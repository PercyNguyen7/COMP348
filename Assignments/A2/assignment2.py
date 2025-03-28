# Please run the program by the command line: python3 main.py <...path>
from operator import truediv


class Diagram:
    def __init__(self, filename, width, height):
        self.filename = filename
        self._width = width
        self._height = height
        self._dimension = height * width
        self.objects = []
        self.objects_type = set()
        self.objects_count = 0
        self.objects_truncated_count = 0
        self.objects_difficult_count = 0

    @property
    def width(self):
        return self._width

    @property
    def height(self):
        return self._height

    @property
    def dimension(self):
        return self._dimension

    def add_obj(self, diagram_obj):
        self.objects.append(diagram_obj)
        self.objects_type.add(diagram_obj.name)
        self.objects_count += 1

    def __str__(self):
        diagram_att = f"""
    DIAGRAM INFOS----------------------------------
    Name: {self.filename}
    Height: {self.height}
    Width: {self.width}
    Dimension: {self.dimension}
    Objects Count: {self.objects_count}
    Objects Truncated Count: {self.objects_truncated_count}
    Objects Difficult Count: {self.objects_difficult_count}
    DIAGRAM OBJECTS INFOS---------------------------
    """
        objs_info = "\n    ".join(str(obj) for obj in self.objects)
        return diagram_att + objs_info

class DiagramObject:
    def __init__(self, name,truncated, difficult, xmin, ymin, xmax, ymax):
        self.name = name
        self.bndbox = (xmin, ymin, xmax,ymax)
        self._height = ymax-ymin
        self._width = xmax - xmin
        self._area = self._width * self._height
        self.truncated = truncated
        self.difficult = difficult

    @property
    def width(self):
        return self._width

    @property
    def height(self):
        return self._height

    @property
    def area(self):
        return self._area

    def __eq__(self, other):
        if isinstance(other, DiagramObject):
            return self.name == other.name and self.bndbox == self.bndbox and self.truncated == other.truncated and self.difficult == other.difficult
        return False

    def __str__(self):
        return f"Object Type: {self.name}, BoundBox: (xmin: {self.bndbox[0]},ymin: {self.bndbox[1]},xmax: {self.bndbox[2]},ymax: {self.bndbox[3]}), Width: {self._width}, Height: {self._height}, Area: {self._area}  Truncated: {self.truncated}, Difficult: {self.difficult}"

# function that get all arguments via argument parser module and return it
def get_args():
    parser = argparse.ArgumentParser(
        description="Please provide the path to the folder that contains xml files."
    )
    parser.add_argument(
        "dir_path", metavar="path", help="The path to your xml files."
    )
    args = parser.parse_args()
    return args

#MENU: function prints menu instructions
def display_menu():
    print("""
    1. List Current Files
    2. List Loaded Diagrams
    3. Load File
    4. Display Diagram Info
    5. Search Diagram
        5.1. Find by object type
        5.2. Find by diagram dimension
    6. Statistics
    7. Exit
""")

#MENU: function asks for user choice of feature
def get_response():
    while True:
        res = input("Please input an integer between 1 and 7: ")
        try:
            res = int(res)
            if 1 <= res <= 7:
                return res
            else:
                print(f"{res} is out of range. Please input an integer between 1 and 7: ")
        except ValueError:
            print(f"'{res}' is not a valid number. Please input a valid integer: ")

#FEATURE 1: function lists all files ending with xml
def list_curr_files():
    print("------1. LISTING CURRENT FILES----------\n")
    for file in glob.glob("*.xml"):
        print(file)
    print("\n----------------------------------------")

#FEATURE 2: function prints all diagrams instances inside of the diagram dictionary
def list_diagrams(diagram_dict):
    print("------2. LISTING LOADED DIAGRAMS-----------\n")
    diagram_num = len(diagram_dict)
    if diagram_num == 0:
        print("0 diagram loaded. Please load a diagram first.")
    else:
        all_diagram_name_str = ""
        for i, key in enumerate(diagram_dict):
            all_diagram_name_str += f"'{key}'"
            if i != len(diagram_dict) - 1:
                all_diagram_name_str += f", "
        print(f"{diagram_num} diagram(s) loaded: {all_diagram_name_str}")

    print("\n----------------------------------------")

#FEATURE 3 HELPER: function checks if current directory contains xml files or not
def dir_has_xml():
    xml_files = glob.glob("*.xml")
    if not xml_files:
        return False
    else:
        return True

#FEATURE 3 HELPER: function checks if the input xml tags exist or not
def xml_tags_valid(tag_tuple):
    for tag in tag_tuple:
        if tag is None:
            return False
    return True

