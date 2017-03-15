#include<stdio.h>
#include<string.h>
int main()
{
	char s[99];
	int len,sum1=0,sum2=0,i,m=0,n=1;
	while(1)
	{
		gets(s);
		if(strcmp(s,"end")==0)
			break;
		sum1=0,sum2=0,m=0,n=1;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(sum2==3||sum1==3)
				break;
			if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='u'||s[i]=='i')
			{
				m=1;
				sum1++;
				sum2=0;
			}
			else
			{
				sum2++;
				sum1=0;
			}
			if(i!=len-1)
				if((s[i]==s[i+1])&&(s[i]!='e' && s[i]!='o'))
					n=0;
				
		}
		if(m==1&&n==1&&sum1<3&&sum2<3)
			printf("<%s> is acceptable.\n",s);
		else printf("<%s> is not acceptable.\n",s);
	}
	return 0; 
}
