#include <iostream>
#include <stack>
using namespace std;

class Minstack
{
public:
    stack<pair<int, int>> s;
    void pushVal(int val)
    {
        if (s.empty())
        {
            s.push({val, val});
        }
        else
        {
            int minval = min(val, s.top().second);
            s.push({val, minval});
        }
    }
    void pop()
    {
        s.pop();
    }
    int getTop()
    {
        return s.top().first;
    }
    int getMin()
    {
        return s.top().second;
    }
};
int main()
{
    Minstack ms;
    ms.pushVal(-2);
    ms.pushVal(0);
    ms.pushVal(-3);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getTop() << endl;
    cout << ms.getMin() << endl;
}