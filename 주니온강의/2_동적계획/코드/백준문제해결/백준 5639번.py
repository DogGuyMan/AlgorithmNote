import sys
sys.setrecursionlimit(10**6)

class BSTnode :
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BST : 
    def __init__(self):
        self.root = None
    
    def mInsert(self,node, key):
        if(self.root == None) :
            self.root = BSTnode(key)
        if(node == None):
            node = BSTnode(key)
        elif(node.key > key) :
            node.left = self.mInsert(node.left, key)
        elif(node.key < key) :
            node.right = self.mInsert(node.right, key)
        return node

    def mPostorder(self, node) :
        if(node == None) :
            return
        else :
            self.mPostorder(node.left)
            self.mPostorder(node.right)
            print(node.key)

L = list()
while True:
    try:
        L.append(int(input()))
    except:
        break

BSTtree = BST()
for E in L :
    BSTtree.mInsert(BSTtree.root,E)

BSTtree.mPostorder(BSTtree.root)