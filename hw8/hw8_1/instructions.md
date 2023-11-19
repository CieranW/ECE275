# Ordered Lists

An OrderedList is a vector that keeps elements in sorted order.

Complete template `<typename TheType>` class OrderedList by defining the following functions:

1. **int Size()**
    - Return the size of the list
2. **TheType At(int index)**
    - Return the element of the list at parameter index.
3. **int Find(TheType value)**
    - Return the index of the first element in the list equal to parameter value.
    - Return -1 if parameter value is not found in the list.
4. **bool Remove(TheType value)**
    - Search the list for parameter value. Hint: Use Find().
    - If parameter value is found in the list, remove the element found by moving the subsequent elements towards the beginning of the list. Decrement list size and return true.
    - Return false if parameter value is not found in the list.
Hint: Use any vector functions to simplify the implementations.

The template code provides the implementations of the following functions:

1. **void Insert(TheType value)**
    - Search the list for an element that is greater than parameter value.
    - If an element is found, increment list size and move the element and all subsequent elements towards the end of the list to make room for parameter value. Copy parameter value at the location that was occupied by the first element greater than parameter value.
    - If no such element is found, increment list size and add parameter value at the end of the list.
2. **void Print()**
    - Output the list, separated by a space character.
    - A main program is provided as a sample test in the develop mode. Unit tests will be used during a submission.

Ex: if the given **main()** is executed, the output of the program is

    Size is correct
    List is in correct order: 3 7 11
    Index of 11 is correct -- 2
    7 was removed correctly
