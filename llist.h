//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Tyler Allen
// Compiler:  g++ 
// File type: header file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: Returns true if linked list is empty otherwise return false
  //PARAMETERS: None
  bool isEmpty();
    
  //PURPOSE: Displays all of the elements in a linked list
  //PARAMETERS: None
  void displayAll();

  //PURPOSE; Add a node to the rear of the list, make sure there are no dangling pointers
  //PARAMETERS:  takes an el_t value
  void addFront(el_t NewNum);
    
  //PURPOSE: Add a node to the rear of the list, make sure there are no dangling pointers
  //PARAMETERS: takes an e l_t value
  void addRear(el_t NewNum);

  //PURPOSE: Delete a node from the front of the list, make sure there are no dangling pointers
  //PARAMETERS: takes an el_t passed by reference
  void deleteFront(el_t& OldNum);
    
  //PURPOSE: Delete a node from the rear of the list, make sure there are no dangling pointers
  //PARAMETERS: takes an el_t passed by reference
  void deleteRear(el_t& OldNum);
    
  //PURPOSE: Delete the node at index position i, make sure there are no dangling pointers
  //PARAMETERS: takes an integer passed by value and el_t passed by reference

  void deleteIth(int I, el_t& OldNum);

  //PURPOSE: Add a node before the node at index position i of the list.
  //PARAMETERS: takes an integer passed by value and el_t passed by reference
  void addbeforeIth(int I, el_t NewNum);
    
};
