//Daniel Farone
//CSCI 3110-001
//Project #2
//Due: 02/10/22
//This implementation file for the IntSLList class defines several public functions that
//insert values chronologically into a linked list (including duplicate numbers),
//delete a single value from the list, delete all values of a specified number from the list,
//and a function that clears all elements left over in the list.
#include "intsllist.h"

//This function adds each inputted value to the list. In the event of duplicate numbers,
//the duplicate is placed after the one previously there of the same number.
void IntSLList::insertInOrder(int el)
{
        IntSLLNode *trail = head;
        IntSLLNode *lead = nullptr;
        IntSLLNode *newNode = new IntSLLNode;
        newNode->info = el;
        newNode->next = nullptr;

        //empty list case
        if(head == nullptr)
                head = newNode;
        //in order non-empty list and non-duplicate case for a new entry less than the head value (no duplicates)
        else if(newNode->info < head->info)
        {
                newNode->next = head;
                head = newNode;
        }
        //for entries greater than the head value in the list and duplicate entries
        else
        {
                while(trail != nullptr && trail->info <= newNode->info)
                {
                        lead = trail;
                        trail = trail->next;
                }
                lead->next = newNode;
                newNode->next = trail;
        }
}

//This function removes the first node having a specific value from the list. If there are duplicate numbers,
//only the first value chronologically placed in the lsit is deleted. Returns deleted value.
int IntSLList::deleteVal(int el)
{
        //initializes an integer to store the value to be returned
        int deleted_val;
        IntSLLNode *lead = head;
        IntSLLNode *trail = nullptr;
        //if list is empty
        if(head == nullptr)
                std::cout << "This list is empty!" << std::endl;
        //deleting first value, set lead to head
        else if(head->info == el)
        {
                deleted_val = head->info;
                delete head;
                head = head->next;
        }
        //deleting any other value in the list
        else
        {
                while(lead != nullptr && lead->info != el)
                {
                        trail = lead;
                        lead = lead->next;
                }
                if(lead != nullptr)
                {
                        trail->next = lead->next;
                        deleted_val = lead->info;
                        delete lead;
                }
        //for values not found in the list
                else
                        std::cout << "This value is not in the list. Returned value is NULL" << std::endl;
        }
        return deleted_val;
}

//This function remvoes all instances of nodes with a specifed value and no values are returned in this function.
void IntSLList::deleteAllVal(int el)
{
        IntSLLNode *trail = head;
        IntSLLNode *lead;
        IntSLLNode *tmp = nullptr;
        //if list is empty
        if(head == nullptr)
                std::cout << "This list is empty!" << std::endl;
        //if deleting first value, set lead to head
        if(head->info == el)
        {
                head = nullptr;
        }
        lead = trail;
        //list is not empty find the first instance of the value
        while(trail != nullptr && lead->info != el)
        {
                trail = lead;
                lead = lead->next;
        }
        //loop to delete every instance of the specified value
        while(lead != nullptr && lead->info == el)
        {
                tmp = lead;
                lead = lead->next;
                delete tmp;
        }
        trail->next = lead;
        if(head == nullptr)
                head = lead;
}
//This function clears all remaining nodes from the list nad is called by the IntSLList destructor.
//Prints the word "clearing" followed by value and address of all the deleted nodes.
void IntSLList::clearList()
{
        IntSLLNode *tmp = head;
        if(head == nullptr)
        {
                std::cout << "This list is empty. Nothing to be cleared." << std::endl;
        }
        while(tmp != nullptr)
        {
                head = head->next;
                std::cout << "clearing " << tmp->info << " " << tmp << std::endl;
                delete tmp;
                tmp = head;
        }
}
