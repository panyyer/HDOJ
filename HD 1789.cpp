#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct cla{
	int d;
	int s;
}clas[1000];
int mark[1000];
bool cmp(cla a,cla b){
	return a.s>b.s;
}

int main()
{
	int T,n,minm,sum;
	cin>>T;
	while(T--){
		minm=sum=0;
		cin>>n;
		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++){
			cin>>clas[i].d;
		}
		for(int i=0;i<n;i++){
			cin>>clas[i].s;
			sum+=clas[i].s;
		}
		sort(clas,clas+n,cmp);
		for(int i=0;i<n;i++){
			for(int j=clas[i].d;j>0;j--){
				if(!mark[j]){
					mark[j]=1;
					sum-=clas[i].s;
					break;
				}
			}
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
