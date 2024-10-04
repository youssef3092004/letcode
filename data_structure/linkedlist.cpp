#include <iostream>
using namespace std;

class linkedlist {
    struct node {
        int data;
        node* next;
    };

    node* head;
    node* tail;

public:
    linkedlist() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void insertNode_at_head(int element) {
        node* Newnode = new node;
        Newnode->data = element;
        Newnode->next = head;
        head = Newnode;
        if (tail == NULL) {
            tail = Newnode;
        }
    }

    void insertNode_at_tail(int element) {
        node* Newnode = new node;
        Newnode->data = element;
        Newnode->next = NULL;
        if (head == NULL) {
            head = Newnode;
            tail = Newnode;
        }
        else {
            tail->next = Newnode;
            tail = Newnode;
        }
    }

    void insertNode_at_position(int element, int position) {
        if (position < 1) {
            cout << "Position must be 1 or greater." << endl;
            return;
        }
        node* Newnode = new node;
        Newnode->data = element;
        if (position == 1) {
            Newnode->next = head;
            head = Newnode;
            if (tail == NULL) {
                tail = Newnode;
            }
            return;
        }
        node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of bounds." << endl;
            delete Newnode;
            return;
        }
        Newnode->next = temp->next;
        temp->next = Newnode;
        if (Newnode->next == NULL) {
            tail = Newnode;
        }
    }

    void deleteNode_by_element(int element) {
        if (head == NULL) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        node* temp = head;
        node* perv = NULL;
        if (head->data == element) {
            head = head->next;
            delete temp;
            return;
        }
        while (temp != NULL && temp->data != element) {
            perv = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Element not found in the list." << endl;
            return;
        }
        perv->next = temp->next;
        if (temp == tail) {
            tail = perv;
        }
        delete temp;
    }

    void reverse() {
        node* perv = NULL;
        node* curr = head;
        node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = perv;
            perv = curr;
            curr = next;
        }
        head = perv;
    }

    void search(int element) {
        node* curr = head;
        int position = 1;
        while (curr != NULL && curr->data != element) {
            curr = curr->next;
            position++;
        }
        if (curr == NULL) {
            cout << "Element not found in the list." << endl;
        }
        else {
            cout << "Element found at position " << position << endl;
            cout << "the index of the element is " << position - 1 << endl;
        }
    }

    void convert_linkedlist_to_array(int arr[], int size) {
        node* curr = head;
        for (int i = 0; i < size && curr != NULL; i++) {
            arr[i] = curr->data;
            curr = curr->next;
        }
    }

    void print() {
        node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    linkedlist l;
    l.insertNode_at_head(1);    //2 6 1 4 5
    l.insertNode_at_head(2);
    l.insertNode_at_head(3);
    l.insertNode_at_tail(4);
    l.insertNode_at_tail(5);
    l.insertNode_at_position(6, 3);
    l.deleteNode_by_element(3);
    l.reverse();
    l.print();
    l.search(2);

    return 0;
}
