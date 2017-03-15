#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,num,t,s,e,maxn,c[201];
	cin>>n;
	while(n--){
		memset(c,0,201*sizeof(int));
		cin>>num;
		maxn=0;
		for(int i=0;i<num;i++){
			scanf("%d%d", &s, &e);	
			if(s>e){
				t=s;
				s=e;
				e=t;
			}
			s=(s+1)/2;
			e=(e+1)/2;
			for(int i=s;i<=e;i++){
				c[i]++;
				if(c[i]>maxn)
					maxn=c[i];
			}
		}
		cout<<maxn*10<<endl;
	}
	return 0;	
}

