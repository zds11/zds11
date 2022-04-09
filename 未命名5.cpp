#include<stdio.h>
#include<string.h>
int main()
{
	char strExp[]="2+2*3+2/2-1";
	char strTmp[strlen(strExp)];
	int T=-1;
	for(int i=0;i<strlen(strExp);i++)
	{
		if(strExp[i]=='*')
		{
			int l=strTmp[T]-'0';
			int r=strExp[i+1]-'0';
			strTmp[T]=l*r+'0';
			i++;
		}
		else if(strExp[i]=='/')
		{
			int l=strTmp[T]-'0';
			int r=strExp[i+1]-'0';
			strTmp[T]=l/r+'0';
			i++;
		}
		else strTmp[++T]=strExp[i];
	}
	int res=strTmp[0]-'0';
	for(int i=1;i<strlen(strExp);i++)
	{
		if(strTmp[i]=='+')
		{
			res+=strTmp[++i]-'0';
		}
		else if(strTmp[i]=='-')
		{
			res-=strTmp[++i]-'0';
		}
		
	}
	printf("%d",res);
	return 0;
}