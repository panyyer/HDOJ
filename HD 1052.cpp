#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int tian[1000];
int king[1000];
int main()
{
	int n,m,ta,tb,ka,kb;
	while(cin>>n){
		if(n==0) break;
		m=0;
		for(int i=0;i<n;i++){
			cin>>tian[i];
		}
		for(int i=0;i<n;i++){
			cin>>king[i];
		}
		sort(tian,tian+n);
		sort(king,king+n);
		ta=ka=n-1;
		tb=kb=0;
		while(n--){
			if(tian[ta] > king[ka]){
				m++;
				ta--;
				ka--;
			}
			else if(tian[tb] > king[kb]){
				m++;
				tb++;
				kb++;
			}
			else if(tian[tb] < king[ka]){
				tb++;
				ka--;
				m--;
			}
		}
//		money = ;
		cout<<200*m<<endl;
	}
	return 0;
}
