#include <iostream>
#include "BinaryTree.h"

using namespace std;
void test_node_count() {
	cout << "--- TEST NODE COUNT ---\n";
	BTree<int, int> tree;
	tree.set(1, 1);
	tree.set(2, 2);
	tree.set(3, 3);
	tree.set(4, 4);
	tree.set(5, 5);
	tree.set(6, 6);
	tree.set(7, 7);
	tree.traverse("PREORDER");
	cout << "Node count: " << tree.node_count() << endl;
	tree.remove(2);
	tree.traverse("PREORDER");
	cout << "Node count: " << tree.node_count() << endl;
}

void test_leaves_count() {
	cout << "--- TEST LEAVES COUNT ---\n";
	BTree<int, int> tree;
	tree.set(1, 1);
	tree.set(2, 2);
	tree.set(3, 3);
	tree.set(4, 4);
	tree.set(5, 5);
	tree.set(6, 6);
	tree.set(7, 7);
	tree.traverse("PREORDER");
	cout << "Leaves count: " << tree.leaves_count() << endl;
	tree.remove(2);
	tree.traverse("PREORDER");
	cout << "Leaves count: " << tree.leaves_count() << endl;
}

void test_swap_subtrees() {
	cout << "--- TEST SWAP SUBTREES ---\n";
	BTree<int, int> tree;
	tree.set(1, 1);
	tree.set(2, 2);
	tree.set(3, 3);
	tree.set(4, 4);
	tree.set(5, 5);
	tree.set(6, 6);
	tree.set(7, 7);
	tree.traverse("PREORDER");
	tree.swap_subtrees();
	tree.traverse("PREORDER");
}

void test_avl() {
	BTree<int, int> tree;
	tree.set(4, 4);
	tree.set(6, 2);
	tree.set(5, 3);
	tree.traverse("PREORDER");

}

int main() {
	// test_node_count();
	/// test_leaves_count();
	test_swap_subtrees();
	// test_avl();
}