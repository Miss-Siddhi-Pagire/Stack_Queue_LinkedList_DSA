#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void StockSpan(vector<int> &prices)
{
    int n = prices.size();
    stack<int> st;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && prices[st.top()] <= prices[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - st.top();
        }
        st.push(i);
    }
    for (int val : ans)
    {
        cout << val << endl;
    }
}
int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    StockSpan(prices);
}