#include<iostream>  
#include<cstdio>
#include<algorithm>  
using namespace std;  
  
int main(void)  
{  
freopen("in.txt","r",stdin); 
    int L;  //���ܳ�  
    int n;  //����ʯͷ���������S���յ���E��  
    int m;  //�Ƴ�ʯͷ��  
  
    while(cin>>L>>n>>m)  
    {  
        /*Input & Initial*/  
  
        int* dist=new int[n+2];  //��i��ʯͷ�����ʯͷ�ľ���Ϊdist[i]  
        dist[0]=0;    //���S  
        dist[n+1]=L;  //�յ�E  
  
        int low=L;   //�Ͻ�(һ����Ծ����̾���)  
        int high=L;   //�½�(һ����Ծ��������)  
        for(int i=1;i<=n+1;i++)  
        {  
            if(i<=n)   //������1~n����i=n+1ʱ������Ѱ��low  
                cin>>dist[i];  
  
            if(low > dist[i]-dist[i-1])  
                low=dist[i]-dist[i-1];  
        }  
  
        sort(dist,dist+(n+2));   //����ʯͷ��S�ľ�����������  
  
        /*Binary-Search*/  
          
        while(low<=high)  
        {  
            int mid=(low+high)/2;  //�����������С���ľ������У����ֲ���mid��������Ž���ƫ����ƫС  
                                   //����mid���Ƴ�m��ʯͷ�����̾���  
  
            int delrock=0;    //���õ�ǰ��midֵ���Ƴ���ʯͷ��  
            int sum=0;   //���POJ 3273, ������ ����������ۼ�ֵ  
                         //���ڵ�i�������ۼӺ�sum  
  
            for(int i=1;i<=n+1;)  
            {  
                if( (sum+=dist[i]-dist[i-1]) <= mid)  
                {  
                    i++;  
                    delrock++;  
                }  
                else   //���ӵ�i�������ۼӵ�i+k���������sum>mid����k��������Ϊһ��  
                {  
                    i++;  
                    sum=0;  //sum��0���ӵ�i+k+1�����������ۼ�  
                }  
            }  
  
            if(delrock<=m)   //�����ѵ�֮һ����ʹdelrock==mҲ��һ���ҵ������Ž�  
                low=mid+1;   //�õ�ǰmidֵ�Ƴ���ʯͷ��С�ڹ涨����˵��midƫС  
            else               
                high=mid-1;  //��֮midƫ��  
                cout<<"delrock: "<<delrock<<" mid: "<<mid<<endl;
        }  
  
        /*Output & Relax*/  
  
        cout<<low<<endl;  
  
        delete dist;  
    }  
  
    return 0;  
}
