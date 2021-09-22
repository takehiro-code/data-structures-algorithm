# Data Structures and Algorithm

To compress the files with zip command,

`zip archivename.zip filename1 filename2 filename3`

To unzip the files to a newly created folder,

`unzip archivename.zip -d foldername` 

## Development environment

- Visual Studio 2019 Community Version
- Visual Studio 2019 Linux Development Environment add-on
- Ubuntu 18.04 Windows Subsystem Linux (WSL)
- g++ compiler with C++11 standard on WSL
- Valgrind
- Text editing with Visual Studio Code (Occasionally)

## Development Setup

1. Install Linux environment on Visual Studio as add-on
2. Set up Visual Studio with WSL as follows:

Once you setup WSL (which is not covered here), run the following commands in WSL.

`sudo apt update`

`sudo apt install g++ gdb make ninja-build rsync zip`

Then, open the Visual Studio. Create the new project with Linux platform. Go to Properties > General > Platform Toolset. Then, select the GCC for Windows Subsystem for Linux. 

Then, you can compile with usual Visual Studio features (e.g. <kbd>ctrl</kbd> + <kbd>F5</kbd>).

Or you can then compile from the command line in WSL:

`g++ -o <FILENAME> <SOMECODE.cpp> -std=c++11`

`./a.out`

For more detail, see https://devblogs.microsoft.com/cppblog/c-with-visual-studio-2019-and-windows-subsystem-for-linux-wsl/.

### Valgrind setup on WSL:

The software to perform memory leak check. Execute the following command to install Valgrind on WSL.

`sudo apt install valgrind`

Then you can run the program with memory check e.g.:

`valgrind ./a.out`

## Compiling and Running
To compile,
`g++ -o <FILENAME.out> <ALL of .cpp> -std=c++11`

To run,
`valgrind ./a.out`


___
# Notes

| Abstract Data Type(ADT) | Other ADT names                 | Commonly implemented with: |
|-------------------------|---------------------------------|----------------------------|
| List                    | Sequence                        | Array, Linked List         |
| Queue                   |                                 | Array, Linked List         |
| Double-ended Queue      | Dequeue, Deque                  | Array, Doubly-linked List  |
| Stack                   |                                 | Array, Linked List         |
| Associative Array       | Dictionary, Hash Map, Hash, Map | Hash Table                 |
| Set                     |                                 | Red-black Tree, Hash Table |
| Priority Queue          |                                 | Heap                       |

## Front vs Back vs Top vs Bottom in LinkedList

- Stack: Insert front, remove front (or Insert back, remove back)
- Queue: Insert back, remove front
- Deque: Insert front, insert back, remove front, remove back 

### Insert Front (or push)
Insert "front" ≡ push to the "top". For example,

```
obj.insert_front(42); // or obj.push(42)
obj.insert_front(7); // or obj.push(7)
obj.insert_front(1); // or obj.push(1)
obj.insert_front(6); // or obj.push(6)
```
(front) 42 -> 7 -> 1 -> 6 (back) -> null

Typical insert front implementation:
```
Node* newNode = new Node(val, front);
front = newNodeT;
size++;
```

Insert "back" ≡ Insert at the "bottom". For example,

```
obj.insert_back(42);
obj.insert_back(7);
obj.insert_back(1);
obj.insert_back(6);
```
(front) 6 -> 1 -> 7 -> 42 (back) -> null

Given (front) 7 -> 5 -> 3 -> 1 (back) -> null,

Remove "front" ≡ pop will be:

(front) 5 -> 3 -> 1 (back) -> null

Remove "back" will be:

(front) 7 -> 5 -> 3 (back) -> null

## BST Traversal

in-order: sorted
pre-order: root, left, right
post-order: left, right, root


## Programming Practice

Variable, function naming conventions:

*camelCase*

*snake_case*

Use one but not both.

Single-character variable or function naming is not a good practice. Give a sensible naming, e.g., use size instead of sz, queueT instead of qt.


## Time complexities Table
| -                         | Best      | Worst         | Average   |
|---------------------------|-----------|---------------|-----------|
| Selection sort            | O(n^2)    | O(n^2)        | O(n^2)    |
| Insertion sort            | O(n)      | O(n^2)        | O(n^2)    |
| Merge sort                | O(n*logn) | O(n*logn)     | O(n*logn) |
| Quick sort                | O(n*logn) | O(n^2)        | O(n*logn) |
| BST(unbalanced) search    | O(1)      | O(h)=O(n)     | O(logn)   |
| BST(unbalanced) insertion |           | O(h)=O(n)     |           |
| BST(unbalanced) removal   | O(1)      | O(h)=O(n)     |           |
| BST(balanced) search      | O(1)      | O(logn)       | O(logn)   |
| BST(balanced) insertion   |           | O(logn)       |           |
| BST(balanced) removal     | O(logn)   | O(logn)       |           |
| BST(unbalanced) sort      |           | O(n*h)=O(n^2) |           |
| BST(balanced) sort        |           | O(n*logn)     |           |
| Heap insertion            |           | O(logn)       |           |
| Heap removal              |           | O(logn)       |           |
| Heap sort                 | O(n*logn) | O(n*logn)     | O(n*logn) |
| Bogosort                  | O(n)      | O(Infinite)   | O(n*n!)   |

