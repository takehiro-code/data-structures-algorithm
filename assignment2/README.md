# Assignment 2

Template class of Queue implementation using a singly LinkedList. Since we are implementing a template class, we include the class declaration and its definition inside of single header file.


## Files
- QueueT.h (that includes all classes)
- main.cpp (for testing)

## Classes
### QueueT template class

Attributes:
- front pointer that points to the front of the queue
- back pointer that points to the front of the queue
- number of items in the queue (int)

### NodeT template class
Attributes:
- *data*
- *next*, which is a pointer to the next NodeT

## Notes

Given for example (front) 7 -> 5 -> 3 -> 1 (back) -> null

Enqueue method: Insert "back"

new_val -> 7 -> 5 -> 3 -> 1

Dequeue method: Remove "front"

5 -> 3 -> 1

Print: Printing from "front" to "back"

Result is 7, 5, 3, 1

