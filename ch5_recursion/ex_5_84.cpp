#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\queue_interface_ll.h"
#include "tree_node.h"

void level_order_traversal(tree_node* t1) {

	Queue<tree_node*> q1(1);
	Queue<tree_node*> q2(1);

	q1.put(t1);

	while (!q1.empty()) {
		tree_node* sub_root = q1.get();

		q2.put(sub_root);

		if (sub_root->left != 0) {
			q1.put(sub_root->left);
		}

		if (sub_root->right != 0) {
			q1.put(sub_root->right);
		}
	}

	while (!q2.empty()) {
		std::cout << q2.get()->item << " ";
	}

	std::cout << std::endl;
}


int main_5_84() {

	//create a dummy tree
	tree_node* root = new tree_node(10, 0, 0);
	tree_node* t_left = root;
	tree_node* t_right = root;
	t_left = t_left->left = new tree_node(4, 0, 0);
	t_right = t_right->right = new tree_node(19, 0, 0);

	t_left->left = new tree_node(2, 0, 0);
	t_left->right = new tree_node(6, 0, 0);
	t_left->right->right = new tree_node(7, 0, 0);
	t_left->right->left = new tree_node(5, 0, 0);

	t_right->left = new tree_node(11, 0, 0);
	t_right->right = new tree_node(21, 0, 0);
	t_right->right->left = new tree_node(20, 0, 0);

	level_order_traversal(root);

	return 0;
}