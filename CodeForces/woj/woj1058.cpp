/*
    Name: 
    Copyright: 
    Author: LJS
    Date: 13/01/16 11:10
    Description: woj1058
    �����ѧ�о����ĸ��������,
    (1+x+x^2+...+x^n)*(1+x^2+x^4+...+(x^2)^(n/2))*(1+x^3+x^6+(x^3)^(n/3))
    ģ�����ʽ��չ������x^n��ϵ�� 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n,i,j,k;
    while(cin>>n&&n)
    {
        k=0;
        for(i=n/3;i>=0;--i)
        {
            j=(n- i * 3)/2 + 1;
            k = k + j;
        }
        cout<<k<<endl;
    }
    return 0;
}