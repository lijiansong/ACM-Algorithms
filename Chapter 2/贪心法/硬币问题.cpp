/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/08/16 22:33
	Description: 
	Ӳ������
	̰���㷨 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int V[6]={1,5,10,50,100,500};
int A,C[6];//A��ʾ��ֵ��C[i]��ʾ������ֵ��Ӳ�ҵ�ö�� 
void solve()
{
	int ans=0;
	for(int i=5;i>=0;--i)
	{
		int t=min(A/V[i],C[i]);//ʹ��Ӳ��i��ö��
		A-=t*V[i];
		ans+=t; 
	}
	cout<<ans<<endl;
} 
int main()
{
	for(int i=0;i<6;++i)
		cin>>C[i];
	cin>>A;
	solve();
	return 0;
}
