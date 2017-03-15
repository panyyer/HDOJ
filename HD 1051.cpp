#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct stick{
	int l;
	int w;
	bool index;
}s[5000];
int mt = 1;
int main()
{
	int num, total;
	void minTime(stick *s, int n);
	cin>>num;
	while(num>0){
		cin>>total;
		for(int i=0;i<total;i++){
			scanf("%d %d", &s[i].l, &s[i].w);
			s[i].index = false;	
		} 
		minTime(s, total);
		num--;
	}
	return 0;
}

int cmp(stick s1, stick s2){
 if(s1.l < s2.l)  
        return true;  
    else if(s1.l == s2.l)  
        return s1.w < s2.w;  
    return false;  
}

void minTime(stick *s, int n){
	int c = 0, flag = 0, mark = 0;
	sort(s, s+n, cmp);
//	for(int i=0;i<n;i++)
//		cout<<s[i].l<<" "<<s[i].w<<endl;
	s[0].index = true;
	while(c != n-1){
		for(int i=1;i<n;i++){
			if(!s[i].index){
				if(flag){
					s[i].index = true;
					c++;
					mt++;
					flag = 0;
					mark = i;
					continue; 
				}
				if(s[i].l>=s[mark].l && s[i].w>=s[mark].w){
					mark = i;
					c++;
					s[i].index = true;
				}
			}
		}
		flag = 1;
				
	}
	cout<<mt<<endl;
	mt=1;
}
