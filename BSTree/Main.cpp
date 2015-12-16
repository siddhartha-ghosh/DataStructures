#include <iostream>
#include "BSTree.h"

using namespace std;


int main()
{
  cout << "Testing BSTree class ... " << endl;

  BSTree* bstree = new BSTree();

  int input = -1;
  do
  {
    cout << endl << "Menu::" << endl;
    cout << "1.Insert 2.Delete 3.Show 4.PreOrder 5.Inorder 6.PostOrder 0.Exit" << endl;
    cin >> input;

    switch(input)
    {
      case 1:
        {
          int key;
          cout << "Enter the key to insert:" ;
          cin >> key;
          bstree->insert(key);
          bstree->show_simple();
        }
        break;
      case 2:
        {
          int key;
          cout << "Enter the key to delete:" ;
          cin >> key;
          bstree->del(key);
          bstree->show_simple();
        }
        break;
      case 3:
        bstree->show_simple();
        break;
      case 4:
        bstree->preorder();
        break;
      case 5:
        bstree->inorder();
        break;
      case 6:
        bstree->postorder();
        break;
      case 0:
        break;
      default:
        cout << "Not a valid input!!!" << endl;
        break;
    }
  }
  while(input != 0);

  return 0;
}
