#include<stdio.h>
#include<string.h>
int main()
{
	//freopen("1.txt","r",stdin); 
	char a[1002],b[1002],c[1002];
	int lena,lenb,i,j,n,p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=0;
		scanf("%s %s",a,b);
		lena=strlen(a)-1;
		lenb=strlen(b)-1;
		for(j=0;lena>=0||lenb>=0;lena--,lenb--,j++)
		{
			if(lena>=0&&lenb>=0)
				c[j]=a[lena]+b[lenb]-'0'+p;
			if(lena>=0&&lenb<0)
				c[j]=a[lena]+p;
			if(lena<0&&lenb>=0)
				c[j]=b[lenb]+p;
			p=0;
			if(c[j]>'9')
			{
				c[j]=c[j]-10;
				p=1;
			}
		}
		printf("Case %d:\n",i+1);
		printf("%s + %s = ",a,b);
		if(p==1)
			printf("%d",p);
		for(;j>0;j--)
			printf("%c",c[j-1]);
		if(i<n-1)
			printf("\n\n");
		else printf("\n");
	}
	return 0;
}
