/*
    Name: 
    Copyright: 
    Author: 
    Date: 31/12/15 10:38
    Description: woj1315 
    ������ȡģ 
    scanf��ʽ�������ٶȿ죬������д�鷳�� 
    cin�����룬Ч�ʵͣ��������뾹Ȼ���س�ʱ���Ǻ�
*/
#include<iostream>
#include<stdio.h>
using namespace std;
long PowMod(long a,long b,long c)
{
    long temp=1;
    while(b>=1)
    {
        if(b%2==1)
            temp=a*temp%c;
        a=a*a%c;
        b=b/2;
    }
    return temp;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long int a,b,c;
    while(scanf("%ld%ld%ld",&a,&b,&c)&&!(a==0&&b==0&&c==0))
    {
        //cout<<PowMod(a,b,c)<<endl;
        printf("%ld\n",PowMod(a,b,c));
    }
    return 0;
}