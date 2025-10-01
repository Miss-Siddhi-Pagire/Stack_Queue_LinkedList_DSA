#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node( int val ){
        data=val;
        next=NULL;
    }
};
class Queue{
    Node*head;
    Node*tail;
    public:
        Queue(){
            head=tail=NULL;
        }
        bool is_Empty(){
            return head==NULL;
        }
        int empty(){
            return is_Empty();
        }
        int front(){
            if(empty()){
                cout<<"Queue is Empty";
                return -1;
            }
            else{
                return head->data;
            }
        }
        void push(int data){
            Node*newNode= new Node(data);
            if(empty()){
                head=tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        void pop(){
            if(empty()){
                cout<<"Queue is Empty";
            }
            else{
                Node*temp=head;
                head=head->next;
                delete temp;

            }
            
        }


};
int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

     while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
   
    cout << "Front: " << q.front() << endl; // 10
    q.pop();
    cout << "Front after pop: " << q.front() << endl; // 20

    //q.pop();
    //q.pop();
    //q.pop(); // Queue is Empty

    return 0;
}
