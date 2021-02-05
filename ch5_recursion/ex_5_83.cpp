#include "tree_node.h"
#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\Stack_linked_list.h"



void post_order_traversal_no_recursion(tree_node* t1) {
	
	STACK_ll<tree_node*> s;
	STACK_ll<tree_node*> s2;

	if (t1 == 0) {
		return;
	}

	tree_node* t = t1;
	s.push(t);

	while (!s.empty()) {

		//pop the current node
		t = s.pop();

		//push current node into output print stack - > reverse its position
		s2.push(t);

		//get current node children and push left and right child of removed item into s1 for next iteration
		if (t->left != 0) {
			s.push(t->left);
		}

		if (t->right != 0) {
			s.push(t->right);
		}
	}

	//all items are in correct order for printing.
	while (!s2.empty()) {
		t = s2.pop();
		std::cout << t->item << std::endl;
	}


}

int main_5_83() {

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

	tree_traversal_post_order(root);

	std::cout << std::endl;

	post_order_traversal_no_recursion(root);

	std::cout << std::endl;



	return 0;
}