#ifndef __BSTree_H__
#define __BSTree_H__

#include <cstddef>


using namespace std;

template<class T>
class Node
{
public:
  Node(T key)    {  this->key = key; left = NULL; right = NULL; }
  T Key()    { return key; }
  Node* Left()   { return left; }
  Node* Right()  { return right; }
  void setKey(T key) { this->key = key; }
  void setLeft(Node* left)     { this->left = left; }
  void setRight(Node* right)  { this->right = right; }

private:
  T key;
  Node *left;
  Node *right;
};

template<class T>
class BSTree
{
public:
  BSTree();
  ~BSTree();
  
  void insert(T key);
  void del(T key);
  void preorder();
  void inorder();
  void postorder();
  void show_simple();

private:
  Node<T>* root;

  void insert(T key,Node<T>* node);
  void preorder(Node<T>* node);
  void inorder(Node<T>* node);
  void postorder(Node<T>* node);
  Node<T>* del(Node<T>* node,T key);
  Node<T>* findLargest(Node<T>* node);
  void show_simple_r(Node<T>* node);
};

#include "BSTree.cpp"
#endif
