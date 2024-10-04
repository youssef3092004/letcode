#include <iostream>
using namespace std;

class double_linkedlist {
    struct node {
        int data;
        node* next;
        node* perv;
    };

    node* head;
    node* tail;

public:
    double_linkedlist() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void insertNode_at_head(int element) {
        node* Newnode = new node;
        Newnode->data = element;
        if (isEmpty()) {
            Newnode->next = NULL;
            Newnode->perv = NULL;
            head = Newnode;
            tail = Newnode;
        } else {
            Newnode->next = head;
            head->perv = Newnode;
            Newnode->perv = NULL;
            head = Newnode;
        }
    }

    void insertNode_at_tail(int element) {
        node* Newnode = new node;
        Newnode->data = element;
        Newnode->next = NULL;
        Newnode->perv = tail;
        if (tail != NULL) {
            tail->next = Newnode;
        } else {
            head = Newnode;
        }
        tail = Newnode;
    }

    void insertNode_at_position(int element, int position) {
        if (position < 1) {
            cout << "Position must be 1 or greater." << endl;
            return;
        }
        if (position == 1) {
            insertNode_at_head(element);
            return;
        }
        node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
            if (temp == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }
        }
        node* Newnode = new node;
        Newnode->data = element;
        Newnode->next = temp->next;
        Newnode->perv = temp;
        temp->next = Newnode;
        if (Newnode->next != NULL) {
            Newnode->next->perv = Newnode;
        } else {
            tail = Newnode;
        }
    }

    void deleteNode(int element) {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        node* temp = head;
        while (temp != NULL && temp->data != element) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Element not found in the list." << endl;
            return;
        }
        if (temp == head) {
            head = head->next;
            if (head != NULL) {
                head->perv = NULL;
            } else {
                tail = NULL;
            }
        } else if (temp == tail) {
            tail = tail->perv;
            tail->next = NULL;
        } else {
            temp->perv->next = temp->next;
            temp->next->perv = temp->perv;
        }
        delete temp;
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

// Add the main function here
int main() {
    double_linkedlist list;
    list.insertNode_at_head(5);
    list.insertNode_at_tail(10);
    list.insertNode_at_tail(15);
    list.insertNode_at_position(7, 2);
    
    cout << "Initial list: ";
    list.print();

    list.deleteNode(7);
    cout << "After deleting 7: ";
    list.print();

    list.deleteNode(15);
    cout << "After deleting 15: ";
    list.print();

    return 0;
}
