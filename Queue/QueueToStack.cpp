#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
    stack<int>s1;
    stack<int>s2;
    int is_Empty(){
        return s1.empty();
    }
    int front(){
        return s1.top();
    }
    void push(int data){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        int ans=s1.top();
        s1.pop();
        return ans;
    }
};
int main(){
    Queue q;
    q.push(12);
    q.push(23);
    q.push(45);
    cout<<q.front()<<endl;

    while(!q.is_Empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}