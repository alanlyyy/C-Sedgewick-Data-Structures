#include <iostream>

typedef int Item3;

struct tree_node3 {
	Item3 item;
	tree_node3* left;
	tree_node3* right;

	tree_node3(Item3 i, tree_node3* l, tree_node3* r) {
		item = i;
		left = l;
		right = r;
	}
};
bool is_isomorphic_BT(tree_node3* t1, tree_node3* t2) {
	//are both binary trees isomorphic, same structure?

	//if both nodes are null
	if ((t1 == 0) && (t2 == 0)) {
		return true;
	}

	//if either current node is null, while the other node is not null
	else if (t1 == 0 || t2 == 0) {
		return false;
	}

	//if the data for both nodes are not the same
	else if (t1->item != t2->item) {
		return false;
	}

	//there are two possible cases for t1 and 2 to be isomorphic
	//case 1: the subtrees rooted at these nodes have not been flipped. t1->left = t2-> left, t1->right = t2->right
	//Both of these subtrees have to be isomorphic, hence the &&
	//case 2: the subtrees at these nodes have been flipped. t1->left = t2->right or t2->right = t1->left;
	else {

		bool left_right  =is_isomorphic_BT(t1->left, t2->right);
		bool right_left = is_isomorphic_BT(t1->right, t2->left);
		bool left_left = is_isomorphic_BT(t1->left, t2->left);
		bool right_right = is_isomorphic_BT(t1->right, t2->right);

		std::cout << left_right << " " << right_left << " " << left_left << " " << right_right << std::endl;

		return left_right || right_left || left_left || right_right;
	}
}

int main_5_65() {
	tree_node3* t1 = new tree_node3(0, 0, 0);
	t1->left = new tree_node3(5, 0, 0);
	t1->right = new tree_node3(8, 0, 0);

	t1->left->left = new tree_node3(4, 0, 0);
	t1->left->right = new tree_node3(1, 0, 0);

	tree_node3* t2 = new tree_node3(0, 0, 0);
	t2->right = new tree_node3(5, 0, 0);
	t2->left = new tree_node3(8, 0, 0);

	t2->right->right = new tree_node3(4, 0, 0);
	t2->right->left = new tree_node3(1, 0, 0);

	tree_node3* t3 = new tree_node3(0, 0, 0);
	t3->left = new tree_node3(1, 0, 0);
	t3->right = new tree_node3(5, 0, 0);

	tree_node3* t4 = new tree_node3(0, 0, 0);
	t4->left = new tree_node3(5, 0, 0);
	t4->right = new tree_node3(1, 0, 0);

	std::cout << "True: " << is_isomorphic_BT(t1, t2) << std::endl;
	return 0;
}