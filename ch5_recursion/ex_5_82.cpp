#include <iostream>
#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\Stack_linked_list.h"
#include "tree_node.h"

void inorder_traversal_non_recursive(tree_node* t1) {
	
	STACK_ll<tree_node*> s;

	tree_node* t = t1;

	tree_node* h;
	
	//start from left push all left nodes
	while (t != 0) {
		s.push(t);
		t = t->left;
	}

	//visit left nodes and subchildren of left nodes
	while (!s.empty()) {
		
		h = s.pop();
		
		//pop and visit current item
		std::cout << h->item << std::endl;
		
		//if right child has children
		if (h->right != 0) {
			s.push(h->right);
			h = h->right;

			//store all left nodes in right subtree
			while (h->left != 0) {
				s.push(h->left);
				h = h->left;
			}
		}
	}
}

int main_5_82() {

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

	tree_traversal(root);

	std::cout << std::endl;

	inorder_traversal_non_recursive(root);

	std::cout << std::endl;



	return 0;
}
