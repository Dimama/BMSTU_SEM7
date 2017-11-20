from enigma import Enigma
import sys
from config import *

def main():
    try:
        file = open(sys.argv[1], "rb")
    except IndexError:
        print("Set file as argv[1]")
        return

    # init Enigma

    enc_file = open("enc_" + sys.argv[1], "wb")


    while True:
        buf = file.read(MAX_LEN)
        if(not len(buf)):
            file.close()
            enc_file.close()
            break
        else:
            enc_file.write(buf) # encrypt

    enc_file = open("enc_" + sys.argv[1], "rb")    
    dec_file = open("dec_" + sys.argv[1], "wb")
    
    while True:
        buf = enc_file.read(MAX_LEN)
        if(not len(buf)):
            enc_file.close()
            dec_file.close()
            break
        else:
            dec_file.write(buf) # decrypt
    
    
if __name__ == "__main__":
    main()