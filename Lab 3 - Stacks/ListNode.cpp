// Iain Muir, iam9ez
// 2/5/2020
// ListNode.cpp --> lab3

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

#include <iostream>
using namespace std;

// ListNode constructor
ListNode::ListNode() {
  value = 0;
  next = NULL;
  previous = NULL;
}
