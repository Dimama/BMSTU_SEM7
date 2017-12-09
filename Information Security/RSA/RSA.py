from algoritms import Algorithms
import struct
import sys

class RSA():
    
    def __init__(self, bit_count=512):
        
        self.bit_count = bit_count
        self.e , self.d, self.n = self.generate_keys()
        
    # e - открытый ключ
    # d - закрытый ключ
    # n - модуль
    def generate_keys(self):
        
        p = Algorithms.simple_number(self.bit_count)
        q = Algorithms.simple_number(self.bit_count)
        n = p * q
        phi = (p - 1) * (q - 1) 
        e, d = Algorithms.find_e_d(phi)


        print("p:", p)
        print("q:", q)
        print("n:", n)
        print("phi:", phi)
        print("e:", e)
        print("d:", d)

        print("size n:", sys.getsizeof(n), "bytes")
        print("e*d mod phi:", e*d % phi)
        return e, d, n

    def encrypt(self, filename_read, filename_write):
        
       with open(filename_read, "rb") as fr, open(filename_write, "w") as fw:
               data = fr.read()
               for item in data:
                   new_item = pow(item, self.e, self.n)
                   fw.write(str(new_item) + "\n") 

    def decrypt(self, filename_read, filename_write):
       
        with open(filename_read, "r") as fr, open(filename_write, "wb") as fw:
            
            line = fr.readline()
            while line:
                num = int(line)
                byte = pow(num, self.d, self.n)
                fw.write(struct.pack('B', byte)) 
                line = fr.readline()

