#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> NG(n); // store results
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        // Assign next greater element
        if (st.empty()) {
            NG[i] = -1;
        } else {
            NG[i] = st.top();
        }
        // Push current element for next iteration
        st.push(arr[i]);
    }

    return NG;
}

vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> NG(n); // store results
    stack<int> st;

    for (int i = 0; i <n; i++) {
        // Pop smaller or equal elements
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        // Assign next greater element
        if (st.empty()) {
            NG[i] = -1;
        } else {
            NG[i] = st.top();
        }
        // Push current element for next iteration
        st.push(arr[i]);
    }

    return NG;
}


int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> result = nextGreater(arr);
vector<int> result2 = prevSmaller(arr);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Previous smaller Elements: ";
    for (int x : result2) {
        cout << x << " ";
    }
    

    return 0;
}
