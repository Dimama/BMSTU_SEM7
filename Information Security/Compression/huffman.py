from tree import Node


class Huffman():
    
    def __init__(self, filename):
        self.table = self.make_frequency_table(filename)
        self.tree = self.make_tree()
        #self.code_table = self.make_code_table()

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

    def make_tree(self):
        """
        Построение дерева кодирования
        """
        # создаем список свободных узлов
        nodes = []
        for i in range(len(self.table)):
            nodes.append(Node(i, self.table[i]))

        nodes.sort(key=Node.sort_by_freq)

        #for node in nodes:
        #    print(node)
        leafs = [] # Список узлов нижнего уровня

        # создаем дерево: создаем один узел, объединяя два узла с наименьшими весами, записываем в список
        count = 0
        while len(nodes) > 1:
            count += 1
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
        
        #print("-------------")
        #print(len(nodes))
        #for node in nodes:
            #print(node)

        root = nodes[0] # корень дерева Хаффмана

        # создаем таблицу кодов
        codes = []
    

        for i in range(len(leafs)):
            code = ""
            node =  leafs[i]
            while True:
                parent = node.parent
                if parent == None:
                    break
                if node == parent.left:
                    code += "0"
                if node == parent.right:
                    code += "1"
                node = parent
            codes.append(code[::-1])

        for i in range(len(codes)):
            print("{}: {}".format(i, codes[i]))
            
        return nodes[0]


    def make_code_table():
        """
        Создание таблицы кодов Хаффмана
        """
        pass
        
        
    def compress():
        pass

    def decompress():
        pass