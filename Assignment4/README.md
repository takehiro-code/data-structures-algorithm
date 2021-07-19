# Assignment 4

Template class of Red Black Tree implementation. Since we are implementing a template class, we include the class declaration and its member function definition inside of single header file and outside of its class declaration.


## Files
- RedBlackTree.h (that includes all classes)
- main.cpp (for testing)

## Classes

### NodeT template class 
(should be above RedBlackTree class)

Attributes:
- data: the data contained in the node
- left: pointer that points to left child node
- right: pointer that points to the right child node
- parent: pointer that points the parent node
- isBlack: if true, the node is black. Otherwise, false

### RedBlackTree template class

Attributes:
- root: nodeT pointer that points to the root node
- sz: size of the tree, i.e., number of elements in the tree


