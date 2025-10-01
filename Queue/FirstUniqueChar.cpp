#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstUniqueChar(string str) {
    queue<int> q;
    unordered_map<char, int> mp;

    for (int i = 0; i < str.size(); i++) {
        mp[str[i]]++;               // increment character frequency

        if (mp[str[i]] == 1) {      // push index only first time
            q.push(i);
        }

        // Remove indices from the front if that character is no longer unique
        while (!q.empty() && mp[str[q.front()]] > 1) {
            q.pop();
        }
    }

    // If queue is empty => no unique character
    return q.empty() ? -1 : q.front();
}

int main() {
    string str = "level";
    int idx = firstUniqueChar(str);
    if (idx == -1)
        cout << "No unique character found";
    else
        cout << "First unique character is '" << str[idx] << "' at index " << idx;
    return 0;
}
