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
  //void del(int num);
  void preorder();
  void inorder();
  void postorder();

private:
  Node* root;

  void insert(int key,Node* node);
  void preorder(Node* node);
  void inorder(Node* node);
  void postorder(Node* node);
};

#endif