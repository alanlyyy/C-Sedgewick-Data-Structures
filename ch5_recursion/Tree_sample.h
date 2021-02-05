#pragma once


template<class Item>
class Binary_Tree {
	
private:
	struct tree_node {
		Item item;
		tree_node* prev_node;
		tree_node* left;
		tree_node* right;

		tree_node(Item i, tree_node* p, tree_node* l, tree_node* r) {
			item = i;
			prev_node = p;
			left = l;
			right = r;
		}
	};

	typedef tree_node* link;

	tree_node* root;

	Binary_Tree(Item item) {
		root = new tree_node(item, 0, 0, 0);
	}

public:

	void insert_node(Item item) {

		tree_node* t = root;

		//if current item less than root
		if (t->item >= item) {
			insert_node(item, t->left);
		}
		else {
			insert_node(item, t->right);
		}
	}

	void insert_node(Item item, tree_node* current_node) {

		node* t = current_node;
		
		if (t->item >= item) {
			insert_node(item, t->left);
		}
		else {
			insert_node(item, t->right);
		}


	}

};