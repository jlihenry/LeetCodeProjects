#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int maxprofit=0, localmax, i=0, sum=0;
        int profits[2][prices.size()];
        memset(profits, 0, sizeof(profits));
        
        if (k>=prices.size()/2)
        {
            for (i=1; i<prices.size(); i++) sum+=max(0, prices[i]-prices[i-1]);
            return sum;
        }
        for (i=0; i<k; i++)
        {
            localmax=prices[1]-prices[0];
            profits[i%2][1]=max(0, prices[1]-prices[0]);
            for (int j=1; j<prices.size(); j++)
            {
                profits[i%2][j]=max(max(localmax, profits[i%2][j-1]), profits[(i+1)%2][j]);
                if (j==prices.size()-1) break;
                localmax=max(localmax, profits[(i+1)%2][j-1]) + prices[j+1] - prices[j];
            }
        }
        return profits[(i+1)%2][prices.size()-1];
    }
};

int main()
{
	vector<int> l;
	l.push_back(3);
	l.push_back(2);
	l.push_back(6);
	l.push_back(5);
	l.push_back(0);
	l.push_back(3);
	Solution s;
	cout << s.maxProfit(2, l) << endl;
	return 0;
}
