#include<iostream>
#include<vector>
#include<string>
using namespace std;

int stringCompression(vector<char>&arr){
    int n=arr.size();
    int idx=0;
    for(int i=0;i<n;i++){
        char ch=arr[i];
        int count=0;
        while(i<n && arr[i]==ch){
            i++;
            count++;
        }
        if(count==1){
            arr[idx++]=ch;
        }
        else{
            arr[idx++]=ch;
            string str = to_string(count);
            for(char dig:str){
                arr[idx++]=dig;
            }
        }
        i--;
    }
    for(int i=0;i<idx;i++){
        cout<<arr[i];
    }
   
}
int main(){
    vector<char>arr={'a','a','b','b','c','c','c'};
    cout<<stringCompression(arr);
}