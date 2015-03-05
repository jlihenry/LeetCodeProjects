#include<iostream>
#include<stdlib.h>
using namespace std;

int compareVersion(string version1, string version2) {
    int v1=0, v2=0;
    int i=0, j=0; 
    while (version1[i]!='.' && i<version1.length()) {
    	cout << "i = " << i++ << endl;i--;
    	cout << "v1 = " << v1 << endl;
    	cout << version1[i] << endl;
    	cout << atoi(version1.c_str()+i) << endl;
    	v1=v1*10+atoi(&version1[i++]);
    }
    while (version2[j]!='.' && j<version2.length()) v2=v2*10+atoi(&version2[j++]);
    cout << "V1 = " << v1 << endl;
	cout << "V2 = " << v2 << endl; 
    if(v1>v2) return 1;
    else if(v1<v2) return -1;
    /*
    else
    {
        v1=0; v2=0;
        while (++i<version1.length()) v1=v1*10+atoi(&version1[i]);
        while (++j<version2.length()) v2=v2*10+atoi(&version2[j]);
        if (v1>v2) return 1;
        else if (v1<v2) return -1;
        else return 0;
    }
    */
    return 0;
}
int main()
{
	cout << compareVersion("01", "1") << endl; 
	return 0;
} 
