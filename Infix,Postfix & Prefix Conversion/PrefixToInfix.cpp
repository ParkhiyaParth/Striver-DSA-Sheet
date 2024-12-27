#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
string PrefixToInfix(string s)
{
    // Write your code here
    int n = s.size();
    stack<string> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string s3 = '(' + s1 + s[i] + s2 + ')';
            st.push(s3);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    cout << PrefixToInfix(s) << endl;
    return 0;
}