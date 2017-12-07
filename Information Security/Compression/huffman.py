from tree import Node
import struct
import sys

class Huffman():
    
    def __init__(self, filename):
        self.table = self.make_frequency_table(filename)
        self.codes_table = self.make_codes_table()

    def make_frequency_table(self, filename):
        """
        Создание таблицы частот
        Индекс в списке table - код символа по ASCII
        """
        table = [0] * 256
        with open(filename, "rb") as f:
            while True:
                s = f.read(1024)
                if not len(s):
                    break
                else:
                    for item in s:
                        table[item] += 1
        return table                    

    def make_codes_table(self):
        """
        Построение таблицы кодов
        """
        # создаем список свободных узлов
        nodes = []
        for i in range(len(self.table)):
            if self.table[i] > 0:
                nodes.append(Node(i, self.table[i]))

        leafs = [] # Список узлов нижнего уровня
        codes = [] # Таблица кодов
    
        # создаем дерево: создаем один узел, объединяя два узла с наименьшими весами, записываем в список
        
        if len(nodes) == 1:
            leafs.append(nodes[0])
            codes.append((nodes[0].value, "0"))
            return codes

        while len(nodes) > 1:
            nodes.sort(key=Node.sort_by_freq) # сортируем узлы по весам
            left, right = nodes.pop(0), nodes.pop(0)   # выбираем два узла с наименьшими весами
            new_node = Node(None, left.freq + right.freq, None, left, right) # создаем новый узел
            left.parent = new_node 
            right.parent = new_node

            # добавляем узлы нижнего уровня в новый список
            if(left.value != None):
                leafs.append(left)

            if(right.value != None):
                leafs.append(right)
            
            nodes.append(new_node) # добавляем новый узел в список
        
        # создаем таблицу кодов
        # добавляем только коды символов, содержащихся в сжимаемом файле
        for leaf in leafs:
            code = ""
            node =  leaf
            # проход по дереву до корня
            while True:
                parent = node.parent
                if parent == None:
                    break
                if node == parent.left:
                    code += "0"
                if node == parent.right:
                    code += "1"
                node = parent
            codes.append((leaf.value, code[::-1])) # добавляем в таблицу кортеж (символ, код)
            
        return codes

    def bit_str_to_byte(self, s):
        return struct.pack('B', int(s, 2)) 

    def find_code(self, num):
        for i in range(len(self.codes_table)):
            if self.codes_table[i][0] == num:
                return self.codes_table[i][1]

        raise "Incorrect code table!"

    def find_byte(self, code):
        for i in range(len(self.codes_table)):
            if self.codes_table[i][1] == code:
                return self.codes_table[i][0]

        return None    

    def compress(self, filename):
        """
        Cжатия файла filname
        return:
        имя файла с таблицей кодов
        имя сжатого файла
        кол-во дописанных в байт нулей
        """
        codes_filename = "codes.txt"

        # создание файла с кодами
        with open(codes_filename, "w") as codes_f:
            for item in self.codes_table:
                codes_f.write("{} {}\n".format(item[0], item[1]))

        # сжатие
        zeroes = 0
        res_filename = "compressed_" + filename
        with open(filename, "rb")  as f, open(res_filename, "wb") as res_f:
            code_str = ""
            while True:
                s = f.read(1024)
                if not len(s):
                    break
                else:
                    for item in s:
                        code = self.find_code(item)
                        code_str += code
                        if len(code_str) >= 8:
                            byte_str = code_str[:8]
                            code_str = code_str[8:]
                            byte = self.bit_str_to_byte(byte_str)
                            res_f.write(byte)

            # дописать биты, если размер кода не кратен 8  
            if len(code_str) > 0:
                zeroes = 8 - len(code_str)
                for i in range(zeroes):
                    code_str += '0'
                byte = self.bit_str_to_byte(code_str)
                res_f.write(byte)

        return codes_filename, res_filename, zeroes

    def split_on_bytes(self, code_str, zeroes, file):
        pass

    def decompress(self, filename, compressed_filename, zeroes):
        """
        Восстановление исходного файла из сжатого
        """
        res_filename = "decompressed_" + filename
        with open(compressed_filename, "rb") as f, open(res_filename, "wb") as res_f:
            code_str = ""
            while True:
                s = f.read(1024)
                if not len(s):
                    break
                else:
                    for byte in s:
                        code = bin(byte)[2:].zfill(8)
                        code_str += code

            if zeroes:
                code_str = code_str[:-zeroes]

            code = ""
            while len(code_str):
                code += code_str[0]
                code_str = code_str[1:]
                byte = self.find_byte(code)
                if byte != None:
                    res_f.write(struct.pack('B', byte))
                    code = ""
      
        return res_filename