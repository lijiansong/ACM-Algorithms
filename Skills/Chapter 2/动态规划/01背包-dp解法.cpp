#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N=101;
const int MAX_W=10001;
int dp[MAX_N][MAX_W];
int weight[MAX_N]={0},value[MAX_N]={0},n,max_w;
//�ӵ�i����Ʒ��ʼ��ѡ����С��w�Ĳ��� 
int rec(int i,int w)
{
	if(dp[i][w]>=0)
		return dp[i][w];
	int ans;
	//û��ʣ�����Ʒ�� 
	if(i==n)
		ans=0;
	//�޷���ѡ�����Ʒ 
	else if(w<weight[i]) 
		ans=rec(i+1,w);
	//��ѡ�Ͳ���ѡ������һ�� 
	else
		ans=max(rec(i+1,w-weight[i])+value[i],rec(i+1,w));
	dp[i][w]=ans;
	return dp[i][w];
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,max_w)<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while (cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>weight[i]>>value[i];
		cin>>max_w;
		solve();
	}
	fclose(stdin);
	return 0;
}

