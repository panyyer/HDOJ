#include<stdio.h>
#include<iostream>
#include<string.h>
#include<malloc.h>
#include<algorithm>
using namespace std;
float m[10001];
float v[101];
int w[101];
int main()
{
	int sum,n,num;
	float t,p;
	cin>>n;
	while(n>0){
		memset(m,0,10001*sizeof(float));
		m[0] = 1;
		sum=0;

		scanf("%f %d", &t, &num);
		p = 1 - t;
		for(int i=1;i<=num;i++){
			scanf("%d %f", &w[i], &v[i]);
			sum += w[i];
		}
		for(int i=1;i<=num;i++){
			for(int j=sum;j>=w[i];j--){
				m[j] = max(m[j], m[j-w[i]]*(1-v[i]));
			}
		}
		for(int i=sum;i>=0;i--){
			if(m[i]>=p){
				cout<<i<<endl;
				break;
			}
		}
		n--;
	}
	return 0;
}
