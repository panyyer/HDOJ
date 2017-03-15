#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int m[100];
struct act{
	int s;
	int e;
}a[100];
int main()
{
	int n,num,j;
	int cmp(act i, act j);
	while(1){
		num=1;
		j=0;
		memset(m,0,100*sizeof(int));
		memset(a,0,100*sizeof(act));
	//	memset(e,0,100*sizeof(int));
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			scanf("%d %d",&a[i].s,&a[i].e);
		}
		sort(a, a+n, cmp);
//		for(int i=0;i<n;i++)
//			cout<<a[i].s<<" "<<a[i].e<<endl;exit;
		for(int i=1;i<n;i++){
			if(a[i].s>=a[j].e){
				num++;
				j=i;
			}
		}
		cout<<num<<endl;
		num=0;
	}
	return 0;
}
int cmp(act i, act j){
	return i.e<j.e;
//	if(i.e<j.e) return -1;
//	else if(i.e==j.e) return 0;
//	else return 0;
}
