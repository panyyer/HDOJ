#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	int T,len,num;
	char str[10005],res[10005];
	int sum[10005];
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		len=strlen(str);
		memset(sum,0,sizeof(sum));
		num=0;
		sum[0]=1;
		res[0]=str[0];
		for(int i=1;i<len;i++){
			if(str[i]==str[i-1]){
				sum[num]++;
			} else{
				sum[++num]++;
				res[num]=str[i];
			}
		}
		for(int i=0;i<=num;i++){
			if(sum[i]!=1){
				printf("%d",sum[i]);
			}
			printf("%c",res[i]);
		}
		printf("\n");
	} 
	return 0;
}


