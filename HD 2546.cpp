#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[1001];
int v[1001]={0};
int main()
{
	int num,m,maxn;
	while(1){
		memset(dp,0,1001*sizeof(int));
		cin>>num;
		if(num == 0) break;
		for(int i=1;i<=num;i++)
				cin>>v[i];
		cin>>m;
		sort(v+1,v+num+1);
		maxn = v[num];

		if(m>=5){
			m-=5;		
			for(int i=1;i<num;i++){
				for(int j=m;j>=v[i];j--){
					dp[j] = max(dp[j], dp[j-v[i]] + v[i]);
				}
			}
			cout<<m+5-dp[m]-maxn<<endl;	
		}
		else cout<<m<<endl;
	}

	return 0;
} 


