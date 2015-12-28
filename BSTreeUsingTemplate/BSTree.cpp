#include <iostream>

template<class T>
BSTree<T>::BSTree()
{
  root = NULL;
}

template<class T>
BSTree<T>::~BSTree()
{

}

template<class T>
void BSTree<T>::insert(T key)
{
  if(root == NULL)
  {
    Node<T>* newNode = new Node<T>(key);
    root = newNode;
    return;
  }
  else
  {
    insert(key, root);
  }

}

template<class T>
void BSTree<T>::del(T key)
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

template<class T>
void BSTree<T>::preorder()
{
  cout << endl << "Preorder: " <<endl;
  preorder(root);
  cout << endl;
}

template<class T>
void BSTree<T>::inorder()
{
  cout << endl << "Inorder: " <<endl;
  inorder(root);
  cout << endl;
}

template<class T>
void BSTree<T>::postorder()
{
  cout << endl << "Postorder: " <<endl;
  postorder(root);
  cout << endl;
}

template<class T>
void BSTree<T>::show_simple()
{
  cout << endl << "BSTree show:" << endl;
  if(root != NULL)
    show_simple_r(root);
  else
    cout << "Empty!";
  cout << endl;
}

template<class T>
void BSTree<T>::insert(T key, Node<T>* node)
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
      Node<T>* newNode = new Node<T>(key);
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
      Node<T>* newNode = new Node<T>(key);
      node->setRight(newNode);      
    }
  }
}

template<class T>
Node<T>* BSTree<T>::del(Node<T>* node, T key)
{
  if(node != NULL)
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
      { // Node would be deleted 
        delete node;
        return NULL;
      }
      // Case 2: Node has either left child or right child
      //
      // Case 2.1: Node has only left child
      else if((node->Left() != NULL) && (node->Right() == NULL))
      { // Node would be deleted, left child would take its place
        Node<T>* retNode = node->Left();
        delete node;
        return retNode;
      }
      // Case 2.2: Node has only right child
      else if((node->Left() == NULL) && (node->Right() != NULL))
      { // Node would be deleted, right child would take its place
        Node<T>* retNode = node->Right();
        delete node;
        return retNode;
      }
      // Case 3: both childs are present
      else
      {
        // Node Key would be replaced with inorder predecessor key value
        // -- inorder predecessor --> largest node in left subtree
        Node<T>* pred = findLargest(node->Left());
        node->setKey(pred->Key());
        node->setLeft(del(node->Left(),pred->Key()));
      }
    }
  }
  return node;
}

template<class T>
Node<T>* BSTree<T>::findLargest(Node<T>* node)
{
  if(node->Right() == NULL)
    return node;
  else
    return findLargest(node->Right());
}

template<class T>
void BSTree<T>::preorder(Node<T>* node)
{
  cout << node->Key() << " ";

  if(node->Left())
    preorder(node->Left());

  if(node->Right())
    preorder(node->Right());
}

template<class T>
void BSTree<T>::inorder(Node<T>* node)
{
  if(node->Left())
    inorder(node->Left());

  cout << node->Key() << " ";

  if(node->Right())
    inorder(node->Right());
}

template<class T>
void BSTree<T>::postorder(Node<T>* node)
{
  if(node->Left())
    postorder(node->Left());

  if(node->Right())
    postorder(node->Right());

  cout << node->Key() << " ";
}

template<class T>
void BSTree<T>::show_simple_r(Node<T>* node)
{
  cout << node->Key();
  if(node->Left() != NULL || node->Right() != NULL)
  {
    cout << "(";
    
    if(node->Left())
      show_simple_r(node->Left());

    cout << ",";

    if(node->Right())
      show_simple_r(node->Right());

    cout << ")";
  }
}

