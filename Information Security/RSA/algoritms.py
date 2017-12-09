import random
from config import MILLER_RABIN_ROUNDS_COUNT

class Algorithms():

    # проверка числа на простоту
    @staticmethod
    def miller_rabin_2(a, s, t, n):
        x = pow(a, t, n)
        if x == 1 or x == n - 1:
            return True
        for _ in range( s - 1 ):
            x = pow(x, 2, n)
            if x == 1:
                return False
            if x == n - 1:
                return True
	
        return False

    
    @staticmethod
    def miller_rabin(n, rounds):
        # Представить n - 1 как 2^s * t
        t = n - 1
        s = 0
        while t % 2 == 0:
            t >>= 1 
            s += 1
        
        for _ in range(rounds):
            a = random.randrange(2, n - 2)

            if not Algorithms.miller_rabin_2(a, s, t, n):
                return False

        return True    

        
    @staticmethod
    def simple_number(bits_count):
        rounds = MILLER_RABIN_ROUNDS_COUNT
        while True:
            num = random.getrandbits(bits_count)
            if num % 2 != 0 and Algorithms.miller_rabin(num, rounds):
                return num

    @staticmethod
    def gcd_euclid(a, b):
        if a < b:
            a, b = b, a
        while b != 0:
            a, b = b, a % b
        return a


    @staticmethod
    # a - phi
    # b - e
    # ax + by = d
    # нужно найти коэффициент при b
    def advanced_euclide(a, b):
        x2, x1, y2, y1 = 1, 0, 0, 1
        while b > 0:
            q = a // b
            r = a - q *b
            
            x = x2 - q * x1
            y = y2 - q * y1
            x2 = x1
            x1 = x
            y2 = y1
            y1 = y

            a = b
            b = r
            
        d = a
        x = x2
        y = y2

        return d, y
        

    @staticmethod
    def find_e_d(phi):
        while True:
            while True:
                # находим e, взаимно простое с phi
                e = random.randrange(phi)
                if e == 0:
                    continue
                if Algorithms.gcd_euclid(e, phi):
                    break
            
            # находим d такое, чтобы (e * d) mod phi = 1
            gcd, d = Algorithms.advanced_euclide(phi, e)
            if gcd == 1:
                break

        if d < 0:
            d = phi + d
        return e, d     