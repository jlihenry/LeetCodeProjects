#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int start=0, step;
        if (n) k=k%n;
        if (k) 
        {
            step=(k-(n-1)%k)%k;
        }
        cout << "step = " << step << endl;
        for (start=0; start<k; start+=step)
        {
            int anchor=start;
	int record=nums[anchor];
            cout << "start = " << start << endl;
            do 
            {
                anchor=(anchor+k)%n;
                int tmp=nums[anchor];
                nums[anchor]=record;
                record=tmp;
            } while (anchor != start);
            if (step==0) break;
        }
    }
};

int main()
{
	Solution s;
	int a[54];
	for (int i=1; i<55; i++) a[i-1]=a[i];
	s.rotate(a, 54, 45);	
}
