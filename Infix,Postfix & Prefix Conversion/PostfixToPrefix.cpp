#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
string PostfixToPrefix(string s)
{
    // Write your code here
    int n = s.size();
    stack<string> st;
    for (int i = 0; i < n; i++)
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
            string s3 = s[i] + s2 + s1;
            st.push(s3);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    cout << PostfixToPrefix(s) << endl;
    return 0;
}