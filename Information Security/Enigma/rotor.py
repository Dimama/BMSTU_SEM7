from config import BYTE_MAX
from random import shuffle


class Rotor:
    def __init__(self):
        self.__arr1 = bytearray(range(BYTE_MAX))
        self.__arr2 = bytearray(range(BYTE_MAX))
        self.__offset = 0 
        self.__rotate_next = False

        shuffle(self.__arr2)

    @property
    def rotate_next(self):
        return self.__rotate_next

    @rotate_next.setter
    def rotate_next(self, value):
        self.__rotate_next = False

    def rotate(self, offset=1):
        self.__offset += offset

        if self.__offset == BYTE_MAX:
            self.__offset = 0
            self.__rotate_next = True
                   
    def reset(self):
        self.__offset = 0

    def handle_byte_straight(self, item):
        pos = self.__arr1.index(item) 
        return self.__arr2[(pos + self.__offset) % (BYTE_MAX)]

    def handle_byte_back(self, item):
        pos = self.__arr2.index(item) - self.__offset
        return self.__arr1[pos]
        
    def __str__(self):
        res = "\nArr1: {0}".format(self.__arr1)
        res += "\nArr2: {0}".format(self.__arr2)
        res += "\nOffset: {0}".format(self.__offset)

        return res
        
