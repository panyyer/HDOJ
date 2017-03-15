#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int pre[100005];
bool vis[100005], flag; //flag判断是否存在环 

void init(){
	for(int i=1;i<100005;i++){
		pre[i] = i;
	}
	flag = false;
	memset(vis,false,sizeof(vis));
}

int find(int p){
	int root = p, t;
	while(pre[root]!=root){
		root = pre[root];
	}
	while(pre[p]!=p){   // 尽可能简便地缩短树的高度  
		t = pre[p];
		pre[p] = root;
		p = t;
	}	
	return root;
}

void connect(int a, int b){
	vis[a] = vis[b] = true;
	int x = find(a), y = find(b);
	if(x==y){
		flag = true;
	} else{
		pre[x] = y;
	}
}

int main()
{
//	freopen("input.txt","r",stdin); 
	int a, b;
	init();
	while(scanf("%d%d",&a,&b) && a+b>-1){
		if(a==0){
			int num = 0;
			for(int i=1;i<100005;i++){
				if(vis[i] && pre[i]==i){
					num++;
				}
			}
			if(flag || num>1){
				printf("No\n");
			} else{
				printf("Yes\n");
			} 
			init();
		} else{
			connect(a,b);
		}
	} 
	return 0;
}
