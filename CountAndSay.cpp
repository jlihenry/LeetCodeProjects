#include <iostream>
using namespace std;

string countAndSay(int n) {
    string seq="1", result="";
    int count=0, prev;
    for (int i=1; i<n; i++)
    {
        prev=seq[0]-48;
        for (int j=0; j<seq.length(); j++)
        {
            int curr=seq[j]-48;
            if (curr==prev) count++;
            else
            {
                result.push_back('0'+count);
                result.push_back('0'+prev);
                prev=curr;
                count=1;
            }
        }
        result.push_back('0'+count);
        result.push_back('0'+prev);
        seq=result;
        result="";
        count=0;
    }
    return seq;
}
    
int main()
{
	cout << countAndSay(3) << endl;
	return 0;
}
