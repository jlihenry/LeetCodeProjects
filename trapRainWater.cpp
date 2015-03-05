#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n==0) return 0;
        int tallest = 0, localTallest = 0, rain = 0, rainRollBack = 0;
        
        for (int i=0; i<n; i++)
        {
        	if (A[i]>=tallest)
        	{
        		cout << "tallest = " << tallest << endl;
        		tallest = A[i];
        		rainRollBack = rain;
        		cout << "tallest upadated = " << tallest << endl;
        		
        	}
        	else 
        	{
        		rain += tallest - A[i];
        	}
        }
        
        cout << "rain = " << rain << endl;
        cout << "rain roll back = " << rainRollBack << endl;
        int i = n - 1;
        while (A[i]!=tallest)
        {
        	if (A[i]>=localTallest) localTallest = A[i];
        	else rainRollBack += localTallest - A[i];
        	i--;
        	rain = rainRollBack;
        }
        
        return rain;
    }
};

int main()
{
	Solution s;
	int list[] = {4,2,3};
	cout << s.trap(list, 3);
	return 0;
} 
