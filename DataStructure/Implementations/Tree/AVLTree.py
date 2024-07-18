class Node:
    def __init__(self, value):
        self.data = value
        self.left, self.right = None, None
        self.balanceFactor = 0
        self.height = 0

class AVLTree:
    def __init__(self):
        self.__root = None
        self.__sz = 0

    def insert(self, val):
        '''
            Function to insert the new value into AVL Tree. This implementation will not allow duplicate value to be present in the AVL Tree.
            This function will return `True` if the value is inserted in Tree else it will return `False`
        '''
        if val == None:
            return False
        
        if self.find(val):
            return False 
        else:
            self.__root = self.__add(self.__root, val)
            self.__sz += 1
            return True
    
    
    def find(self, val):
        '''
            Returns `True` if the given value is present else it will return `False`
        '''
        return self.__contains(self.__root, val)
    
    def __contains(self, root, val):
        '''
            This private method will search the given value in AVL Tree, if the value is not present then it will return `False` else it will return `True` 
        '''
        if root is None:
            return False

        if root.data == val:
            return True
        elif self.__compare(val, root) < 0:
            return self.__contains(root.left, val)
        else:
            return self.__contains(root.right, val)

    def __compare(val, root):
        '''
            Compare function to calculate the value of `val - root.data`
        '''
        return val - root.data
    
    def __rightRotate(self, root):
        '''
            This will right rotate the given node
        '''
        rootChild = root.left
        root.left = rootChild.right
        rootChild.right = root

        # First we have to update the node which is coming below, so we have to update the current node first and then child of root i.e now the parent
        self.__update(root)
        self.__update(rootChild)

        return rootChild

    def __leftLeftCase(self, root):
        '''
            This will deal the left - left case
        ''' 
        return self.__rightRotate(root)
    
    def __leftRotate(self, root):
        '''
            This will left rotate the given node
        '''
        rootChild = root.right
        root.right = rootChild.left
        rootChild.left = root

        # First we have to update the node which is coming below, so we have to update the current node first and then child of root i.e now the parent
        self.__update(root)
        self.__update(rootChild)

        return rootChild
    
    def __rightRightCase(self, root):
        '''
            This will deal the right - right case
        ''' 
        return self.__leftRotate(root)
    
    def __leftRightCase(self, root):
        '''
            This will deal the left - right case
        ''' 
        root.left = self.__leftRotate(root.left)
        return self.__leftLeftCase(root)

    def __rightLeftCase(self, root):
        '''
            This will deal the right - Light case
        ''' 
        root.right = self.__rightRotate(root.right)
        return self.__rightRightCase(root)

    def __balance(self, root):
        '''
            This method will check for unbalance codition for AVL Tree and if the tree is unbalanced then this will balance the tree and return the node after balancing it.
        '''
        # Left Heavy Tree
        if root.balanceFactor == -2:
            # Left-Left Case
            if root.left.balanceFactor < 0:
                return self.__leftLeftCase(root)
            # Left-Right Case
            else:
                return self.__leftRightCase(root)
        
        # Right Heavy Tree
        elif root.balanceFactor == 2:
            # Right-Right Case
            if root.right.balanceFactor > 0:
                return self.__rightRightCase(root)
            # Right-Left Case
            else:
                return self.__rightLeftCase(root)





    def __add(self, root, val):
        '''
            Private Method to add a new node, It will insert the node and it will return the root node of updated tree. 
        '''
        if root == None:
            return Node(val)
        
        cmp = self.__compare(val, root)
    
        if cmp < 0:
            root.left = self.__add(root.left, val)
        else:
            root.right = self.__add(root.right, val)

        # Call update method to update the height of nodes
        self.__update(root)

        # Return the balanced AVL Tree
        return self.__balance(root)


    def __update(root):
        '''
            This will update the heights and balance factor of given node
        '''
        leftHeight, rightHeight = -1, -1

        if root.left is not None:
            leftHeight = root.left.height
        
        if root.right is not None:
            rightHeight = root.right.height
        
        root.height = 1 + max(leftHeight, rightHeight)
        root.balanceFactor = rightHeight - leftHeight
    

if __name__ != "main":
    avl = AVLTree()
    