Binary Search Tree: Can be either complete or non-complete, Fully Ordered
Heaps (max heap, min heap): Complete, Partially Ordered


## Priority Queue

pseudocode

`pq = {}`

`pq.enqueue(1)`

`pq.enqueue(8)`

`pq.enqueue(3)`

`pq.enqueue(7)`

pq becomes `{8, 7, 3, 1}`

The highest priority item is 8 (if the priority is defined for higher number).

`pq.dequeue()` --> remove 8. Time complexity is O(log n)

### Heap implementation of Priority Queue

Max heap insertion process:

1. Insert a new item into the first available leaf location, which will maintain complete tree
2. Compare this value with the parent value. If parent's value > value, swap them.
3. Continue doing comparison with the parent value, swap it, parent value comparison, swap it until it reaches root (bubbleUp).

Max Heap Removal Process:

1. Copying the right most leaf value into the removing node to overwrite the data.
2. Compare the parent value with the larger value of the child (either left child or right child). If parent value is smaller, swap them.
3. Continue comparing the parent value with the larger value of the child and swap if necessary until it reaches a leaf (bubbleDown).

Max Heap Process:

Heapifying (cost is O(n)):
1. Starting with right-most non-leaf node.
2. Compare the parent value with the larger value of the child and swap the values if necessary (bubbleDown).
3. Go to the index - 1 and repeat the process at 2, until it reaches root.

Sorting after heapifying (cost is O(n*logn)):
1. Perform Heap Removal process from the root (see above).
2. The removed value will be simply inserted into the end of the array, i.e., the free location.
3. Continue 1 and 2 until all the iterations are done, i.e., number of all elements in the heap tree.


## Hash Table

Hash Table is unordered and is implemented in C++ STL such as unordered map and unordered set.

Hash Table is disordered and often compared with ordered data structure of red black tree implementation, e.g., ordered map and ordered set.

Hash function: Maps a key to an index. It should have the following properties:

- Fast
- Deterministic
- Uniformity

Collisions: Two different keys map to a same index

Good hash function has less collisions.

solution to collisions:

1.  Open Addressing
    - Linear Probing (less efficient)
        - Cause primary cluster
    - Quadratic Probing
    - Double Hashing
2. Separate Chaining
    - Using singly linked list to each key element in the hash table

Exmaple of Hash Function: h = (Integer key) mod tableSize, where tableSize is the first prime number larger than twice the size of the number of expected values, the actual keys stored.

String key to Integer Conversion:

For alphabet letters number assigned as 1 to 26, we can use 5 binary bits since 2^5 = 32, which covers enough for the 26 alphabet letters.

Steps are:

1. Represent each letter in 5 binary bits (e.g. c = 3 = 00011).
2. Concatenate all letters which are in 5 binary bits (e.g. cat = 00011 00001 10100). 
3. Convert binary numbers to numbers in base 10 (e.g. 000110000110100 = 3,124).

Other way:

char_0 * 32 ^ n-1 + … + (char_n-2) * 32 ^ 1 + (char_n-1) * 32 ^ 0

(E.g. cat = 3 * 32^2 + 1 * 32^1 + 20 * 32^0 = 3,124)

when the result is so huge, it will cause overflow, so use *Horner's Method*

Factoring the operation such that ... see slide cmpt225_22hash1 slide 33/33



## Radix Sort


## Dijkstra’s algorithm

0.  Assign distance 0 to the initial vertex. All other verteces are initialized as ∞.
1.	Start at the initial vertex e.g. A
2.	Find the neighbor vertex to A and add distance (or called weight or cost) to the neighbor vertex. Perform comparison and update distance if necessary (see below for more detail).
3.	Choose the vertex that has the minimum distance (e.g. C).
4.	Connect the vertex (e.g. AC)
5.	Repeat from 2 – 4

Meaning that find neighbor vertexes to AC and add distance to the neighbor vertexes.

At step 2, if the added distance is smaller than the originally assigned distance, update the distance. If the new distance is greater than the originally assigned distance, leave it. This comparison is done such that:

 (original distance assigned on the neighbor vertex) > (nearby vertex that you just visited + edge distance to the neighbor vertex)

Comparison is only done between originally assigned distance on the neighbor vertex and its nearby visited vertex + edge weight.

cost = g = distance (edge weight)


Implementation detail:

This algorithm can be implemented with **indexed heap for priority queue** + **hash table for results list**.


## A* algorithm

Same as Dijkstra algorithm except the cost is not just g but f = g + h

where g is edge weight and h is estimated heuristic cost.

heuristic cost is how much distance left to the end vertex. This cost isn't known in general, so need to estimate it. 

0.  Assign distance 0 to the initial vertex. All other verteces are initialized as ∞.
1.	Start at the initial vertex e.g. A
2.	Find the neighbor vertex to A and add distance (or called weight or cost) to the neighbor vertex. Perform comparison and update f if necessary (see below for more detail).
3.	Choose the vertex that has the minimum distance (e.g. C).
4.	Connect the vertex (e.g. AC)
5.	Repeat from 2 – 4





