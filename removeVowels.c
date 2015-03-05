#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* removeVowels(char* string)
{
	char vowels[5]={'a','e','i','o','u'};
	char* res=(char*)malloc(sizeof(char)*strlen(string));
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

/*int main()
{
	printf("result is %s\n", removeVowels("hello"));
	return 0;
}*/
void re(char* stir)
{
  //char str[] ="- This, a sample string."i;
  printf("%s\n", stir);
  char *str=(char*)malloc(sizeof(char)*strlen(stir));
  strcpy(str, stir);
  char * pch;
  char *res = (char*)malloc(sizeof(char)*strlen(str));
  int pos=0;
  //printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str,"aeiou");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
	strncpy(res+pos, pch, strlen(pch));
	pos+=strlen(pch);
    pch = strtok (NULL, "aeiou");
  }
  //printf("result is %s\n", removeVowels("hello"));
  printf("result = %s\n", res);
  //return 0;
}

int main()
{
	re("hello");
}
