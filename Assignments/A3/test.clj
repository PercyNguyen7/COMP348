(ns test)

(def x 10)

(defn outer []
  (let  [
         y 5]
  (fn inner [] (println (* x 2))) 
    ))

(def myFunc (outer)) ;; myFunc is a reference to inner
                     
(myFunc) ;; executing myFunc, which remembers x (3) and print 6

