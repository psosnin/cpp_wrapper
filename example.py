from numpy import average
from lib.pyexample import *

#initialise class
myclass = MyClass()

#pass int to class
print(myclass.square(10))

#return vector from class (either use as IntVec or convert to list or np array)
print(list(myclass.returnList()))

#pass vector to class
vect = IntVec()
vect.extend([10, 20, 721, 0])
print(myclass.sum(vect))


#use lib function without class
print(exampleFunction())