class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i = 0;
        string result = "";
        while (i<path.length())
        {
            int index = path.find("/", i);
            if (index==-1) index=path.length();
            if (index == 0)
            {
                i++;
                continue;
            }
            else
            {
                string sub = path.substr(i, index-i);
                i = index + 1;
                if (sub=="." || sub=="") continue;
                else if (sub=="..")
                {
                    if (s.empty()) continue;
                    else s.pop();
                }
                else
                {
                    s.push(sub);
                }
            }
        }
        
        if (s.empty()) return "/";
        else
        {
            while (!s.empty())
            {
                result = ("/"+s.top()) + result;
                s.pop();
            }
            return result;
        }
    }
};
