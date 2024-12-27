#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
string PostfixToInfix(string s)
{
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
            string s3 = "";
            s3 += '(';
            s3 += s2;
            s3 += s[i];
            s3 += s1;
            s3 += ')';
            st.push(s3);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    cout << PostfixToInfix(s) << endl;
    return 0;
}