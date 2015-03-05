#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s)
{
	char *lastword;
	int i=0;
	if (s==NULL || strlen(s)==0) return 0;
	while (s[i]==' ') s++;
	int len=strlen(s);
	printf("beginning len = %d\n", len);
	lastword = strtok(s, " ");
	if (lastword!=NULL) printf("----%s\n", lastword);
	else printf("NULL\n");
	while (lastword!=NULL)
	{
		printf("--%s\n", lastword);
		len=strlen(lastword)-1;
		lastword=strtok(NULL, " ");
	}
	return len;
}
int main()
{
	char *lastword="a";
	printf("Length of last word is %d\n", lengthOfLastWord(lastword));
	return 0;
}
