#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int pre[1005],n,m;
bool vis[1005];

void init(){
	for(int i=1;i<=n;i++){
		pre[i] = i;
	}	
	memset(vis,false,sizeof(vis));
}

int find(int p){
	int root = p, t;
	while(pre[root]!=root)
		root = pre[root];
	while(pre[p]!=p){
		t = pre[p];
		pre[p] = root;
		p = t;
	}	
	return root;
}

void connect(int a, int b){
	int x = find(a), y = find(b);
	if(x!=y){
		pre[x]=y;
	}	
}

//统计连通分量 
void solve(){
	int res = 0;
	for(int i=1;i<=n;i++){
		if(pre[i]==i){
			res++;
		}
	}
	printf("%d\n",res);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T, a, b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			scanf("%d%d",&a,&b);
			connect(a,b);
		}
		solve();
	} 
	return 0;
}


