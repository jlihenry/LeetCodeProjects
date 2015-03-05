#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return wordBreakN(s, 0, dict);
    }
    
    vector<string> wordBreakN(string s, int pos, unordered_set<string> &dict)
    {
        vector<string> res;
        int len=s.length();
        for (int i=pos; i<len; i++)
        {
            if (dict.find(s.substr(pos, i-pos+1))!=dict.end())
            {
                vector<string> pending=wordBreakN(s, i+1, dict);
                if (i==len-1) res.push_back(s.substr(pos, i-pos+1));
                for (int j=0; j<pending.size(); j++)
                {
                    string sentence=s.substr(pos, i-pos+1)+" "+pending[j];
                    res.push_back(sentence);
                }
            }
        }
        return res;
    }
};

int main()
{
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("aaa");
	dict.insert("aaaaa");
	dict.insert("aaaaaaaa");
	dict.insert("dog"); 
	Solution s;
	vector<string> v=s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaab", dict);
	for (int i=0; i<v.size(); i++) cout << v[i] << endl; 
	return 0;
}
