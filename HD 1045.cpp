#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char map[4][4];
int num,n,t;
int visit[4][4];
int check(int x, int y){
	if(x>=n || x<0 || y>=n || y<0)
		return 0;
	if(map[x][y] == 'X')
		return 0;
	if(visit[x][y])
		return 0;
	for(int i=x-1;i>=0;i--){
		if(map[i][y] == 'X')
			break;
		if(visit[i][y])
			return 0;
	}
	for(int i=y-1;i>=0;i--){
		if(map[x][i] == 'X')
			break;
		if(visit[x][i])
			return 0;
	}
	return 1;
}
//»ØËÝ 
void dfs(int m){
	if(m>(n*n-1)){
		if(t>num)
			num=t;		
		return;

	}
	int x,y;
	x=m/n;
	y=m%n;

	if(check(x,y)){
		visit[x][y]=1;
		t++;
		dfs(m+1);
//		t--;
		visit[x][y]=0;
		t--;
		dfs(m+1);	
	} else{
		dfs(m+1);
	}
}

int main()
{
//	int n;
	void dfs(int m);
	while(scanf("%d",&n) && n!=0){
		for(int i=0;i<n;i++){
			scanf("%s",map[i]);
		}
		num=t=0;
		memset(visit,0,sizeof(visit));
		dfs(0);
		cout<<num<<endl;
	}
	return 0;
}
