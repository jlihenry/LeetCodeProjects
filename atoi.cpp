#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        int res=0, neg=1, start=0, flag=0;
        while(str[start]==' ') start++;
        if (str[start]=='-') 
        {
            neg=-1;
            start++;
        }
        else if (str[start]=='+')
        {
            neg=1;
            start++;
        }
        for (int i=start; i<str.length(); i++)
        {
            if (str[i]==' ') flag=1;
            else if (str[i]<'0'||str[i]>'9') return res*neg;
            else if (flag) return res*neg;
            else 
            {
                if (res*neg>(INT_MAX-str[i]+48)/10) return INT_MAX;
                if (res*neg<(INT_MIN+str[i]-48)/10) 
				{
					cout << res*neg << " , " << (INT_MIN+str[i])/10 << endl; 
					return INT_MIN;
				}
                res=res*10+str[i]-48;
            }
        }
        return res*neg;
    }
};

int main()
{
	Solution s;
	cout << s.atoi("-2147483647") << endl;;
	return 0;
}
