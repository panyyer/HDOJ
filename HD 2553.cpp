#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
int m[10];
int r[10]={0};
bool valid(int i, int j){
	for(int t=0;t<i;t++){
		if(m[t] == j || (abs(t-i) == abs(j-m[t])))		
			return false;
	}
	return true;
}

int main()
{
	int n,i,j,num;
	bool valid(int i, int j);
	while(scanf("%d", &n)){
		if(n==0) break;
		if(r[n-1] != 0){
			cout<<r[n-1]<<endl;;
			continue;
		}
		i=j=num=0;
		memset(m,-1,10*sizeof(int));
		while(i<n){
			while(j<n){
				if(valid(i,j)){
					m[i] = j;
					j=0;
					break;
				} else{
					j++;
				}
			}
			if(m[i] == -1){
				if(i==0) break;
				else {
					i--;
					j = m[i]+1;
					m[i] = -1;	
					continue;
				}
			}
			if(i==n-1){
				j = m[i]+1;
				m[i] = -1;
				num++;
				continue;
			}
			i++;
		}
		cout<<num<<endl;
		r[n-1] = num;
	}
	return 0;
}
