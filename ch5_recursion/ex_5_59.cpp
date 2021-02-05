#include <iostream>
#include "tree_node.h"


tree_node* FindMin(tree_node* root){

	//if there are no nodes in the left subtree, root is the min
	if (root->left == NULL) {
		return root;
	}

	//if left subtree is not empty, continue to traverse left subtree until null is found
	else {
		return FindMin(root->left);
	}
}

tree_node* delete_node_recursive(tree_node* r, Item item) {

	tree_node* t = r;

	//if tree is empty return null
	if (r == NULL) {
		return r;
	}
	else if (item < r->item) {
		r->left = delete_node_recursive(r->left, item);
	} 

	else if (item > r->item) {
		r->right = delete_node_recursive(r->right, item);
	}
	else {

		//case 1: root has no childs - delete the root node
		if (r->left == NULL && r->right == NULL) {
			delete r;
			r = NULL;
		}

		//case 2: root has 1 child , right child.
		else if (r->left == NULL) {
			tree_node* temp = r;

			//traverse to right node
			r = r->right;

			//delete node
			delete temp;

		}

		//case 2: root has 1 child, left child
		else if (r->right == NULL) {
			
			tree_node* temp = r;
			
			//traverse to left node
			r = r->left;
			
			//delete the temp node
			delete temp;

		}
		//case 3: root has 2 children
		else {

			//find the minimum value in the right subtree
			tree_node* temp = FindMin(r->right);

			//replace current item of current root with minimum item found in right subtree
			r->item = temp->item;

			//delete the min duplicate value found in the right sub tree used to perform the swap.
			r->right = delete_node_recursive(r->right, temp->item);
		}
	}

	return r;

}

tree_node* insert_node_val(tree_node* root, Item item) {
	//if current value is null create a new node 
	if (root == NULL) {
		root = new tree_node(item, 0, 0);
	}
	//if current value is less then roots value
	else if (item < (root)->item) {

		tree_node* left_node = (root)->left;

		return insert_node_val(left_node, item);
	}

	//if current value is greater than root value
	else if (item > (root)->item) {

		tree_node* right_node = (root)->right;

		 return  insert_node_val(right_node, item);
	}

	//after all the recurrsion return the subtrees root node
	return root;
}

void insert_node(tree_node** root, Item item) {

	//if current value is null create a new node 
	if (*root == NULL) {
		*root = new tree_node(item, 0, 0);
	}
	//if current value is less then roots value
	else if( item < (*root)->item) {

		tree_node* left_node = (*root)->left;

		//root left consist of all left subtree nodes + newly inserted node
		(*root)->left = insert_node_val( left_node, item);
	}
	else if (item > (*root)->item) {

		tree_node* right_node = (*root)->right;

		//root right consist of all right subtree nodes + newly inserted node
		(*root)->right = insert_node_val( right_node, item);
	}

	//if item already exists in BST do nothing
	return;
}
int main_5_59() {

	//create a dummy tree
	tree_node* root = new tree_node(10, 0, 0);
	tree_node* t_left = root;
	tree_node* t_right = root;
	t_left = t_left->left = new tree_node(8, 0, 0);
	t_right = t_right->right = new tree_node(19, 0, 0);

	t_left->left = new tree_node(7, 0, 0);
	t_left->right = new tree_node(9, 0, 0);

	t_right->left = new tree_node(11, 0, 0);
	t_right->right = new tree_node(21, 0, 0);

	tree_traversal(root);

	std::cout << std::endl;
	tree_node* d = delete_node_recursive(root, 11);


	std::cout << std::endl;


	tree_traversal(d);
	tree_node* p = delete_node_recursive(d, 8);

	std::cout << std::endl;

	tree_traversal(p);

	return 0;
}
