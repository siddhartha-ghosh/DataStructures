#include <iostream>
#include "BSTree.h"

using namespace std;


int main()
{
  cout << "Testing BSTree class ... " << endl;

  BSTree* bstree = new BSTree();

  bstree->insert(20);
  bstree->insert(15);
  bstree->insert(25);
  bstree->insert(5);

  bstree->preorder();
  bstree->inorder();
  bstree->postorder();

  return 0;
}
