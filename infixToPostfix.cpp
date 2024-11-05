#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static int priority(char ch)
    {
        if (ch == '^')
        {
            return 3;
        }
        if (ch == '*' || ch == '/')
        {
            return 2;
        }
        if (ch == '+' || ch == '-')
        {
            return 1;
        }
        return -1;
    }
    static string reverse(string &str)
    {
        int n = str.size();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                str[i] = ')';
            }
            else if (str[i] == ')')
            {
                str[i] = '(';
            }
        }
        return str;
    }
    static string infixToPostfix(string s)
    {
        string ans = "";
        stack<char> st;
        int i = 0;
        while (i != s.size())
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] - 48 >= 0 && s[i] - 48 <= 9)
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
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    static string infixToPrefix(string s)
    {
        reverse(s);
        int i = 0;
        string ans = "";
        stack<char> st;
        while (i != s.size())
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9')
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
                if (s[i] == '^')
                {
                    while (!st.empty() && priority(s[i]) <= priority(st.top()))
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else
                {
                    while (!st.empty() && priority(s[i]) < priority(st.top()))
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            i++;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans);
        return ans;
    }
    static string postfixToInfix(string s)
    {
        int i = 0;
        stack<string> st;
        string t1, t2;
        while (i != s.size())
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9')
            {
                string str(1, s[i]);
                st.push(str);
            }
            else
            {
                if (st.size() < 2)
                {
                    return "invalid expression";
                }
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();

                string ans = '(' + t1 + s[i] + t2 + ')';
                st.push(ans);
            }
            i++;
        }
        if (st.size() != 1)
        {
            return "invlid expression";
        }
        return reverse(st.top());
    }
    static string prefixToInfix(string s)
    {
        stack<string> st;
        int i = s.size() - 1;
        while (i >= 0)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] - 48 >= 0 && s[i] - 48 <= 9)
            {
                string str(1, s[i]);
                st.push(str);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string ans = '(' + t2 + s[i] + t1 + ')';
                st.push(ans);
            }
            i--;
        }
        return reverse(st.top());
    }
    static string postfixToPrefix(string s)
    {
        stack<string> st;
        int i = 0;
        while (i != s.size())
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] - 48 >= 0 && s[i] - 48 <= 9)
            {
                string str(1, s[i]);
                st.push(str);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string ans = s[i] + t2 + t1;
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
    static string prefixToPostfix(string s)
    {
        int i = s.size() - 1;
        stack<string> st;
        while (i >= 0)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] - 48 >= 0 && s[i] - 48 <= 9)
            {
                string str(1, s[i]);
                st.push(str);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string ans = t1 + t2 + s[i];
                st.push(ans);
            }
            i--;
        }
        return st.top();
    }
};
int main()
{
    Solution obj;
    // cout<< Solution1::myPow(2,2);
    cout << "IN TO POST : " << obj.infixToPostfix("a+b*(c^d-e)^(f+g*h)-i") << endl;
    cout << "IN TO PRE : " << obj.infixToPrefix("a+b*(c^d-e)^(f+g*h)-i") << endl;
    cout << "Post To In : " << obj.postfixToInfix("abcd^e-fgh*+^*+i-") << endl;
    cout << "Pre To IN : " << obj.prefixToInfix("-+a*b^-^cde+f*ghi") << endl;
    cout << "Post To Pre : " << obj.postfixToPrefix("abcd^e-fgh*+^*+i-") << endl;
    cout << "Pre To Post : " << obj.prefixToPostfix("-+a*b^-^cde+f*ghi") << endl;
    return 0;
}