// Iain Muir, iam9ez
// February 27th, 2020
// AVLTree.cpp

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// ----------------------------------------------------

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  if (root == NULL) {
    AVLNode* newNode = new AVLNode();
    newNode->value = x;
    root = newNode;
    return;
  }
  if (find(x)) {
    return;
  }
  insert(root, x);
  //printTree();
}

// private helper for insert
void AVLTree::insert(AVLNode*& n, const string& x) {
  if (x < n->value) {
    if (n->left == NULL) {
      AVLNode* newNode = new AVLNode();
      newNode->value = x;
      n->left = newNode;
    }
    else {
      insert(n->left, x);
    }
  }
  else {
    if (n->right == NULL) {
      AVLNode* newNode = new AVLNode();
      newNode->value = x;
      n->right = newNode;
    }
    else {
      insert(n->right, x);
    }
  }
  
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
}  

// ----------------------------------------------------

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if (!find(x)) {
    return "";
  }
  return pathTo(root, x);
}

// private helper for pathTo
string AVLTree::pathTo(AVLNode* n, const string& x) const {
  string pathname = "";
  pathname += n->value + " ";
  if (x < n->value) {
    pathname += pathTo(n->left, x);
  }
  if (x > n->value) {
    pathname += pathTo(n->right, x);
  }
  return pathname;
}

// ----------------------------------------------------

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

// private helper for find
bool AVLTree::find(AVLNode* n, const string& x) const {
  if (n == NULL) {
    return false;
  }
  if (x == n->value) {
    return true;
  }
  if (x < n->value) {
    return find(n->left, x);
  }
  if (x > n->value) {
    return find(n->right, x);
  }
  return false;
}

// ----------------------------------------------------

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

// private helper for numNodes
int AVLTree::numNodes(AVLNode* n) const {
  if (n == NULL) {
    return 0;
  }
  if (n->left != NULL and n->right != NULL) {
    return 1 + numNodes(n->left) + numNodes(n->right);
  }  
  if (n->left != NULL and n->right == NULL) {
    return 1 + numNodes(n->left);
  }
  if (n->left == NULL and n->right != NULL) {
    return 1 + numNodes(n->right);
  }
  return 1;
}  

// ----------------------------------------------------

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if (height(n->right) - height(n->left) == 2) {
    if (height(n->right->right) - height(n->right->left) < 0) {
      AVLNode* newSubRoot = rotateRight(n->right);
      n->right = newSubRoot;
    }
    n = rotateLeft(n);
  }
  if (height(n->right) - height(n->left) == -2) {
    if (height(n->left->right) - height(n->left->left) > 0) {
      AVLNode* newSubRoot = rotateLeft(n->left);
      n->left = newSubRoot;
    }
    n = rotateRight(n);
  } 
}

/*
PSEUDOCODE:

balance(node):
    if balance factor of node is 2 we will need to rotate left:
        first, see if we should also rotate right (i.e., do a double rotation)
        if balance factor of right child is negative:
            rotate right on the right child
        endif
        rotate left on node
    else if balance factor of node is -2 we will need to rotate right:
        first, see if we should also rotate left (i.e., double rotation)
        if balance factor of left is positive:
            rotate left on the left child
        endif
        rotate right on node
    endif
 */


// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* child = n->right;
  AVLNode* childLeft = child->left;
  
  n->right = childLeft;
  child->left = n;

  n->height = 1 + max(height(n->left), height(n->right));
  child->height = 1 + max(height(child->left), height(child->right));
  
  return child;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* child = n->left;
  AVLNode* childRight = child->right;
  n->left = childRight; 
  child->right = n;

  n->height = 1 + max(height(n->left), height(n->right));
  child->height = 1 + max(height(child->left), height(child->right));
  
  return child;
}

// ----------------------------------------------------

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// ----------------------------------------------------

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
