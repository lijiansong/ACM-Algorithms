#include<iostream>
#include<cstdio>
/*
	Name: 
	Copyright: 
	Author: 
	Date: 01/10/16 22:30
	Description: 
	H:M:S
	A(H)=30*H+M/2+S/120
	A(M)=6*M+S/10
	A(S)=6*S
	
	���ӵ��ٶ�s=6��/s��������1/10��/s��ʱ����1/120��/s			  *
*	��������ٶ�s_m=59/10��/s��s_h=719/120��/s��m_h=120/11��/s		  *
*	�������һ������Ҫ��ʱ��sm=10/59 s/�㣬sh=120/719 s/�㣬mh=120/11 s/��   *
*	���ǲ�360�������Ϊtsm=3600/59 s��tsh=43200/719 s��tmh=43200/11 s	  *
*	��Ҫ���ĽǶ�Ϊn��                                                          *
*	rsm>n �� n*sm+k1*tsm < t < tsm-n*sm+k1*tsm;			  *
*	rsh>n �� n*sh+k2*tsh < t < tsh-n*sh+k2*tsh;		           *
*	rmh>n �� n*mh+k3*tmh < t < tmh-n*mh+k3*tmh;			  *
*	����������������ռ����ʱ�伴Ϊʱ�롢���롢�������Ƕȴ���n����ʱ��          *
*/

using namespace std;

int main()
{
    int t;
    double n,sum,ft1,ft2,ft3,et1,et2,et3,max,min;
    double sm,sh,mh,tsm,tsh,tmh,fsm,fsh,fmh,esm,esh,emh;
    sm=10./59.;
    sh=120./719.;
    mh=120./11.;
    tsm=360*sm;
    tsh=360*sh;
    tmh=360*mh;
    while(scanf("%lf",&n))
    {
        if(n==-1)
            break;
        sum=0;
        fsm=sm*n;
        fsh=sh*n;
        fmh=mh*n;
        esm=tsm-fsm;
        esh=tsh-fsh;
        emh=tmh-fmh;
        for(ft3=fmh,et3=emh;et3<=43200;et3+=tmh,ft3+=tmh)
        {
            for(ft2=fsh,et2=esh;et2<=43200;et2+=tsh,ft2+=tsh)
            {
                if(et2<ft3)
                    continue;
                if(ft2>et3)
                    break;
                for(t=0,ft1=fsm,et1=esm;et1<=43200;t=t+1,et1=esm+t*tsm,ft1=fsm+t*tsm)
                {
                    if(et1<ft3 || et1<ft2)
                        continue;
                    if(ft1>et3 || ft1>et2)
                        break;
                    max=ft1;
                    if(ft2>max)
                        max=ft2;
                    if(ft3>max)
                        max=ft3;
                    min=et1;
                    if(et2<min)
                        min=et2;
                    if(et3<min)
                        min=et3;
                    sum+=min-max;
                }
            }
        }
        sum/=432.;
        printf("%.3lf\n",sum);
    }
    return 0;
} 
