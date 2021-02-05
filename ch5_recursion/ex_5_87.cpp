#include <iostream>
#include "tree_node.h"

int count_internal_external_nodes(tree_node* t1) {

	//if head is null
	if (t1 == 0) {
		return 0;
	}

	if (t1->right == 0 && t1->left == 0) {
		return 0;
	}

	//if node contains 1 internal node and  contains one external node on the right subtree 
	if (t1->left != 0 && t1->right == 0) {
		return 1 + count_internal_external_nodes(t1->left);
	}

	//if node contains 1 internal node and contains one external node on the left subtree 
	if (t1->right != 0 && t1->left == 0) {
		return 1 + count_internal_external_nodes(t1->right);
	}

	int count_pair_l = count_internal_external_nodes(t1->left);
	int count_pair_r = count_internal_external_nodes(t1->right);

	return count_pair_l + count_pair_r;
}


int main_5_87() {

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

	//case unbalanced tree 5 nodes
	std::cout << count_internal_external_nodes(root) << std::endl;


	tree_node* root2 = new tree_node(10, 0, 0);
	tree_node* t_left2 = root2;
	tree_node* t_right2 = root2;
	t_left2 = t_left2->left = new tree_node(4, 0, 0);
	t_right2 = t_right2->right = new tree_node(19, 0, 0);

	t_left2->left = new tree_node(2, 0, 0);
	t_left2->right = new tree_node(6, 0, 0);

	t_right2->left = new tree_node(11, 0, 0);
	t_right2->right = new tree_node(21, 0, 0);

	//case balanced tree 4 nodes
	std::cout << count_internal_external_nodes(root2) << std::endl;

	tree_node* root3 = new tree_node(10, 0, 0);
	tree_node* t_left3 = root3;

	t_left3 = t_left3->left = new tree_node(4, 0, 0);
	t_left3 = t_left3->left = new tree_node(5, 0, 0);

	//case single subtree 
	std::cout << count_internal_external_nodes(root3) << std::endl;

	return 0;
}
