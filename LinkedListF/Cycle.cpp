#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = tail = NULL;
    }
    void push_front(int x)
    {
        Node *newNode = new Node(x);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            Node *temp = head;
            newNode->next = temp;
            head = newNode;
        }
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "LL is empty";
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    bool isCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true; // cycle detected
            }
        }
        return false; // ✅ only return false when loop ends naturally
    }
};
int main()
{
    LinkedList ll;
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_front(9);
    ll.push_front(10);
    ll.print();
    cout << endl
         << ll.isCycle();
}