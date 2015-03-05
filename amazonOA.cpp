#include <iostream>
#include <string.h>
using namespace std;

int isRotateString( char* word1, char* word2 )
{
// return 1 if they are rotated, -1 if not
	int len1=strlen(word1), len2=strlen(word2), count=0;
	if (len1!=len2) return -1;
	if (len1==0 && len2==0) return 1;
	for (int i=0; i<len1; i++)
	{
		int tmp=i;
		if (word1[i]==word2[0])
		{
			count=0;
			while (count<len2)
			{
				if (word1[i]!=word2[count]) break;
				i=(++i)%len1;
				count++;
			}
			if (count==len2) return 1;
		}
		i=tmp;
	}
	return -1;
}

int* selectionSortArray(int *array, int len){
    int x=0, y =0;
    for(x=0; x<len; x++){
       int index_of_min = x;
       for(y=x; y<len; y++){
          if(array[index_of_min]>array[x]){
             index_of_min = y;
          }
       }
       int temp = array[x];
       array[x] = array[index_of_min];
       array[index_of_min] = temp;
    }
    return array;
}

char* removeVowels(char* string)
{
	char vowels[5]={'a','e','i','o','u'};
	char* res=new char[strlen(string)];
	char* sub = strtok(string, vowels);
	int pos=0;
	while (sub)
	{
		strncpy(res+pos, sub, strlen(sub));
		pos += strlen(sub);
		sub=strtok(NULL, vowels);
	}
	return res;
	
}

int main()
{
	cout << isRotateString("\0", "\0") << endl;
	cout << "Next\n";
	//cout << removeVowels("hello") << endl;
	//char* s="hello";
	//char* ok=strtok(s, "l");
	//cout << s << endl;
	int array[6] = {3,42,34,45,11,23};
	int *a=&(array[0]);
	array = selectionSortArray(a, 4);
	for (int i=0; i<6; i++) cout << array[i] << endl;
	return 0;
}
