#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* head = NULL;

void push_back(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// 🔄 Reverse linked list using prev, curr, next
void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // 1️⃣ store next node
        curr->next = prev;   // 2️⃣ reverse current node's pointer
        prev = curr;         // 3️⃣ move prev forward
        curr = next;         // 4️⃣ move curr forward
    }

    head = prev;  // ✅ new head is 'prev'
}

// 📤 Print linked list
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push_back(10);
    push_back(20);
    push_back(30);
    push_back(40);

    cout << "Original: ";
    printList();

    reverse();  // 🔁 call reverse

    cout << "Reversed: ";
    printList();

    return 0;
}
