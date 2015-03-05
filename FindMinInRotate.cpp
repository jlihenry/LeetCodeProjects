#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int n=num.size();
        int start=0, end=n-1, pivot=(n-1)/2;
        while (start<end-1)
        {
            pivot=(start+end)/2;
            if (num[pivot]>num[end]) start=pivot;
            else end=pivot;
        }
        return min(num[end], num[start]);
    }
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	cout << s.findMin(v) << endl;
	return 0;
} 
