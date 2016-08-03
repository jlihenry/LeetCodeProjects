#include <iostream>
#include <math.h>
using namespace std;

int numSquares(int n) {
	if (n<=1) return 1;
	int *opt = new int[n];
	memset(opt, 0, n*sizeof(int));
	opt[0] = 1;
	for (int i=2; i<=n; i++) {
		int square_root = (int)sqrt(i);
		cout << "i is " << i << endl;
		if (i == square_root*square_root) opt[i-1] = 1;
		else {
			opt[i-1] = opt[i-2] + 1;
			for (int j=square_root; j>=1; j--) {
				opt[i-1] = min(opt[i-1], 1+opt[i-j*j-1]);
			}
		}
	}
	return opt[n-1];
}

int main() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	cout << numSquares(num) << endl;
	return 0;
}