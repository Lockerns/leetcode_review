#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            st.push(')');
        else if (s[i] == '[')
            st.push(']');
        else if (s[i] == '{')
            st.push('}');
        else if (st.empty() || st.top() != s[i])
            return false;
        else st.pop();
    }
    return st.empty();
}

int main()
{
    string s = "()[]{}[";
    if (IsValid(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}