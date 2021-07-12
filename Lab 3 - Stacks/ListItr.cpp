// Iain Muir, iam9ez
// 2/5/2020
// ListItr.cpp --> lab3

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

#include <iostream>
using namespace std;

// ListItr default constructor
ListItr::ListItr() {
  current = NULL;
}

// ListItr one-argument constructor
ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

// Returns true if the iterator is currently pointing past the end position
// in the list (i.e., it's pointing to the dummy tail), else false
bool ListItr::isPastEnd() const {
  if ((*current).next == NULL){
    return true;
  }
  else {
    return false;
  }
}

// Returns true if the iterator is currently pointing past (before) the first position
// in list (i.e., it's pointing to the dummy head), else false
bool ListItr::isPastBeginning() const {
  if ((*current).previous == NULL) {
    return true;
  }
  else {
    return false;
  }
}

// Advances `current` to the next position in the list (unless already past the end of the list)
void ListItr::moveForward() {
  if (! isPastEnd() ) {
    current = current->next;
  }
}

// Moves `current` back to the previous position in the list (unless already past the beginning of the list)
void ListItr::moveBackward() {
  if (! isPastBeginning() ) {
    current = current->previous;
  }
}

// Returns the value of the item in the current position of the list
int ListItr::retrieve() const {
  return current->value;
}
