#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node structure
struct node {
    int data;
    struct node* next;
};

// Linked list structure with head and tail pointers
struct linkedlist {
    struct node* head;
    struct node* tail;
};

// Function to initialize the linked list
void init_list(struct linkedlist* l) {
    l->head = NULL;
    l->tail = NULL;
}

// Function to check if the linked list is empty
int isEmpty(struct linkedlist* l) {
    return l->head == NULL;
}

// Function to insert a node at the head of the list
void insertNode_at_head(struct linkedlist* l, int element) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = l->head;
    l->head = new_node;
    if (l->tail == NULL) {
        l->tail = new_node;
    }
}

// Function to insert a node at the tail of the list
void insertNode_at_tail(struct linkedlist* l, int element) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;
    if (l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }
}

// Function to insert a node at a specific position in the list
void insertNode_at_position(struct linkedlist* l, int element, int position) {
    if (position < 1) {
        printf("Position must be 1 or greater.\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = element;

    if (position == 1) {
        new_node->next = l->head;
        l->head = new_node;
        if (l->tail == NULL) {
            l->tail = new_node;
        }
        return;
    }

    struct node* temp = l->head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    if (new_node->next == NULL) {
        l->tail = new_node;
    }
}

// Function to delete a node by its value
void deleteNode_by_element(struct linkedlist* l, int element) {
    if (l->head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* temp = l->head;
    struct node* prev = NULL;

    if (l->head->data == element) {
        l->head = l->head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    if (temp == l->tail) {
        l->tail = prev;
    }
    free(temp);
}

// Function to reverse the linked list
void reverse(struct linkedlist* l) {
    struct node* prev = NULL;
    struct node* curr = l->head;
    struct node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l->head = prev;
}

// Function to search for an element in the list
void search(struct linkedlist* l, int element) {
    struct node* curr = l->head;
    int position = 1;
    while (curr != NULL && curr->data != element) {
        curr = curr->next;
        position++;
    }
    if (curr == NULL) {
        printf("Element not found in the list.\n");
    } else {
        printf("Element found at position %d\n", position);
        printf("The index of the element is %d\n", position - 1);
    }
}

// Function to get the size of the linked list (renamed from gitsize)
int getLinkedListSize(struct linkedlist* l) {
    struct node* temp = l->head;
    int size = 0;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

// Function to convert the linked list to an array
int* convert_linkedlist_to_array(struct node* head) {
    int size = getLinkedListSize(&head); // Get the size of the linked list
    int* arr = (int*)malloc(size * sizeof(int)); // Dynamically allocate memory for the array
    
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    struct node* curr = head;
    for (int i = 0; i < size && curr != NULL; i++) {
        arr[i] = curr->data; // Copy linked list data to array
        curr = curr->next;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return arr; // Return the dynamically allocated array
}

// Function to print the elements of the linked list
void print(struct linkedlist* l) {
    struct node* temp = l->head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the linked list functions
int main() {
    struct linkedlist l;
    init_list(&l);

    insertNode_at_head(&l, 1);
    insertNode_at_head(&l, 2);
    insertNode_at_head(&l, 3);
    insertNode_at_tail(&l, 4);
    insertNode_at_tail(&l, 5);
    insertNode_at_position(&l, 6, 3);

    deleteNode_by_element(&l, 3);
    reverse(&l);
    convert_linkedlist_to_array(l.head);
    print(&l);

    search(&l, 2);

    return 0;
}
