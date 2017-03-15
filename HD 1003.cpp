/*
´ýÓÅ»¯ 
*/ 
#include<stdio.h>
int main()
{
//	freopen("1.txt","r",stdin);
	int times,num,sum,i=0,first,max,end,n=1;
	int a[100002];
	scanf("%d",&times);
	getchar();
	while(times--)
	{
		max=0;
		first=end=0;
		scanf("%d",&num);
		for(i=0;i<num;i++)
			scanf("%d",&a[i]);
		printf("Case %d:\n",n);
		n++;
		max=sum=a[0];
		for(i=1;i<num;i++)
		{
			sum=sum+a[i];
			if(sum>max)
			{
				max=sum;
				end=i;
			}
			if(a[i]>max)
			{
				max=a[i];
				sum=a[i];
				end=i;
			}
			if(a[i]>sum)
				sum=a[i];
		}
		sum=0;
		for(i=end;i>=0;i--)
		{
			sum=sum+a[i];
			if(sum>=max)
			{
				max=sum;
				first=i;
			}
		}
		printf("%d %d %d\n",max,first+1,end+1);
		if(times!=0)
			printf("\n");
	}
	return 0;
} 
