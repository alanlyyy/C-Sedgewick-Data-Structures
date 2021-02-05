#include "tree_node.h"
#include <iostream>

int calc_internal_length(tree_node* t1, int level) {
	//traverses to null node for case where node has 1 child. 
	//calculation is proportional to number of nodes +  # of null childs

	//if t1 is nullptr
	if (t1 == 0) {
		return 0;
	}

	//if leaf node return 0
	if (t1->left == 0 && t1->right == 0) {
		return 0;
	}

	int left_sub_tree = calc_internal_length(t1->left, level + 1);
	int right_sub_tree = calc_internal_length(t1->right, level + 1);

	//add sums + current level
	return left_sub_tree + right_sub_tree + level;
}
int main_5_88() {

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
	std::cout << calc_internal_length(root,0) << std::endl;


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
	std::cout << calc_internal_length(root2,0) << std::endl;

	tree_node* root3 = new tree_node(10, 0, 0);
	tree_node* t_left3 = root3;

	t_left3 = t_left3->left = new tree_node(4, 0, 0);
	t_left3 = t_left3->left = new tree_node(5, 0, 0);

	//case single subtree 
	std::cout << calc_internal_length(root3,0) << std::endl;

	return 0;
}