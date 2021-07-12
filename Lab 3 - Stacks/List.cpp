// Iain Muir, iam9ez
// 2/5/2020
// List.cpp --> lab3

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

#include <iostream>
using namespace std;

// List constructor
List::List() {
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0; 
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// List destructor
List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// Returns true if empty, else false
bool List::isEmpty() const {
  if (count == 0) {
    return true;
  }
  else {
    return false;
  }
}

// Removes (deletes) all items except the dummy head/tail.
// The list should be a working empty list after this.
void List::makeEmpty() {
  ListItr itr = first();
  while (count != 0) {
    remove(itr.current->value);
    itr.moveForward();
  }
  head->next = tail;
  head->previous = NULL;
  tail->previous = head;
  tail->next = NULL;
}

// Returns an iterator that points to the first ListNode **after** the dummy head node
ListItr List::first() {
  ListItr itr = head->next;
  return itr;
}

// Returns an iterator that points to the last ListNode **before** the dummy tail node
ListItr List::last() {
  ListItr itr = tail->previous;
  return itr;
}

// Inserts x after current iterator position
void List::insertAfter(int x, ListItr position) {
  ListNode* newNode = new ListNode();
  newNode->value = x;

  newNode->next = position.current->next;
  newNode->previous = position.current;
  position.current->next = newNode;
  newNode->next->previous = newNode;
  count++;
}

// Inserts x before current iterator position
void List::insertBefore(int x, ListItr position) {
  ListNode* newNode = new ListNode();
  newNode->value = x;

  newNode->next = position.current;
  newNode->previous = position.current->previous;
  position.current->previous = newNode;
  newNode->previous->next = newNode;
  count++;
}

// Inserts x at tail of list
void List::insertAtTail(int x) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  
  ListNode* last = tail->previous;
  newNode->previous = last;
  last->next = newNode;
  newNode->next = tail;
  tail->previous = newNode;
  count++;
}

// Returns an iterator that points to the **last** occurrence of x.
// When the parameter is not in the list, return a ListItr object that points to the dummy tail node.

// FUNCTION CHANGED -- switched so that the iterator returns to the last occurence
// Ensures the stack pops from the top rather than another occurence of the value
ListItr List::find(int x) {
  ListItr itr = last();
  while (! itr.isPastEnd()) {
    if (itr.current->value == x) {
      break;
    }
    else {
      itr.moveBackward();
    }
  }
  return itr.current;
}

// Removes the first occurrence of x
void List::remove(int x) {
  ListItr itr = find(x);
  if (itr.isPastEnd()) {
    cout<< "Node not in list" << endl;
  }
  else {
    itr.current->previous->next = itr.current->next;
    itr.current->next->previous = itr.current->previous;
    count--;
  }
}

// Returns the number of elements in the list
int List::size() const {
  return count;
}

// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
void printList(List& source, bool forward) {
  if (forward) { // print from head to tail
    ListItr itr(source.first());
    while(!itr.isPastEnd()) {
      cout << itr.retrieve() << endl;
      itr.moveForward();
    }
  }
  if (!forward) { //print from tail to head
    ListItr itr(source.last());
    while(!itr.isPastBeginning()) {
      cout << itr.retrieve() << endl;
      itr.moveBackward();
    }
  }
}
