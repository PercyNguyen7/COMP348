(ns menu
  (:require [clojure.string :as str])
  (:require [db]))

;; Print all students ID and Name from the data
(defn listNames
  [data-seq]
  (doseq [x data-seq]
    (println (first x) (second x) (get x 2)))
  (println (str (count data-seq) " student(s) in total")))


;; fn prints the menu and returns a value for read line
(defn showMenu
  []
  (println "\n\n*** Grade Processing Menu ***")
  (println  "-----------------------------")
  (println "1. List Names")
  (println "2. Display Student Record by ID")
  (println "3. Display Student Record by Lastname")
  (println "4. Display Component")
  (println "5. Display Total")
  (println "6. Exit"))

;; Get user response for menu option
(defn getMenuRes []
  (do
    (print "\nEnter an option? ")
    (flush)
    (read-line)))

; Listing all student names and ID in database
(defn option1
  [data] ;parm(s) can be provided here, if needed
  (print "\n1. Listing all Student Names")
  (println  "\n-----------------------------")
  (listNames data))

;; Find a student record with matching ID (case insensitive)
(defn option2
  [data] ;parm(s) can be provided here, if needed 
  (print "\n2. Displaying Student Record by ID")
  (println  "\n-----------------------------")
  (print "\nEnter the Student ID: ")
  (flush)
  
  (let [id-input (read-line)
        parsed-id (read-string id-input)
        res (db/fetchStudentById data parsed-id)]
    ;; METHOD 1: use filter in fetchStudentById
    (if (= (count res) 0)
      (println "Invalid student ID or student ID not found.")
      (println (first res)))
    ))

;; Find all student records with matching last name (case insensitive)
(defn option3
  [data]
  (print "\n3. Display Student Record by Last Name")
  (println  "\n-----------------------------")
  (print "\nEnter the student's Last Name: ")
  (flush)
  (let [lname-input (read-line)
        res (db/fetchStudentByLastName data lname-input)]
    (if (= (count res) 0)
      (println "Student last name not found in database")
      (doseq [student res]
        (println student)))))

; Find all student's grades for a given component (a1, a2, midterm, final, total)
(defn option4
  [data, avgGrdsMap]
  (print "\n4. Displaying Student Grade by Component")
  (println  "\n-----------------------------")
  (print "\nEnter the component: ")
  (flush)
  (let [component-input (read-line)]
    (if (contains? (nth (nth data 0) 3) (str/upper-case component-input))
      (do
        (doseq [student data]
          (let [grade-map (nth student 3)
                grade-component (get grade-map (str/upper-case component-input))
                grade-comp-grd-value  (get grade-component :grade)
                stud-id (nth student 0)]

            (println (str  stud-id " " (db/roundToOneDeci grade-comp-grd-value)))))
        (println (str "Average: "  (db/roundToOneDeci (get avgGrdsMap (str/upper-case component-input))))))
      (println "Grade component does not exist "))))

;; Feature 5: Display all Grade Components
(defn option5
  [data avgMap]
  (print "\n5. Displaying All Student Grade Components and their Total Average")
  (println  "\n-----------------------------------------------------------")
  (println "  STUDID  |   A1    |   A2    | MIDTERM |  FINAL  |  TOTAL  |")
  (println "-----------------------------------------------------------")
  (doseq [student data]
    (let [gradeMap (nth student 3)]
      (println (str (first student) "  |  " (db/numToDisplay (get-in gradeMap ["A1" :grade])) "  |  " (db/numToDisplay (get-in gradeMap ["A2" :grade])) "  |  " (db/numToDisplay (get-in gradeMap ["MIDTERM" :grade])) "  |  " (db/numToDisplay (get-in gradeMap ["FINAL" :grade])) "  |  " (db/numToDisplay (get-in gradeMap ["TOTAL" :grade])) "  |"))))
  (println  "-----------------------------------------------------------")
  (println (str "CLASS AVG |  " (db/numToDisplay (get avgMap "A1")) "  |  " (db/numToDisplay (get avgMap "A2")) "  |  " (db/numToDisplay (get avgMap "MIDTERM")) "  |  " (db/numToDisplay (get avgMap "FINAL")) "  |  " (db/numToDisplay (get avgMap "TOTAL")) "  |")))


; If the menu selection is valid, call the relevant function to 
; process the selection
(defn processOption
  [option data avgGrdsMap] ; other parm(s) can be provided here, if needed
  (if (= option "1") (option1 data)
      (if (= option "2") (option2 data)
          (if (= option "3") (option3 data)  ; other args(s) can be passed here, if needed
              (if (= option "4") (option4 data avgGrdsMap)   ; other args(s) can be passed here, if needed
                  (if (= option "5") (option5 data avgGrdsMap)
                      (println "Invalid Option, please try again")))))))


; Display the menu and get a menu item selection. 
(defn menu
  [data, avgGrdsMap] 
  (showMenu)
  (let [option (str/trim (getMenuRes))]
    (if (= option "6")
      (println "\nGood Bye\n")
      (do
        (processOption option data avgGrdsMap)
        (recur data avgGrdsMap)))))  
