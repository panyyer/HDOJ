#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <cmath>  
#include <iostream>  
using namespace std;  
double arr[50005],sum[50005],sum2[50005];
int main()  
{  
	//freopen("input.txt","r",stdin);
    int T,i,n,k,m;
	double minm,aver,temp;
    scanf("%d",&T);  
    while(T--) {
    	sum[0]=sum2[0]=0;
    	scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lf",&arr[i]);
		}
		sort(arr+1,arr+n+1);  
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+arr[i];
			sum2[i]=sum2[i-1]+arr[i]*arr[i];		
		}
		m=n-k;
		if(m==0){
			printf("0\n");
		} else{
			aver=sum[m]/m;
			minm=sum2[m]+m*aver*aver-2*aver*sum[m];
			for(int i=m+1;i<=n;i++){
				aver=(sum[i]-sum[i-m])/m;
				temp=sum2[i]-sum2[i-m]+m*aver*aver-2*aver*(sum[i]-sum[i-m]);
				if(temp<minm){
					minm=temp;
				}
			}
			printf("%.10f\n",minm);
		}
    }  
    return 0;  
}  
