/*
    Name: 
    Copyright: 
    Author: 
    Date: 22/01/16 22:00
    Description: woj1050
    ��С������
    prim�㷨��ʵ�� 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int N=101;
int main()
{
    //freopen("in.txt","r",stdin);
    int t,matrix[N][N],num;
    int i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>num;
        for(i=1;i<=num;++i)
            for(j=1;j<=num;++j)
                cin>>matrix[i][j];
        int sum=0,flag[N]={0};//flag[i]��ʶ�ڵ�i�Ƿ��Ѿ������� 
        flag[1]=1;//�ӵ�һ���ڵ㿪ʼ 
        for(k=1;k<num;++k)
        {
            int min=-1,min_weight;
            for(i=1;i<=num;++i)//ѡȡ��һ��Ȩֵ��С�Ľڵ�
            {
                if(flag[i]==0&&(min==-1||matrix[1][i]<min))
                {
                    min=matrix[1][i];
                    min_weight=i;
                }
            }
            flag[min_weight]=1;
            for(i=1;i<=num;++i)
            {
                if(flag[i]==0&&matrix[1][i]>matrix[min_weight][i])
                {
                    matrix[1][i]=matrix[min_weight][i];
                }
            }
            sum+=matrix[1][min_weight];
        }
        cout<<sum<<endl;
    }
    return 0;
}