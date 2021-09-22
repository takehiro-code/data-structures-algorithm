# Queue

Template class of Queue implementation using a singly LinkedList. Since we are implementing a template class, we include the class declaration and its member function definition inside of single header file and outside of its class declaration.


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

Do you need `inline`? -> no

Specifying a method defined outside the class definition as inline, using the keyword, is a hint* to the compiler to compile a function in a way that reduce the amount of overhead in function calling. This is useful for small functions that are called repeatedly

For template class, when to place <...>?
- Inside of the template class definitions, no need to put <type_parameter>.
- Put <type_parameter> for other template class object even inside of the class definition.
- Put <type_parameter> for each method as class_name <type_parameter>:: outside of the class definition.
- How about the method parameter in our example const List<T>& lst, do we need here or si it optional?
