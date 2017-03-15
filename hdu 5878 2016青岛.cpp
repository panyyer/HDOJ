#include <iostream>  
#include <cstdio>  
#define min(a,b) ((a)<(b)?(a):(b))  
#define min4(a,b,c,d) min(min(a,b),min(c,d))  
using namespace std;  
int a[5850];  

int bSearch(int begin, int end, int e)
{
    int mid, left = begin, right = end;
    while(left <= right){
        mid = (left + right) >> 1;
        if(a[mid] >= e) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}

int main()  
{  
    freopen("input.txt","r",stdin);  
    int n=1, T;
    int p2,p3,p5,p7;  
    p2=p3=p5=p7=1;  
    a[1]=1;  
    while(n<5843){  
        a[++n]=min4(2*a[p2],3*a[p3],5*a[p5],7*a[p7]);
        if(a[n]==2*a[p2])p2++;
        if(a[n]==3*a[p3])p3++;  
        if(a[n]==5*a[p5])p5++;  
        if(a[n]==7*a[p7])p7++; 
    }  
    cin>>T;
    while(T--){
    	scanf("%d",&n);
    	printf("%d\n",a[bSearch(1,5842,n)]);      	
    }
    return 0;  
}  
