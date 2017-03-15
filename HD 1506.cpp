#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
//	freopen("1.txt","r",stdin);
	long long int maxm,temp,l[100002],r[100002];
	int n,h[100002];
	while(scanf("%d",&n)!=EOF && n!=0){
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
			r[i] = l[i] = i;
		}
		h[0] = h[n+1]= -1;
		for(int i=2;i<=n;i++){
			int j=i-1;
			while(h[i]<=h[j])
				j=l[j]-1;
			l[i] = j+1;
		}
		for(int i=n-1;i>0;i--){
			int j=i+1;
			while(h[i]<=h[j])
				j=r[j]+1;
			r[i] = j-1;
		}
		maxm = 0;
		for(int i=1;i<=n;i++){
			if((temp=(r[i]-l[i]+1)*h[i]) > maxm){
				maxm = temp;
			}
		}
		printf("%lld\n",maxm);
	}
	return 0;
}
