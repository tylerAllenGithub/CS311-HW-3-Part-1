//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Tyler Allen
//Compiler: g++  
//File type: llist implementation file
//=====================================================
//Purpose: To construct a linked list with function that add and delete nodes.
//To be used with a client class for testing.
//Algorithm: Traverse the list with a pointer variable, for deleting ith nodes: use 1 more pointer for prev

using namespace std;

#include<iostream>
#include"llist.h" 

//Constructor
llist::llist()
{
//- initialize Front and Rear to be NULL and Count = 0.
  Front = NULL;
  Rear = NULL;
  Count = 0;
//- This does not create any node.  The new list is empty.
}
  
//Destructor 
llist::~llist()
{
  cout<<"calling the llist destructor."<<endl;
  int temp;
  while(!isEmpty())
    {
      deleteFront(temp);// while the list is not empty, call deleteFront repeatedly to delete all nodes.
    }
} 

bool llist::isEmpty()
{
  if(Front==NULL&&Rear==NULL&&Count==0)
    return true;
// return true if Front and Rear are both pointing to NULL and Count is 0.
  return false;
}
void llist::displayAll()
{
// Special case: if the list is empty, display [ empty ] ).
  if(this->isEmpty())
    cout<<"[ empty ]"<<endl;
  else
    {
  // - Regular: 
  //  displays each element of the list horizontally starting from Front in [ ].
      Node *p = Front;//used to cycle through list
      cout<<"[ ";
      while(p!=NULL)
	{
	  cout<<p->Elem<<" ";
	  p = p->Next;
	}
      cout<<"]"<<endl;
    }
} 
void llist::addRear(el_t NewNum) 
{
//2 cases:
// - Special case: if this is going to be the very first node,
  if(isEmpty())
    {
      addFront(NewNum);//call addFront because list is empty
    }
  else if (Front==Rear&&Count==1)//Special case: Where there is only one node in the list
      {
	Rear->Next = new Node;
	Rear = Rear->Next;
	Front->Next=Rear;
	Rear->Elem = NewNum;
	Rear->Next = NULL;
	Count++;//Count is updated.
      }
      else
	{
	  //  - Regular: adds a new node at the rear and puts NewNum in the Elem field	 
	  // of this new node. Count is updated.
	  //Regular case:
	  Rear->Next = new Node;
	  Rear = Rear->Next;
	  Rear->Elem = NewNum;
	  Rear->Next = NULL;
	  Count++;//Count is updated.
	}
}
void llist::addFront(el_t NewNum)
{
  //2 cases:
  //- Special case: if this is going to be the very first node,
  if(isEmpty())
    {
      //  create a new node and make Front and Rear point to it.
      Front = new Node;
      Rear = Front;
      Front->Elem = NewNum;// Place NewNum
      Rear->Next = NULL;
      Count++;//Count is updated.
    }
  else
    {
      //- Regular: add a new node to the front of the list and 
      //  Regular case:
      Node *x;//new node to be added to Front of Linked List
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      Count++;// Count is updated.
    }
}

void llist::deleteFront(el_t& OldNum)
{
  //3 cases:
  //- Error case: if the List is empty, throw Underflow
  if(isEmpty())
    throw Underflow();
  //- Special case: if currently only one Node,
  else if(Front==Rear&&Count==1)
    {
      // give back the front node element through OldNum (pass by reference) 
      OldNum = Front->Elem;
      delete Front;
      // make sure both Front and Rear become NULL
      Front = NULL;
      Rear = NULL;
      Count--;//Count is updated
    }
 else
  {
    //- Regular: give back the front node element through OldNum (pass by reference)
    //Regular case:
    OldNum = Front->Elem;
    Node *Second;//Holds second element that will become new front
    Second = Front->Next;
    delete Front;//removes the front node.
    Front = Second;
    Count--;//Count is updated
  }
}	
void llist::deleteRear(el_t& OldNum)
{
  //3 cases:
  //- Error case: if empty, throw Underflow
  if(isEmpty())
    throw Underflow();
  //- Special case: if currently only one node,

  else if(Front->Next==NULL&&Count==1)
    {
      //give back the rear node element through OldNum (pass by reference) and
      OldNum = Front->Elem;
      delete Front;
      Rear = NULL;
      Front = NULL;//make sure both Front and Rear become NULL.
      Count--;// Count is updated.
     }
  
  //- Regular: give back the rear node element through OldNum (pass by reference)
  //and also remove the rear node. Count is updated.
  //Regular case:
    else
    {
      OldNum = Rear->Elem;
      Node *p = Front;
      //  Make p go to the one right before rear (using while)
      while(p->Next!=Rear)
	{
	  p=p->Next;
	}
      delete Rear;
      Rear = p;
      Rear->Next=NULL;
      Count--;//Count is updated
    }
  
}

void llist::deleteIth(int I, el_t& OldNum)
{
//4 cases:
//- Error case: 
// If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
  if(I>Count || I<1) 
    {
      throw OutOfRange();
    }
//- Special case: this should simply call deleteFront when I is 1 
  else if(I==1)
  deleteFront(OldNum);
//Special case: this should simply call deleteRear when I is Count
  else if(Count==I)
    deleteRear(OldNum);

//- Regular: delete the Ith node (I starts out at 1).  Count is updated.
//<see the template loops in the notes to move 2 pointers to the right nodes;
//and make sure you indicate the purposes of these local pointers>
  else
    {
      Node *p = Front;//to get to the Ith element
      Node *q=Front; //to get to the element before the Ith element
      for(int k=1;k<=I-1;k++)
	{
	  q=p;
	  p=p->Next;
	}
      OldNum=p->Elem;
      q->Next=p->Next;
      delete p;
      p=q->Next;
      Count--;
    }
}

void llist::addbeforeIth(int I, el_t newNum)
{
//4 cases:
//-  Error case:
//   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
  if(I>Count+1|| I<1)
    throw OutOfRange();
//-  Special cases: this should simply call addFront when I is 1 
  else if(I==1)
    addFront(newNum);
// addRear when I is Count+1
  else if(I==Count+1)
    addRear(newNum);
//-  Regular: add right before the Ith node. Cout if updated.
//<see the template loops in the notes to move 2 pointers to the right nodes
//and make sure you indicate the purposes of these local pointers>
  else
    {
      Node *p = Front;//to get to the Ith element
      Node *q; //to get to the element before the Ith element
      for(int k=1;k<=I-1;k++)
        {
          q=p;
          p=p->Next;
        }
      Node *l = new Node;//New Node that will be added
      l->Elem=newNum;
      q->Next=l;
      l->Next=p;
      Count++;
    }


}
