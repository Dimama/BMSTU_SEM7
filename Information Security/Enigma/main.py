from enigma import Enigma
from reflector import Reflector
from rotor import Rotor
import sys
from config import ROTORS_COUNT, MAX_LEN
import codecs

def main():
    try:
        file = open(sys.argv[1], "rb")
    except IndexError:
        print("Set file as argv[1]")
        return

    # init rotors
    rotors = []
    for _ in range(ROTORS_COUNT):
        rotors.append(Rotor())

    # set refs to next rotor
    for i in range(ROTORS_COUNT - 1):
        rotors[i].next_rotor = rotors[i+1]
        
    #for i in range(ROTORS_COUNT):
      #  print(id(rotors[i]))
       # print(rotors[i])

    # print(id(None))
    # init Enigma
    
    reflector = Reflector()
    print(reflector)
    byte = reflector.handle_byte(0)
    print(byte)
    print(reflector.handle_byte(byte))

    enigma = Enigma(rotors, Reflector())

    enc_file = open("enc_" + sys.argv[1], "wb")

    while True:
        buf = file.read(MAX_LEN)
        #print(buf)
        if(not len(buf)):
            file.close()
            enc_file.close()
            break
        else:
          #  enc_str = enigma.encryptStr(buf)
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
         #   dec_str = enigma.encryptStr(buf)
            dec_file.write(buf) # decrypt
    
    
if __name__ == "__main__":
    main()