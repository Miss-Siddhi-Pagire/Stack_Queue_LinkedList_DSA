#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class LinkedList{
    public:
    Node*head;
    Node*tail;
    LinkedList(){
        head=tail=NULL;
    }
    void push_front(int data){
        Node*newNode = new Node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node*newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void printLL(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void pop_front(){
        if(head==NULL){
            cout<<"It  is empty";
        }
        else{
            Node*temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(head==NULL){
            cout<<"It is empty";
        }
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node*temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            
            }
            delete tail;
            tail=temp;
            tail->next=NULL;  
        }
    }
    int search(int key){
        Node*temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
};
int main(){
    LinkedList ll;
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_back(4);
    ll.push_back(18);
    cout<<ll.search(2)<<endl;
    ll.pop_front();
    ll.pop_back();
    ll.printLL();

}