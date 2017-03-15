#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
char str1[1005],str2[1005];
int dp[1005][1005];


void LCS(){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i<=len1;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<=len2;i++){
		dp[0][i] = 0;
	}
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			} else if(dp[i-1][j] > dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
			} else{ 
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	printf("%d\n",dp[len1][len2]);
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%s %s",str1,str2)!=EOF){
		LCS();
	}
	return 0;
}

