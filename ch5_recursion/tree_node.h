#pragma once
#include <iostream>

typedef int Item;

struct tree_node {
	Item item;
	tree_node* left;
	tree_node* right;

	tree_node(Item i, tree_node* l, tree_node* r) {
		item = i;
		left = l;
		right = r;
	}
};

namespace {
	//namespace is needed when sharing functions and variables
	//outside of a class in multiple cpp files

	void tree_traversal(tree_node* root) {
		//inorder tree traversal. print all nodes in order left -> middle -> right

		//if leaf node child is null return nothing
		if (root == 0) {
			return;
		}

		//otherwise traverse tree and print items
		else {

			//traverse to left
			tree_traversal(root->left);

			//print the middle node
			std::cout << root->item << std::endl;

			//traverse right
			tree_traversal(root->right);
		}


	};

	void tree_traversal_post_order(tree_node* root) {
		//inorder tree traversal. print all nodes in order left -> middle -> right

		//if leaf node child is null return nothing
		if (root == 0) {
			return;
		}

		//otherwise traverse tree and print items
		else {

			//traverse to left
			tree_traversal_post_order(root->left);

			//traverse right
			tree_traversal_post_order(root->right);

			//print the middle node
			std::cout << root->item << std::endl;
		}


	};
}