#ifndef _BINARYTREE_H_
# define _BINARYTREE_H_
#include <iostream>
using std::cout;
using std::endl;

template <class K, class I>
struct BTreeNode {
	K key;
	I item;
	BTreeNode<K, I>* left;
	BTreeNode<K, I>* right;
};

template <class K, class I>
class BTree {
private:
	BTreeNode<K, I>* root;

	// private auxiliary functions
	BTreeNode<K, I>* set_aux(BTreeNode<K, I>* root, K key, I item);
	BTreeNode<K, I>* get_aux(BTreeNode<K, I>* root, K key);
	BTreeNode<K, I>* remove_aux(BTreeNode<K, I>* root, K key);
	void traverse_aux(BTreeNode<K, I>* root, const std::string& order);
	int height_aux(BTreeNode<K, I>* root);
	BTreeNode<K, I>* copy(BTreeNode<K, I>* root);
	BTreeNode<K, I>* min_node(BTreeNode<K, I>* root);
	BTreeNode<K, I>* left_rotation(BTreeNode<K, I>* root);
	BTreeNode<K, I>* right_rotation(BTreeNode<K, I>* root);
	// imbl is when it is outside the balancing factor range
	bool is_left_imbl(BTreeNode<K, I>* root);
	bool is_right_imbl(BTreeNode<K, I>* root);

	// heavy is when the bl is just 1 or -1
	bool is_left_heavy(BTreeNode<K, I>* root);
	bool is_right_heavy(BTreeNode<K, I>* root);

	BTreeNode<K, I>* balancing(BTreeNode<K, I>* root);
public:
	BTree(): root(NULL) {}

	BTree(const BTree<K, I>& tree);

	void set(K key, I item);
	I get(K key);
	void remove(K key);
	void traverse(const std::string& order);
	int height();
};

