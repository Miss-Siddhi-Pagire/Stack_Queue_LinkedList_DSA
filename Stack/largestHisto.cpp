#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int largestHistogram(vector<int>& heights){
    int n=heights.size();
    vector<int>left(n,0);
    vector<int>right(n,0);
    stack<int>s;
    int ans=0;
    //NGE
    for(int i=n-1;i>=0;i--){
        
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        right[i]=s.empty() ? n: s.top();
        s.push(i);
    }
        while (!s.empty()) s.pop();

    //PSE
    for(int i=0;i<n;i++){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        left[i]=s.empty() ? -1 : s.top();
        s.push(i);
    }
    for(int i=0;i<n;i++){
        int width=right[i]-left[i]-1;
        int currArea=width*heights[i];
        ans=max(ans,currArea);
    }
    
    return ans;
}
int main(){
    vector<int>height={2,1,5,6,2,3};
    cout<<largestHistogram(height);
}