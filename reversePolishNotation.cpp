#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int a, b;
        
        if (tokens.empty()) return 0;
        for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++)
        {
            string token = *it;
            switch (token[0])
            {
            case '+':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a+b);
                break;
            case '-':
                if (token.length() > 1) 
                {
                	s.push(atoi(token.c_str()));
                	break;
                }
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b-a);
                break;
            case '*':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a*b);
                break;
            case '/':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b/a);
                break;
            default:
            	cout << token << endl;
                s.push(atoi(token.c_str()));
                break;
            }
        }
        return s.top();
    }
};

int main()
{
	vector<string> v;
	v.push_back("3");
	v.push_back("-4");
	v.push_back("+");
	Solution s;
	s.evalRPN(v);
	return 0;
} 
