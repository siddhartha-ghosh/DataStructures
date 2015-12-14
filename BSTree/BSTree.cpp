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

void BSTree::del(int key)
{
  if(root == NULL)
  {
    cout << endl << "Empty tree !! nothing to delete ..." << endl;
  }
  else
  {
    root = del(root,key);
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

Node* BSTree::del(Node* node, int key)
{
  if(key < node->Key())
  {
    node->setLeft(del(node->Left(),key));
  }
  else if(key > node->Key())
  {
    node->setRight(del(node->Right(),key));
  }
  else
  { // key matches with current node key

    // Case 1: Node is a leaf node -- both left and right child are NULL.
    if((node->Left() == NULL) && (node->Right() == NULL))
    {
      delete node;
      return NULL;
    }
    // Case 2: Node has either left child or right child
    //
    // Case 2.1: Node has only left child
    else if((node->Left() != NULL) && (node->Right() == NULL))
    {
      Node* retNode = node->Left();
      delete node;
      return retNode;
    }
    // Case 2.2: Node has only right child
    else if((node->Left() == NULL) && (node->Right() != NULL))
    {
      Node* retNode = node->Right();
      delete node;
      return retNode;
    }
    // Case 3: both childs are present
    else
    {
      //////////////////////////////////////
      ////////   TBD ///////////////////////
      //////////////////////////////////////
    }
  }
  return node;
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

