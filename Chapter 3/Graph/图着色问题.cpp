#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int MAX_V=1000;

vector<int> G[MAX_V];//ͼ���ڽӱ� 
int V;int color[MAX_V];//�������ɫΪ1����-1 
bool dfs(int v,int c)
{
	color[v]=c;//�Ѷ���vȾ����ɫc 
	for(int i=0;i<G[v].size();++i)
	{
		//���ڶ���ͬɫ 
		if(color[G[v][i]]==c) return false;
		//������ڶ��㻹û��Ⱦɫ����Ⱦ��-c 
		if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return false;
	}
	//������ж��㶼Ⱦ����
	return true; 
}
void solve()
{
	for(int i=0;i<V;++i)
	{
		//�������i��û��Ⱦɫ����Ⱦ��1 
		if(color[i]==0)
		{
			if(!dfs(i,1))
			{
				printf("No\n");
				return;
			}
		}
	}
	printf("Yes\n");
} 
int main()
{
	//V=3;
	//G[MAX_V]={{1,2},{0,2},{0,1}};
	solve();
	return 0;
}
