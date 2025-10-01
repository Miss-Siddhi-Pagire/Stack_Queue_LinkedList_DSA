#include <iostream>
#include <vector>
using namespace std;

void findBoundaries(vector<int> &arr) {
    int n = arr.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int ans=0;

    // Left boundary: max to the left of each index
    left[0] = arr[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], arr[i]);
    }

    // Right boundary: max to the right of each index
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }
    for(int i=0;i<n;i++){
        ans+=min(left[i],right[i])-arr[i];
    }

    // Print results
    cout << "Left boundary:  ";
    for (int i = 0; i < n; i++) cout << left[i] << " ";
    cout << endl;

    cout << "Right boundary: ";
    for (int i = 0; i < n; i++) cout << right[i] << " ";
    cout << endl;
    cout<<ans;
}

int main() {
    vector<int> arr = {2,4, 0, 3, 2, 5};
    findBoundaries(arr);
    return 0;
}
