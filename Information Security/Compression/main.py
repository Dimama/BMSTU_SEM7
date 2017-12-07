import sys
import os
from huffman import Huffman


def main():
    try:
        filename = sys.argv[1]
    except IndexError:
        print("Задайте файл с помощью аргументов командной строки")
        return

    if not os.path.exists(filename):
        print("Файл не найден!")
        return
    
    print("Исходный файл: '{}' ({} байт)".format(filename, os.path.getsize(filename)))
    
    huf = Huffman(filename)
    codes_filename, res_filename, zeroes = huf.compress(filename)
    print("Сжатый файл: '{}'  ({} байт)".format(res_filename,  os.path.getsize(res_filename)))
    print("Размер таблицы кодов: {} байт".format(sys.getsizeof(huf.codes_table)))
    print("Нулей дописано в последний байт:", zeroes)

    dec_filename = huf.decompress(filename, res_filename, zeroes)
    print("Восстановленный файл: '{}'  ({} байт)".format(dec_filename,  os.path.getsize(dec_filename)))

if __name__ == '__main__':
    main()
    