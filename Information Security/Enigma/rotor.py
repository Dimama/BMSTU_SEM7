from config import BYTE_MAX
from random import shuffle


class Rotor:
    def __init__(self, next_rotor=None):
        self.__arr1 = bytearray(range(BYTE_MAX))
        self.__arr2 = bytearray(range(BYTE_MAX))
        self.__next_rotor = next_rotor
        self.__offset = 0 

        shuffle(self.__arr2)
    
    @property
    def next_rotor(self):
        return self.__next_rotor

    @next_rotor.setter
    def next_rotor(self, rotor):
        self.__next_rotor = rotor

    @property
    def offset(self):
        return self.__offset

    def rotate(self):
        self.__offset = (self.__offset + 1) % BYTE_MAX 
        
        if self.__offset == BYTE_MAX:
            pass # rotate next

    def reset(self):
        self.__offset = 0
        #self.__arr1 = bytearray(range(BYTE_MAX))

    def handle_byte(self, item):
        pos = self.__arr1.index(item)
        # rotate ? 
        return self.__arr2[(pos +self.__offset) % BYTE_MAX]
        
    def __str__(self):
        res = "\nArr1: {0}".format(self.__arr1)
        res += "\nArr2: {0}".format(self.__arr2)
        res += "\nOffset: {0}".format(self.__offset)
        res += "\nNext rotor: {0}".format(id(self.__next_rotor))

        return res
        