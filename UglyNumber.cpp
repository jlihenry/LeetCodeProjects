#include <iostream>
using namespace std;

int nthUglyNumber(int n) {
	int *uglyNumbers = new int[n];
	uglyNumbers[0] = 1;
	int ptr2=0, ptr3=0, ptr5=0;
	for (int i=0; i<n-1; i++) {
		while (uglyNumbers[ptr2]*2 <= uglyNumbers[i]) ptr2++;
		while (uglyNumbers[ptr3]*3 <= uglyNumbers[i]) ptr3++;
		while (uglyNumbers[ptr5]*5 <= uglyNumbers[i]) ptr5++;
		uglyNumbers[i+1] = min(uglyNumbers[ptr2]*2, min(uglyNumbers[ptr3]*3, uglyNumbers[ptr5]*5));
	}
	return uglyNumbers[n-1];
}

int main() {
	for (int i=0; i<20; i++)
		cout << nthUglyNumber(i+1) << " ";
	cout << endl;
	return 0;
}