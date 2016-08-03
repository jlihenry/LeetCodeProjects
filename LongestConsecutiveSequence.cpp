#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_set<int> myset;
	for (auto num: nums) {
		myset.insert(num);
	}
	
}

int main() {
	return 0;
}