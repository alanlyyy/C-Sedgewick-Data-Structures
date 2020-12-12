//example of list of nodes without head pointer
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int val) {
    struct node* new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = val;
    if (*head)
        new1->next = *head;
    *head = new1;

}

void print_list(struct node* list) {
    while (list) {
        printf("%d\n", list->data);
        list = list->next;
    }
}

int main(void)
{
    struct node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    print_list(head);

    return 0;
}