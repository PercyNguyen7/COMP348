(ns app
  (:require [menu])
  (:require [db2]))

;; Process data, and then pass it to the menu to start
(defn startProg
  []
  (let [raw-data (db/loadData "grades.txt")
        data-vectors (db/vectorizeRawData raw-data)
        data (db/mapifyVectorData data-vectors)
        avgGrdsMap (db/createMap data db/CLASSAVG)
        idMap (db/createMap data db/ID)
        lastNameMap (db/createMap data db/LASTNAME)]

    ;; (println raw-data)      ;;data string
    ;; (println)
    ;; (println data-vectors)  ;; data: lazy sequence of student vectors
    ;; (println)
    ;; (println data)          ;;  processed data as lazy sequence of student vectors containing map for their grade
    ;; (println (str "\n" avgGrdsMap))

    ;; These 2 maps were meant for fast lookup (option 2 & 3) but not used in the final submission in favor of filter()
    ;; (println idMap)
    ;; (println lastNameMap)
    (menu/menu data avgGrdsMap)))

(startProg)


