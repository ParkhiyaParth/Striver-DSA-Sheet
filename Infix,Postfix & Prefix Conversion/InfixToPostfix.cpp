#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int pre(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string InfixToPostfix(string s)
{
    int n = s.size();
    stack<char> st;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] >= '0' && s[i] <= '9')
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && pre(s[i]) <= pre(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    if (!st.empty())
    {
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << InfixToPostfix(s) << endl;
    return 0;
}