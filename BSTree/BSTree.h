#ifndef __BSTree_H__
#define __BSTree_H__

#include <cstddef>


using namespace std;

class Node
{
public:
  Node(int key)    {  this->key = key; left = NULL; right = NULL; }
  int Key()    { return key; }
  Node* Left()   { return left; }
  Node* Right()  { return right; }
  void setKey(int key) { this->key = key; }
  void setLeft(Node* left)     { this->left = left; }
  void setRight(Node* right)  { this->right = right; }

private:
  int key;
  Node *left;
  Node *right;
};

class BSTree
{
public:
  BSTree();
  ~BSTree();
  
  void insert(int key);
  void del(int key);
  void preorder();
  void inorder();
  void postorder();
  void show_simple();

private:
  Node* root;

  void insert(int key,Node* node);
  void preorder(Node* node);
  void inorder(Node* node);
  void postorder(Node* node);
  Node* del(Node* node,int key);
  Node* findLargest(Node* node);
  void show_simple_r(Node* node);
};

#endif
