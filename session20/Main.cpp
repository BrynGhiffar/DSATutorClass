#include <iostream>
#include "BinaryTree.h"
using namespace std;
int main() {

	BTree<int, int> myTree;
	myTree.set(1, 1);
	myTree.set(3, 3);
	myTree.set(2, 2);
	// myTree.set(4, -1);
	// myTree.set(5, 1);
	// myTree.set(6, 2);
	// myTree.set(7, 3);
	cout << "Height: " << myTree.height() << "\n";
	// std::cout << myTree.get(4) << "\n";

	// cout << myTree.get(10);
	// BTree<int, int> copiedTree(myTree);
	// myTree.set(1, 0);
	// myTree.set(3, 10);
	// myTree.set(5, -10);
	// myTree.set(7, 100);

	// std::cout << myTree.get(4) << "\n";
	// std::cout << myTree.get(2) << "\n";
	// std::cout << myTree.get(6) << "\n";
	// std::cout << myTree.get(100) << "\n";
	cout << "--- PREORDER TRAVERSAL ---\n";
	myTree.traverse("PREORDER");
	// cout << "--- INORDER TRAVERSAL ---\n";
	// myTree.traverse("INORDER");
	// cout << "--- POSTORDER TRAVERSAL ---\n";
	// copiedTree.traverse("POSTORDER");
	// cout << "Height: " << myTree.height() << "\n";
}