template <class K, class I>
BTree<K, I>::BTree(const BTree<K, I>& tree) {
	root = copy(tree.root);
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::copy(BTreeNode<K, I>* root) {
	if (root == NULL) {
		return NULL;
	}
	else {
		BTreeNode<K, I>* copied = new BTreeNode<K, I>;
		copied->key = root->key;
		copied->item = root->item;
		copied->left = copy(root->left);
		copied->right = copy(root->right);
		return copied;
	}
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::set_aux(BTreeNode<K, I>* root, K key, I item) {
	if (root == NULL) {
		BTreeNode<K, I>* new_node = new BTreeNode<K, I>;
		new_node->key = key;
		new_node->item = item;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	else {
		if (root->key == key) {
			root->item = item;
		}
		else if (root->key > key) {
			root->left = set_aux(root->left, key, item);
		}
		else if (root->key < key) {
			root->right = set_aux(root->right, key, item);
		}
		root = balancing(root);
		return root;
	}
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::get_aux(BTreeNode<K, I>* root, K key) {
	if (root == NULL) {
		// key not found
		return NULL;
	}
	else {
		if (root->key == key) {
			return root;
		}
		else if (root->key > key) {
			return get_aux(root->left, key);
		}
		else {
			return get_aux(root->right, key);
		}
	}
}

template <class K, class I>
void BTree<K, I>::set(K key, I item) {
	root = set_aux(root, key, item);
}

template <class K, class I>
I BTree<K, I>::get(K key) {
	BTreeNode<K, I>* node = get_aux(root, key);
	if (node == NULL) {
		throw "KEY NOT FOUND!!!";
	}
	else {
		return node->item;
	}
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::min_node(BTreeNode<K, I>* root) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->left == NULL) {
		return root;
	}
	else {
		return min_node(root->left);
	}
}

template <class K, class I>
void BTree<K, I>::remove(K key) {
	root = remove_aux(root, key);
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::remove_aux(
	BTreeNode<K, I>* root, K key
) {
	if (root == NULL) {
		return NULL;
	}
	else {
		if (root->key > key) {
			root->left = remove_aux(root->left, key);
			root = balancing(root);
			return root;
		}
		else if (root->key < key) {
			root->right = remove_aux(root->right, key);
			root = balancing(root);
			return root;
		}
		else if (root->key == key) {
			if (root->left == NULL) {
				BTreeNode<K, I>* right = root->right;
				delete root;
				right = balancing(right);
				return right;
			} else if (root->right == NULL) {
				BTreeNode<K, I>* left = root->left;
				delete root;
				left = balancing(left);
				return left;
			}
			else {
				// key matches
				// If the node has two children
				// 1. Want to find the successor
				// 2. Want to swap nodes with the successor
				// 3. use the remove aux function to continue
				// to remove the node we want to delete
				BTreeNode<K, I>* succ = min_node(root->right);
				std::swap(succ->key, root->key);
				std::swap(succ->item, root->item);
				std::cout << succ->key << "\n";
				root->right = remove_aux(succ, key);
				return root;
			}
		}
	}
}

template <class K, class I>
void BTree<K, I>::traverse(const std::string& order) {
	traverse_aux(root, order);
}

template <class K, class I>
void BTree<K, I>::traverse_aux(BTreeNode<K, I>* root, const std::string& order) {
	if (root == NULL) {
		return;
	}
	else {
		if (order == "PREORDER")
			cout << "Key: " << root->key << ", Item: " << root->item << endl;
		traverse_aux(root->left, order);
		if (order == "INORDER")
			cout << "Key: " << root->key << ", Item: " << root->item << endl;
		traverse_aux(root->right, order);
		if (order == "POSTORDER")
			cout << "Key: " << root->key << ", Item: " << root->item << endl;
	}
}

template<class K, class I>
int BTree<K, I>::height()
{
	return height_aux(root);
}

template<class K, class I>
int BTree<K, I>::height_aux(BTreeNode<K, I>* root)
{
	if (root == NULL) {
		return -1;
	}
	else {
		return std::max(height_aux(root->left), height_aux(root->right)) + 1;
	}
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::left_rotation(BTreeNode<K, I>* root) {
	if (root->right == NULL) {
		throw "Cannot do left rotation when right child is empty";
	}
	else {
		BTreeNode<K, I>* ret = root->right;
		root->right = ret->left;
		ret->left = root;
		return ret;
	}
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::right_rotation(BTreeNode<K, I>* root) {
	if (root->left == NULL) {
		throw "Cannot do right rotation when left child is empty";
	}
	else {
		BTreeNode<K, I>* ret = root->left;
		root->left = ret->right;
		ret->right = root;
		return ret;
	}
}

template <class K, class I>
BTreeNode<K, I>* BTree<K, I>::balancing(BTreeNode<K, I>* root) {
	if (root == NULL) return root;
	if (is_left_imbl(root)) {
		// some rotations
		// then return correct nodes
		if (is_right_heavy(root->left)) {
			root->left = left_rotation(root->left);
		}
		return right_rotation(root);
	}
	if (is_right_imbl(root)) {
		// some rotations
		// tehn return correct nodes
		if (is_left_heavy(root->right)) {
			root->right = right_rotation(root->right);
		}
		return left_rotation(root);
	}
	// do nothing
	return root;
}

template <class K, class I>
bool BTree<K, I>::is_left_imbl(BTreeNode<K, I>* root) {
	return (height_aux(root->left) - height_aux(root->right)) > 1;
}

template <class K, class I>
bool BTree<K, I>::is_right_imbl(BTreeNode<K, I>* root) {
	return (height_aux(root->left) - height_aux(root->right)) < -1;
}

template <class K, class I>
bool BTree<K, I>::is_left_heavy(BTreeNode<K, I>* root) {
	return (height_aux(root->left) - height_aux(root->right)) == 1;
}

template <class K, class I>
bool BTree<K, I>::is_right_heavy(BTreeNode<K, I>* root) {
	return (height_aux(root->left) - height_aux(root->right)) == -1;
}
#endif