#include <iostream>
#include "tree_node.h"



tree_node* FindMin2(tree_node* root) {

	//if there are no nodes in the left subtree, root is the min
	if (root->left == NULL) {
		return root;
	}

	//if left subtree is not empty, continue to traverse left subtree until null is found
	else {
		return FindMin2(root->left);
	}
}


tree_node* delete_node_recursive_key(tree_node* r, Item item) {
	
	//traverse tree and delete leaves with value equal to item.

	tree_node* t = r;

	//if tree is empty return null
	if (r == NULL) {
		return r;
	}
	else {
		//traverse both left subtree and right subtree until items are found in tree
		r->left = delete_node_recursive_key(r->left, item);
		r->right = delete_node_recursive_key(r->right, item);
	}


	if (r->item == item)
	{

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
			tree_node* temp = FindMin2(r->right);

			//replace current item of current root with minimum item found in right subtree
			r->item = temp->item;

			//delete the min duplicate value found in the right sub tree used to perform the swap.
			r->right = delete_node_recursive_key(r->right, temp->item);

		}
	}

	return r;

}

int test_function() {

	//create a dummy tree
	tree_node* root = new tree_node(10, 0, 0);
	tree_node* t_left = root;
	tree_node* t_right = root;
	t_left = t_left->left = new tree_node(4, 0, 0);
	t_right = t_right->right = new tree_node(19, 0, 0);

	t_left->left = new tree_node(10, 0, 0);
	t_left->right = new tree_node(6, 0, 0);
	t_left->right->right = new tree_node(7, 0, 0);
	t_left->right->left = new tree_node(10, 0, 0);

	t_right->left = new tree_node(18, 0, 0);
	t_right->right = new tree_node(21, 0, 0);
	t_right->right->left = new tree_node(20, 0, 0);

	tree_traversal(root);
	std::cout << std::endl;
	tree_node* t = delete_node_recursive_key(root, 10);
	//case unbalanced tree 5 nodes
	tree_traversal(t);


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
	tree_node* root3 = new tree_node(10, 0, 0);
	tree_node* t_left3 = root3;

	t_left3 = t_left3->left = new tree_node(4, 0, 0);
	t_left3 = t_left3->left = new tree_node(5, 0, 0);

	//case single subtree 

	return 0;

}

tree_node* construct_tournament_tree(int *a,int l, int r)
{
	//construct a tournament tree compare 2 children, the larger of the 2 children is set as current node

	int m = (l + r) / 2;
	
	tree_node* x = new tree_node(a[m],0,0);

	if (l == r) {
		return x;
	}

	x->left = construct_tournament_tree(a, l, m);
	x->right = construct_tournament_tree(a, m + 1, r);

	int u = x->left->item, v = x->right->item;

	if (u > v) {
		x->item = u;
	}
	else {
		x->item = v;
	}

	return x;

}


int main_5_91() {
	int a[] = { 0,1,2,3,4,5 };
	tree_node* t = construct_tournament_tree(a, 0, 5);

	tree_traversal(t);

	std::cout << std::endl;

	t = delete_node_recursive_key(t, 5);

	std::cout << std::endl;
	tree_traversal(t);
	return 0;
}