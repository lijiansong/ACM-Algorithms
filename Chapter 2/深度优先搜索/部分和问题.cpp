/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/16 13:47
	Description: 
	���ֺ����� 
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAX_N=20;
int a[MAX_N];
int n,k;
//�Ѿ���ǰi��õ��˺�sum��Ȼ���i��֮��Ľ��з�֧ 
bool dfs(int i,int sum)
{
	//���ǰn�������ˣ��򷵻�sum��k�Ƿ���� 
	if(i==n)	return sum==k;
	//������a[i]����� 
	if(dfs(i+1,sum))	return true;
	//����a[i]����� 
	if(dfs(i+1,sum+a[i]))	return true;
	//�����Ƿ����a[i]�����ܴճ�k�ͷ���false 
	return false;
}
void solve()
{
	if(dfs(0,0))
		printf("Yes\n");
	else
		printf("No\n");
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		cin>>k;
		solve(); 
	}
	return 0;
}
