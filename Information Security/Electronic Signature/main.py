import rsa
import sys
import os
from Cryptodome.Hash import SHA256

def hash_file(message_file):
    h = SHA256.new()
    with open(message_file, "rb") as f:
        while True:
            buf = f.read(1024)
            if len(buf) == 0:
                break
            h.update(buf)

    #print("Хеш файла: "  + str(h.hexdigest()))
    return h.digest() # возвращаем хеш в виде мссива байтов

# запись электронной подписи в файл
def make_signature(message_file, key):
   
    # считаем хеш файла
    h = hash_file(message_file)

    # шифруем хеш закрытым ключом
    signature = rsa.encrypt(h, key)

    # записываем электронную подпись в файл
    signature_file_name = "signature"
    with open(signature_file_name, "wb") as f:
        f.write(signature)

    print("Электронная подпись сохранена в файле '{0}'".format(signature_file_name))

    return signature_file_name

# проверка электронной подписи
def check_signature(message_file, signature_file ,key):
    # считаем хеш файла с сообщением
    h1 = hash_file(message_file)

    # расшифровываем ЭП
    signature = None
    with open(signature_file, "rb") as f:
        signature = f.read()

    try:
        h2 = rsa.decrypt(signature, key)
    except rsa.pkcs1.DecryptionError:
        return False

    return (h1 == h2)

def main():
    try:
        message_file = sys.argv[1]
    except IndexError:
        print("Задайте файл с сообщением с помощью аргументов командной строки")
        return

    if not os.path.exists(message_file):
        print("Файл не найден!")
        return

    (privkey, pubkey) = rsa.newkeys(2048)
    signature_file = make_signature(message_file, privkey)
    filename = input("Введите имя файла с подписью:")
    is_valid = check_signature(message_file, filename, pubkey)

    if is_valid:
        print("Электронная подпись корректна.")
    else:
        print("Электронная подпись некорректна.")
    

if __name__ == '__main__':
    main()
