(ns db
  (:require [clojure.string :as str])
  (:require [clojure.math :as math]))

;; Enum-like values for createMap function
(def ^:const ID :id)
(def ^:const LASTNAME :lastName)
(def ^:const CLASSAVG :classAvg)

;; Returns string read from a given file
(defn loadData
  [path]
  (slurp path))

;; Rounds a number up to 1 decimal place
(defn roundToOneDeci
  [num]
  (float (/ (math/round (* 10 num)) 10)))

;; Adds extra space before and after num for displaying, depending on the length of num string 
(defn prettifyNum
  [num]
  (if (= (count (str num)) 1)
   (str "  " num "  ")
   (if (= (count (str num)) 2)
     (str "  " num " ")
     (if (= (count (str num)) 3)
       (str " " num " ")
       (if (or (= (count (str num)) 4) (= (count (str num)) 5))
         (str " " num ))))))

;; Convert all double with .0 to an integer for display
(defn numToDisplay [num]
  (if (not= num (math/floor num))
    (prettifyNum num)
    (prettifyNum (int (math/round num)))))

;; Return a sequence of student vectors with the right ID
(defn fetchStudentById [data, targetId]
  (filter (fn [student] (= (first student) targetId)) data))

;; Return a sequence of student with the targetLastName
(defn fetchStudentByLastName [data, targetLName]
  (filter (fn [student] (= (str/lower-case (nth student 2)) (str/lower-case targetLName))) data))

;; Return the averages in a vector of form [a1,a2,midterm,final,total]
(defn calcClassAvgs [data]
  (let [studNum (count data)]
    ;; Using reduce to accumulate the sums for each grade category
    (let [result (reduce
                  (fn [acc student]
                    (let [grdMap (nth student 3)
                          currA1 (get-in grdMap ["A1" :grade])
                          currA2 (get-in grdMap ["A2" :grade])
                          currMidterm (get-in grdMap ["MIDTERM" :grade])
                          currFinal (get-in grdMap ["FINAL" :grade])
                          currTotal (get-in grdMap ["TOTAL" :grade])]

                      [(+ (first acc) currA1)  ;; sumA1
                       (+ (second acc) currA2) ;; sumA2
                       (+ (nth acc 2) currMidterm) ;; sumMidterm
                       (+ (nth acc 3) currFinal) ;; sumFinal
                       (+ (nth acc 4) currTotal)])) ;; sumTotal
                  [0 0 0 0 0]  ;; Initial accumulator values for sums
                  data)] ;; Data to reduce over 
      ;; #(...) is an anonymous function that takes in one argument
      (mapv #(roundToOneDeci (/ % studNum)) result))))

;; Create a map depending on given type (CLASSAVG, ID, LASTNAME)
(defn createMap [data, type]
  (let [counter (atom -1)]  ;; Counter starts at -1
    (if (= type CLASSAVG)
      (let [class-avgs (calcClassAvgs data)
            class-avgs-map {"A1" (first class-avgs) "A2" (second class-avgs) "MIDTERM" (nth class-avgs 2) "FINAL" (nth class-avgs 3) "TOTAL" (nth class-avgs 4)}]
        class-avgs-map)
      (if (= type ID)
        ;; Store students ID as key and their respective index as value
        (reduce (fn [idMap vector]
                  (swap! counter inc)  
                  (assoc idMap (first vector) @counter))  ;; use first vector element as the key (ID)
                {}  
                data)
        (if (= type LASTNAME)
          ;; Store student last names as keys and their index/indices in a vector as value
          (reduce (fn [lastNameMap vector]
                    (swap! counter inc)  
                    (let [lastName (str/lower-case (nth vector 2))]  
                      (if (contains? lastNameMap lastName)
                        (assoc lastNameMap lastName (conj (get lastNameMap lastName) @counter))  ;; Add current index to last name's key vector
                        (assoc lastNameMap lastName [@counter])))) ;; If last name doesn't exist, create a new vector with the current index
                  {}  
                  data)))))) ;; Input data

;; vectorizeRawData turns each data string line into an individual vector
(defn vectorizeRawData
  [raw-data]
  (let [lines-data (str/split-lines raw-data)]
    (map (fn [line]
           (let [parsed-line (str/split line #",")]
          
             [(Integer. (first parsed-line)) ; ID as Integer
              (nth parsed-line 1)             ; First name
              (nth parsed-line 2)             ; Last name
              (nth parsed-line 3)             ; A1 
              (Double. (nth parsed-line 4))  ; weight
              (Double. (nth parsed-line 5))   ; grade
              (nth parsed-line 6)             ; A2 
              (Double. (nth parsed-line 7))  ; weight
              (Double. (nth parsed-line 8))  ; grade
              (nth parsed-line 9)             ; MIDTERM 
              (Double. (nth parsed-line 10)) ; weight
              (Double. (nth parsed-line 11))  ; grade 
              (nth parsed-line 12)            ; FINAL as String
              (Double. (nth parsed-line 13)) ; weight
              (Double. (nth parsed-line 14))  ; grade 
              ]))
         lines-data)))

;; Returns a new map for a student's grade components (A1,A2,MIDTERM,FINAL). 
;; [grades]: vector must have the structure [id fname lname a1 wgt grd a2 wg grd midterm wgt grd final wgt grd]
(defn mapify
  ([grades] (mapify grades {}))
  ([grades gmap]
   (if (< (count grades) 3)
     gmap
     (do
       (def res (assoc gmap (first grades) {:weight (nth grades 1), :grade (nth grades 2)}))
       (recur (drop 3 grades) res))))) ; call the mapify function from 2nd arity with argument [grades gmap](drop 3 grades) and res (the new gmap)

;; calcTotal calculates the total average of grade components of the student vector
(defn calcTotalAvg [student]
  (+ (* (nth student 5) (/ (nth student 4) 100)) (* (nth student 8) (/ (nth student 7) 100)) (* (nth student 11) (/ (nth student 10) 100)) (* (nth student 14) (/ (nth student 13) 100))))

;; mapData creates a new student vector with all the info and the grade component as a map
(defn mapifyVectorData
  [data]
  (map (fn [v]
         (let [grade-map (mapify (drop 3 v))
               total-component-map  {:grade (roundToOneDeci (calcTotalAvg v))}
               updated-grade-map (assoc grade-map "TOTAL" total-component-map )]
           (vector (nth v 0) (nth v 1) (nth v 2) updated-grade-map )))
       data))


