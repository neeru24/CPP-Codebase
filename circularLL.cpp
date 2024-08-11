#include <iostream>

using namespace std;

// Define the Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

// Function to check if the linked list is circular
bool isCircular(Node* head) {
    if (head == NULL) return true; // Consider an empty list as circular

    Node* temp = head->next; // Start traversal from the node after head

    // Traverse the list to check if we can reach head again
    while (temp != NULL && temp != head) {
        temp = temp->next; // Move to the next node
    }

    // If we have reached head again, the list is circular
    return temp == head;
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "List: ";

    Node* start = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;

        // Stop if we return to the starting node in a circular list
        if (temp == start) {
            cout << "(back to head)" << endl;
            return;
        }
    }
    cout << "NULL" << endl;
}

// Function to append a new node to the list
void appendNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to create a circular link
void createCircular(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Create the circular link
    temp->next = head;
}

// Function to delete the list
void deleteList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    Node* nextNode;

    // Traverse the list and delete nodes
    while (temp->next != head) {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    // Delete the last node
    delete temp;
}

int main() {
    Node* head = NULL;

    // Insert elements into the list
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 3);

    // Uncomment to create a circular link
    createCircular(head);

    // Print the list
    printList(head);

    // Check and print if the list is circular
    bool circular = isCircular(head);
    if (circular) {
        cout << "The list is circular." << endl;
    } else {
        cout << "The list is not circular." << endl;
    }

    // Clean up
    deleteList(head);

    return 0;
}
