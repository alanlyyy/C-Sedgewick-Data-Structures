#include "Node.h"
#include <iostream>

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list*/
void sortedInsert(struct node** head_ref, struct node* new_node)
{
	
	struct node* current;

	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->item >= new_node->item)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL &&
			current->next->item < new_node->item)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}

}
// function to sort a singly linked list using insertion sort 
void insertionSort(struct node** head_ref)
{
	// Initialize sorted linked list 
	struct node* sorted = NULL;

	// Traverse the given linked list and insert every 
	// node to sorted 
	struct node* current = *head_ref;
	while (current != NULL)
	{
		// Store next for next iteration 
		struct node* next = current->next;

		// insert current in sorted linked list 
		sortedInsert(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}



int main_3_41() {

	node headera(0, 0);
	link rand_list = generate_random_nodes(10, &headera);

	//make a copy of randlist to pass into sorted_list no header node
	link ref = rand_list;

	print_nodes(ref);
	std::cout << "-------------------" << std::endl;

	link output_list = 0;
	insertionSort2(&ref);

	print_nodes(ref);
	return 0;
}
