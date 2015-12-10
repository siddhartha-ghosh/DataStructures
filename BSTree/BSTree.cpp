#include "BSTree.h"
#include <iostream>

BSTree::BSTree()
{
  root = NULL;
}

BSTree::~BSTree()
{

}

void BSTree::insert(int key)
{
  if(root == NULL)
  {
    Node* newNode = new Node(key);
    root = newNode;
    return;
  }
  else
  {
    insert(key, root);
  }

}

void BSTree::preorder()
{
  cout << endl << "Preorder: " <<endl;
  preorder(root);
  cout << endl;
}

void BSTree::inorder()
{
  cout << endl << "Inorder: " <<endl;
  inorder(root);
  cout << endl;
}

void BSTree::postorder()
{
  cout << endl << "Postorder: " <<endl;
  postorder(root);
  cout << endl;
}


void BSTree::insert(int key, Node* node)
{
  if(node->Key() == key)
  {
    return;
  }
  else if(key < node->Key())
  {
    if(node->Left() != NULL)
    {
      insert(key,node->Left());
    }
    else
    {
      Node* newNode = new Node(key);
      node->setLeft(newNode);
    }
  }
  else 
  {
    if(node->Right() != NULL)
    {
      insert(key,node->Right());
    }
    else
    {
      Node* newNode = new Node(key);
      node->setRight(newNode);      
    }
  }
}

void BSTree::preorder(Node* node)
{
  cout << node->Key() << " ";

  if(node->Left())
    preorder(node->Left());

  if(node->Right())
    preorder(node->Right());
}

void BSTree::inorder(Node* node)
{
  if(node->Left())
    inorder(node->Left());

  cout << node->Key() << " ";

  if(node->Right())
    inorder(node->Right());
}

void BSTree::postorder(Node* node)
{
  if(node->Left())
    postorder(node->Left());

  if(node->Right())
    postorder(node->Right());

  cout << node->Key() << " ";
}

