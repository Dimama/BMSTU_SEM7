from reflector import Reflector
from rotor import Rotor
from struct import pack

class Enigma:
    def __init__(self, rotors, reflector):
        self.__rotors = rotors
        self.__reflector = reflector

    def encrypt(self, item):
        res = item
        for rotor in self.__rotors:
            res = rotor.handle_byte_straight(res)

        res = self.__reflector.handle_byte(res)

        rotors_count = len(self.__rotors)
        for rotor in self.__rotors[::-1]:
            res = rotor.handle_byte_back(res)

        self.__rotors[0].rotate()
        for i in range(1, rotors_count):
            if self.__rotors[i-1].rotate_next:
                self.__rotors[i-1].rotate_next = False
                self.__rotors[i].rotate()

        return res

    def encryptStr(self, string):
        res = b""
        for item in string:
            enc_item = self.encrypt(item)
            res += pack("B", enc_item)
        return res

    def reset(self):
        for rotor in self.__rotors:
            rotor.reset()

    def __str__(self):
        res = ""
        for rotor in self.__rotors:
            res += rotor.__str__()

        res += "\n\n" + self.__reflector.__str__()

        return res    