#FEATURE 3 HELPER: function updates the stats for the current diagram
def update_stats_obj(stats_dict, new_obj):
    stats_dict["all_obj_type_set"].add(new_obj.name)
    stats_dict["total_obj"] += 1
    if stats_dict["min_obj_area"] is None or new_obj.area < stats_dict["min_obj_area"]:
        stats_dict["min_obj_area"] = new_obj.area
    if stats_dict["max_obj_area"] is None or new_obj.area > stats_dict["max_obj_area"]:
        stats_dict["max_obj_area"] = new_obj.area

#FEATURE 3 HELPER: function updates the stats for the current diagram object
def update_stats_diagram(stats_dict, new_diagram):
    stats_dict["total_diagram"] += 1
    if stats_dict["min_dia_dim"] is None or new_diagram.dimension < stats_dict["min_dia_dim"]:
        stats_dict["min_dia_dim"] = new_diagram.dimension
    if stats_dict["max_dia_dim"] is None or new_diagram.dimension > stats_dict["max_dia_dim"]:
        stats_dict["max_dia_dim"] = new_diagram.dimension

#FEATURE 3: function reads XML file, make new instances of diagrams and diagram objects within them, then update the diagram dictionary and stats_dict
def load_file(diagram_dict,stats_dict):
    print("------------ 3. LOADING FILE ---------------\n")
    if not dir_has_xml():
        print("No XML files found in the current directory to be loaded.")
        print("\n----------------------------------------")
        return
    input_filename = ""
    try:
        diagram_num = len(diagram_dict)
        if diagram_num == 0:
            print("0 diagram loaded.")
        else:
            all_diagram_name_str = ""
            for i, key in enumerate(diagram_dict):
                all_diagram_name_str += f"'{key}'"
                if i != len(diagram_dict) - 1:
                    all_diagram_name_str += f", "
            print(f"{diagram_num} diagram(s) already loaded: {all_diagram_name_str}")


        input_filename = input("Enter the filename (w/o file extension) to load: ")
        if input_filename in diagram_dict:
            print("Diagram is already loaded and cannot be loaded again.")
            print("\n----------------------------------------")
            return

        tree = ET.parse(input_filename +".xml")
        root_tag = tree.getroot()
        width_tag = root_tag.find('./size/width')
        height_tag = root_tag.find('./size/height')
        objects_tags = root_tag.findall('object')

        # verify if all sub_tags are valid
        if not xml_tags_valid((root_tag, width_tag, height_tag, objects_tags)):
            print("Invalid XML. XML must have the following tags: root, width, height and object(s).")
            print("\n----------------------------------------")
            return
        width = int(width_tag.text)
        height = int(height_tag.text)
        new_diagram = Diagram(input_filename,width,height)

        #PROCESSING OBJECTS
        for obj in objects_tags:
            name_tag = obj.find('name')
            truncated_tag = obj.find('truncated')
            difficult_tag = obj.find('difficult')
            xmin_tag = obj.find('./bndbox/xmin')
            ymin_tag = obj.find('./bndbox/ymin')
            xmax_tag = obj.find('./bndbox/xmax')
            ymax_tag = obj.find('./bndbox/ymax')

            #verify if all sub tags are valid, if not then we just dont add em
            obj_sub_tags = (name_tag,truncated_tag,difficult_tag,xmin_tag,xmax_tag,ymin_tag,ymax_tag)
            if not xml_tags_valid(obj_sub_tags):
                print("Invalid XML. XML objects must have the following tags: name, truncated, difficult, xmin, xmax, ymin, ymax.")
                print("\n----------------------------------------")
                break

            truncated = int(truncated_tag.text)
            if not truncated == 0:
                new_diagram.objects_truncated_count += 1

            difficult = int(difficult_tag.text)
            if not difficult == 0:
                new_diagram.objects_difficult_count += 1

            xmin = int(xmin_tag.text)
            ymin = int(ymin_tag.text)
            xmax = int(xmax_tag.text)
            ymax = int(ymax_tag.text)

            new_obj = DiagramObject(name_tag.text,truncated,difficult,xmin,ymin,xmax,ymax)
            new_diagram.add_obj(new_obj)
            update_stats_obj(stats_dict, new_obj)
        update_stats_diagram(stats_dict, new_diagram)
        diagram_dict[input_filename] = new_diagram
        print(f"Loaded file '{input_filename}' successfully!")
        print("\n----------------------------------------")
    except FileNotFoundError:
        print(f"{input_filename}.xml file cannot be found. Load file failed.")
        print("\n----------------------------------------")
    except ValueError:
        print(f"One of the tag's value is not a valid integer.")

