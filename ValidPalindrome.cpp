#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isValid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (!isValid(s[start])) { start ++; continue; }
            if (!isValid(s[end])) { end --; continue; }
            if (s[start] != s[end] && abs(s[start] - s[end]) != 32) return false;
            start ++;
            end --;
        }
        return true;
    }
};

int main()
{
	Solution s;
	cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;;
	return 0;
}
