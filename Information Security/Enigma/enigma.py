from reflector import Reflector
from rotor import Rotor

class Enigma:
    def __init__(self, rotors, reflector):
        self.rotors = rotors
        self.reflector = reflector


    def encrypt(self, item):
        pass


    def encryptStr(self, string):
        res = ""
        for item in string:
            res += self.encrypt(item)
        return res



    