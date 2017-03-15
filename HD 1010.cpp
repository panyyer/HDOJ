#include<stdio.h>
#include<string.h>
char a[8][8];
int ok=0,N,M,T;
char visited[8][8];
void visit(int i,int j,int t)
{
	if(t>T||ok==1) return;
	if(a[i][j]=='D'&&t==T) {ok=1;return;}
	else if(a[i][j]=='.'||a[i][j]=='S')
	{
		visited[i][j]=1;
		if(i>=0&&i<N&&j>=0&&j+1<M&&visited[i][j+1]==0) visit(i,j+1,t+1);
		if(i>=0&&i+1<N&&j>=0&&j<M&&visited[i+1][j]==0) visit(i+1,j,t+1);
		if(i-1>=0&&i<N&&j>=0&&j<M&&visited[i-1][j]==0) visit(i-1,j,t+1);
		if(i>=0&&i<N&&j-1>=0&&j<M&&visited[i][j-1]==0) visit(i,j-1,t+1);
		visited[i][j]=0;
	}
} 
int main()
{
	memset(visited,0,sizeof(visited));
//	freopen("1.txt","r",stdin);
	int t1,t2,i,j;
	void visit(int i,int j,int t);
	while(scanf("%d %d %d",&N,&M,&T)!=EOF)
	{
		ok=0;
	//	printf("%d %d %d\n",N,M,T);
		if(N==0&&M==0&T==0)
			break;
		getchar();
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='S')
					{t1=i;t2=j;}
			}
			getchar();
		}
		visit(t1,t2,0);
		if(ok==1)
		printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
