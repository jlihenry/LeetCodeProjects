class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for (int i=0; i<s.length(); i++)
        {
            if (Stack.empty()) Stack.push(s[i]);
            else
            {
                if (match(Stack.top(), s[i])) Stack.pop();
                else if (s[i]=='(' || s[i]=='[' || s[i]=='{') Stack.push(s[i]);
                else return false;
            }
        }
        if(!Stack.empty()) return false;
        else return true;
    }
    
    bool match(char i, char j)
    {
        if( (i=='(' && j==')') || (i=='[' && j==']') || (i=='{' && j=='}') ) return true;
        else return false;
    }
};