#FEATURE 4: function prints all attributes of the diagram and its objects
def display_diagram_info(diagram_dict):
    print("---------- 4.DISPLAY DIAGRAM INFO -------------\n")
    diagram_num = len(diagram_dict)
    all_diagram_name_str = ""
    if diagram_num == 0:
        print("0 diagram loaded. Please load a diagram first.")
    else:
        for i, key in enumerate(diagram_dict):
            all_diagram_name_str += f"'{key}'"
            if i != len(diagram_dict) - 1:
                all_diagram_name_str += f", "
        print(f"{diagram_num} diagram(s) loaded: {all_diagram_name_str}")
        input_filename = input("Insert your diagram name: ")

        if diagram_dict.get(input_filename) is not None:
            print(f"Printing diagram {diagram_dict.get(input_filename)}")
        else:
            print("Loaded diagram not found.")
    print("\n--------------------------------------------")

#FEATURE 5.1: function asks for an object type, then print the name of any diagram that contains at least 1 object of the given type
def search_by_type(diagram_dict):
    print("---------- 5.1 SEARCH BY TYPE ---------------\n")
    result = ""
    input_obj_type = input("    Please insert the object type: ")
    for diagram in diagram_dict.values():
        if  input_obj_type in diagram.objects_type:
            result += f"\n    {diagram.filename}"
    if not result == "":
        print(f"""
    Found diagram(s):{result}
""")
    else:
        print(f"""
    No diagram found that contains object type '{input_obj_type}'
    """)
    print("\n----------------------------------------")

#FEATURE 5.2: function asks for dimension input requirement and return them
def get_search_input_dimension(dim_type):
    while True:
        type_msg = None
        match dim_type:
            case "minw":
                type_msg = "Min width (enter blank for zero)"
            case "minh":
                type_msg = "Min height (enter blank for max)"
            case "maxw":
                type_msg = "Max width (enter blank for zero)"
            case "maxh":
                type_msg = "Max height (enter blank for max)"

        input_dim = input(f"{type_msg} : ")
        if input_dim == "":
            if dim_type == "minw" or dim_type == "minh":
                return 0
            elif dim_type == "maxw" or dim_type == "maxh":
                return sys.maxsize
        else:
            try:
                input_dim = int(input_dim)
                if input_dim >= 0:
                    return input_dim
                else:
                    print("Integer input must be at least 0")

            except ValueError:
                print(f"'{input_dim}' is not a valid integer. Please input a valid integer equal or bigger to 0: ")

#FEATURE 5.2: function asks for object_visibility input requirement (difficult, truncated,
def get_search_input_visibility(visi_type):
    while True:
        type_msg = None
        match visi_type:
            case "truncated":
                type_msg = "Truncated "
            case "difficult":
                type_msg = "Difficult "

        input_visi = input(f"{type_msg} (yes/no/all): ")
        if input_visi.lower() == "yes" or input_visi.lower() == "y":
            return "yes"
        elif input_visi.lower() == "no" or input_visi.lower() == "n":
            return "no"
        elif input_visi == "" or input_visi.lower() == "all" or input_visi.lower() == "a":
            return "all"
        else:
            print(f"'{input_visi}' is not valid. Please input either yes (y), no (n), or all (a)")

#FEATURE 5.2: function searches input_dimension, then prints the name of any diagram match all input for requirements
def search_by_dimension(diagram_dict):
    print("\n---------- 5.2 SEARCH BY DIMENSION -------------\n")
    input_minwidth = get_search_input_dimension("minw")
    input_maxwidth = get_search_input_dimension("maxw")
    input_minheight = get_search_input_dimension("minh")
    input_maxheight = get_search_input_dimension("maxh")
    input_difficult = get_search_input_visibility("difficult")
    input_truncated = get_search_input_visibility("truncated")
    diagrams_found = []

    # bndbox: xmin, ymin, maxw,ymax
    for key, diagram in diagram_dict.items():
        correct_size = False
        correct_difficult = False
        correct_truncated = False

        # check if every diagram object's size fits within the specified range
        if input_minwidth <= diagram.width <= input_maxwidth and input_minheight <= diagram.height <= input_maxheight:
            correct_size = True
        # if one object doesn't fit then we reject the diagram
        else:
            correct_size = False
            break

        # check if truncation condition is met
        # if input is yes, it only searches for diagrams that contain only truncated objects
        # if input is no, it only searches for diagrams that does NOT contain any truncated objects
        if (input_truncated == "yes" and diagram.objects_truncated_count >= 1) or \
                (input_truncated == "no" and diagram.objects_truncated_count == 0) or \
                (input_truncated == "all"):
            correct_truncated = True

        # check if difficulty condition is met
        # if input is yes, it only searches for diagrams that contain only difficult objects
        # if input is no, it only searches for diagrams that does NOT contain any difficult objects
        if (input_difficult == "yes" and diagram.objects_difficult_count >= 1) or \
                (input_difficult == "no" and diagram.objects_difficult_count == 0) or \
                (input_difficult == "all"):
            correct_difficult = True

        # only append the key (diagram name) to the diagram_found set if all requirements are met
        if correct_size and correct_difficult and correct_truncated:
            diagrams_found.append(key)

    if len(diagrams_found) == 0:
        print("\nNo diagram match found.")
    else:
        msg = "Diagrams names that match your requirements: "
        for i, key in enumerate(diagrams_found):
            msg += f"'{key}'"
            if i != len(diagrams_found) -1:
                msg += f", "
        print(msg)
    print("\n-------------------------------")

