#include <iostream>
using namespace std;

string units[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string tens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string number[3] = {"Thousand", "Million", "Billion"};

string convertThree(int num) {
	string res = "";
	int hundreds = num/100;
	if (num-hundreds*100 < 20) {
		res = units[num-hundreds*100];
	}
	else {
		int ten = (num - hundreds*100)/10;
		int unit = num - hundreds*100 - ten*10;
		if (unit != 0) res = tens[ten-2] + " " + units[unit];
		else res = tens[ten-2];
	}
	if (hundreds > 0) {
	    if (num-hundreds*100 != 0) res = units[hundreds] + " Hundred " + res;
	    else res = units[hundreds] + " Hundred";
	}
	return res;
}

string numberToWords(int num) {
	string res = "";
	if (num == 0) return "Zero";
	int order = -1;
	do {
		int threeDigits = num%1000;
		num = num/1000;
		if (threeDigits == 0) {
		    order++;
		    continue;
		}
		if (order == -1) res = convertThree(threeDigits);
		else res = convertThree(threeDigits) + " " + number[order] + (res==""?"":" "+res);
		order++;
	} while (num > 0);
	return res;	
}

int main() {
	cout << numberToWords(123123) << endl;
	return 0;
}