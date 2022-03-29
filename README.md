# IntegerLinkedLists-C-

Project description:
Create a class representing an ordered singly linked list. The list will store integers in
ascending order. The driver program instantiates a list and applies operations read from the input file.

Requirements:

1. Program split into three files:

  a) The class interface (or declaration) file named intsllist.h, and is provided on course calendar. This file
  must not be edited.
  
  b) A class implementation, or definition, file
    
     Must be implemented as specified in the header file
    
     Must have the implementation for functions not implemented in the header file. 
      Observe the following:
        
        i. insertInOrder – Adds each value to the list in ascending order. In the event duplicate values are
        added to the list, the newly added node must come after those with the same value already in the
        list. Example: If the list already has the number 4 and another 4 is added to the list, the newly added
        node must come after the one already in the list.
        
        ii. deleteVal – This function removes the first node instance having the specified value from the list. In
        the event items having the same value are in the list, this function should only remove the first
        instance of the value. The function should return the deleted value.
        
        iii. deleteAllVal – This function must remove all instances of nodes having the specified value from the
        list.
        
        iv. clearList – This function must remove all nodes from the list. It should print the word Clearing
        followed by value and address of the node being deleted. This function is called by the destructor.

c) A driver, or client, file

   Reads data from input file named ints.txt, having pairs of integers and characters on each line (separated by
  a space), and representing operations to be performed on the list. Each line is formatted as follows:

    1. The first element of each line is the integer to be added or removed from the list.

    2. The second element is one of characters a, d, or D, and should be interpreted as follows:

   a = add the integer to the list (duplicates must follow rules specified above)

   d = remove a single instance of the integer from the list (as specified above)

   D = remove all instances of the integer from the list


Note: Each operation on the list must be printed, and the printAll function must be called after each
operation to show the contents of the list (see sample output). 