#FEATURE 5: functions open up a submenu for 5.1 Search by object type or 5.2 Search by dimension
def search_diagram(diagram_dict):
    print("-------------- 5.SEARCH ---------------\n")
    if len(diagram_dict) == 0:
        print(" No diagram loaded to search for.")
        print("\n-------------------------------")
        return
    while True:
        res = input("""    1. Search by Type
    2. Search by Dimension 
    Please input 1 or 2: """)
        try:
            res = int(res)
            if res == 1:
                search_by_type(diagram_dict)
                return
            elif res == 2:
                search_by_dimension(diagram_dict)
                return
            else:
                print(f"""{res} is out of range. Please input 1 or 2.""")
        except ValueError:
            print(f"'{res}' is not a valid number. Please input a valid integer: ")

#FEATURE 6: display some statistics from the stats dictionary we created and have been updating since the beginning
def display_stats(stats_dict):
    print("----------- 6.STATISTICS -------------\n")
    total_obj_type_str = "" # string to display all object type
    if len(stats_dict["all_obj_type_set"]) == 0:
        total_obj_type_str = None
    else:
        for i, obj_type in enumerate(stats_dict["all_obj_type_set"]):
            total_obj_type_str += f"'{obj_type}'"
            if i != len(stats_dict["all_obj_type_set"]) - 1:
                total_obj_type_str += f", "
    print(f"Number of loaded diagrams: {stats_dict["total_diagram"]} diagrams")
    print(f"Total number of total objects: {stats_dict["total_obj"]} objects")
    print(f"Diagram Object Types: {total_obj_type_str}")
    print(f"Minimum Diagram Dimension is: {stats_dict["min_dia_dim"]}")
    print(f"Maximum Diagram Dimension is: {stats_dict["max_dia_dim"]}")
    print(f"Minimum Object Area is: {stats_dict["min_obj_area"]}")
    print(f"Maximum Object Area is: {stats_dict["max_obj_area"]}")
    print("\n--------------------------------------")

# FEATURE 7 HELPER: function confirms user's wishes to quit
def get_quit_confirmation():
    while True:
        res = input("Are you sure you want to quit? (yes,no) : ")
        if res.lower() == "y" or res.lower() == "yes":
            return True
        elif res.lower() == "n" or res.lower() == 'no':
            return False
        else:
            print("Invalid input. Please input a valid answer (yes,no) ")

# function matches the response to the right feature. if res is 7, return 0 to exit the program
def handle_res(res, diagram_dict, stats_dict):
    match res:
        case 1:
            list_curr_files()
        case 2:
            list_diagrams(diagram_dict)
        case 3:
            load_file(diagram_dict, stats_dict)
        case 4:
            display_diagram_info(diagram_dict)
        case 5:
            search_diagram(diagram_dict)
        case 6:
            display_stats(stats_dict)
        case 7:
            if get_quit_confirmation():
                return 0

#function starts the program in main with the input arguments provided
def start_prog(args):
    change_dir(args.dir_path)
    diagram_dict = {}
    stats_dict = {
        "total_diagram": 0,
        "total_obj": 0,
        "all_obj_type_set": set(),
        "min_dia_dim": None,
        "max_dia_dim": None,
        "min_obj_area": None,
        "max_obj_area": None
    }
    while True:
        display_menu()
        res = get_response()
        if handle_res(res, diagram_dict, stats_dict) == 0:
            print("Exiting the program. See you next time!")
            break

#PRE-PROG: function changes the current directory and catch any error
def change_dir(dir_path):
    try:
        os.chdir(dir_path)
    except FileNotFoundError:
        print("""
        File cannot be located!
        Permission to directory is not granted.
        Closing program.""")
    except PermissionError:
        print("""
        Permission to directory is not granted.
        Closing program.
        """)

def main():
    arguments = get_args()
    start_prog(arguments)

if __name__ == '__main__':
    import sys
    import argparse
    import os
    import glob
    import xml.etree.ElementTree as ET
    main()

