class Node():
    
    def __init__(self, value, freq, parent=None, left=None, right=None):
        self.value = value
        self.freq = freq
        self.parent = parent
        self.left = left
        self.right = right
    
    @staticmethod
    def sort_by_freq(node):
        return node.freq

    def __repr__(self):
        res = ""
        res += "\nValue: {}".format(self.value) 
        res += "\nFreq: {}".format(self.freq) 
        res += "\nParent: {}".format(id(self.parent))
        res += "\nLeft value: {}".format(id(self.left))
        res += "\nRignt value: {}".format(id(self.right))
        return res
