#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int node[4*200000+5];
int max(int a, int b){
	return a>b?a:b;
}
void build(int st, int en, int now){
	if(st==en){
		scanf("%d",&node[now]);
		return;
	}
	int mid = (st+en)>>1;
	build(st,mid,now<<1);
	build(mid+1,en,now<<1|1);
	node[now] = max(node[now<<1],node[now<<1|1]);
}

int query(int st, int en, int a, int b, int now){
	if(st>=a && en<=b){
		return node[now];
	}
	int mid=(st+en)>>1;
	int res=0;
	if(mid<b){
		res=max(res,query(mid+1,en,a,b,now<<1|1));
	} 
	if(mid>=a){
		res=max(res,query(st,mid,a,b,now<<1));
	}
	return res;
}

void update(int st, int en, int a, int b, int now){
	if(st==en){
		node[now]=b;
		return;
	}
	int mid=(st+en)>>1;
	if(mid<a){
		update(mid+1,en,a,b,now<<1|1);
	} else{
		update(st,mid,a,b,now<<1);
	}
	node[now] = max(node[now<<1],node[now<<1|1]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int m,n,a,b;
	char c[10];
	while(scanf("%d%d",&n,&m)!=EOF){
		build(1,n,1);
		while(m--){
			scanf("%s",c);
			scanf("%d%d",&a,&b);
			if(c[0]=='Q'){
				printf("%d\n",query(1,n,a,b,1));
			} else{
				update(1,n,a,b,1);
			}
		}
	} 
	return 0;
}

