#include<iostream>
#include<queue>
using namespace std;

class Stack{
    public:
    queue<int>q1;
    queue<int>q2;

    bool isEmpty(){
        return q1.empty();
    }
    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        } 
    }
    int front(){
        return q1.front();
    }
    int pop(){
        int ans=q1.front();
        q1.pop();
        return ans;
    }

};
int main(){
    Stack sc;
    sc.push(12);
    sc.push(13);
    sc.push(14);
    cout<<sc.front();
    while(!sc.isEmpty()){
        cout<<sc.front()<<" ";
        sc.pop();
    }
}