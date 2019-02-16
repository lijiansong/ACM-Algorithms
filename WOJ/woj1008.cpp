/*
    Name: 
    Copyright: 
    Author: 
    Date: 05/01/16 10:43
    Description: woj 1008
    ����·�㷨�������
    �ο����㷨�������ž��䡷��11�� ���������� 
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm> 
using namespace std;
#define N 210 
int m,n,k,a[N],flow[N][N],capacity[N][N],s,t,f,p[N];
void MaxFlow()
{
    queue<int> q;
    memset(flow,0,sizeof(flow));
    f=0;
    for(;;)
    {
        memset(a,0,sizeof(a));
        a[s]=0xfffffff;
        q.push(s);
        while(!q.empty())//BFSѰ������·�� 
        {
            int u=q.front();
            q.pop();
            for(int v=1;v<=t;++v)
            {
                //�ҵ��½ڵ�v 
                if(!a[v] && capacity[u][v] > flow[u][v])
                {
                    p[v]=u;q.push(v);//��¼v�ĸ��ڵ㣬��������� 
                    a[v]=min(a[u],capacity[u][v]-flow[u][v]);
                }
            }
        }
        if(a[t]==0)break;//�Ҳ�����ǰ����Ϊ����� 
        for(int u=t;u!=s;u=p[u])//�ӻ�������� 
        {
            flow[p[u]][u]+=a[t];//������������ 
            flow[u][p[u]]-=a[t];//���·������� 
        }
        f+=a[t];//���´�s������������
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    while(cin>>m>>n)
    {
        memset(capacity,0,sizeof(capacity));
        s=0;
        t=m+n+1;
        f=0;
        int ani=m+1,temp;
        for(i=1;i<=m;++i)
        {
            for(j=0;j<n;++j)
            {
                cin>>temp;
                if(temp==1)
                    capacity[i][ani+j]=1;
                capacity[ani+j][t]=1;
            }
        }
        cin>>k;
        for(i=1;i<=m;++i)
        {
            capacity[0][i]=k;
        }
        MaxFlow();
        if(f==n)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}