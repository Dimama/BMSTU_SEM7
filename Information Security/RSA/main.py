import sys
from RSA import RSA


def main():
    try:
        filename = sys.argv[1]
    except IndexError:
        print("Set file as argv[1]")
        return

    enc_filename = "enc_" + filename
    dec_filename = "dec_" + filename 

    rsa = RSA(512)

    print("Start encrypting '{0}' ...".format(filename))
    rsa.encrypt(filename, enc_filename)
    print("Encrypting done. Results saved in file: '{0}'".format(enc_filename))
    print("Start decrypting '{0}' ...".format(enc_filename))
    rsa.decrypt(enc_filename, dec_filename)
    print("Decrypting done. Results saved in file: '{0}'".format(dec_filename))


if __name__ == "__main__":
    main()