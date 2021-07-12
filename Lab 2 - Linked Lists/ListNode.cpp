// Iain Muir, iam9ez
// 1/30/2020
// ListNode.cpp

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
