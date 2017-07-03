#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#define MAXNUM 12701
//�Ե���ΪԲ�ģ���dΪ�뾶��Բ���õ�����Բ��x���ཻ�����䣻ȥ���ظ����䣬���õ��״���Ŀ 
int calMin(int **island,int n,int d);
int main() 
{
    freopen("in.txt","r",stdin); 
    int num = 0;
    char s[10];
    
    while(1)
	{  
          ++num;
          int n,d,i;
          scanf("%d%d",&n,&d);
          
          if(n==0&&d==0) break;
          int **island = (int**)malloc(sizeof(int*)*n);
          for(i=0;i<n;i++)
		  {           
              island[i] = (int*)malloc(sizeof(int)*2);
              scanf("%d%d",&island[i][0],&island[i][1]);
          }
          
          //���������״���� 
          int min = calMin(island,n,d);
          printf("Case %d: %d\n",num,min);
          
          //��ȡ�հ���
          gets(s);
          free(island);
    }
    //system("pause");
    return 0;
}
int calMin(int **island,int n,int d){
    
    double *arr = (double*)malloc(sizeof(double)*n*2);
    int i,j;
    
    for(i=0;i<n;i++){
            
         if(island[i][1]<0||island[i][1]>d||d<0){
                                                   
              return -1;
         }
         
         //������������
         if(abs(island[i][1]-d)<1e-6)
		 {
            arr[2*i] = island[i][0];
            arr[2*i+1] = island[i][0];                             
         }
		 else
		 {  
             //����
             double x = sqrt(pow(d,2)-pow(island[i][1],2)); 
             arr[2*i] = (double)island[i][0] - x;
             arr[2*i+1] = (double)island[i][0] + x;     
         }
    }
    
    //����, todo sort by STL
    for(i=0;i<n-1;i++)
	{
        for(j=0;j<n-i-1;j++)
		{             
              if(arr[2*j]>arr[2*(j+1)])
			  {                  
                   double temp = arr[2*(j+1)];
                   arr[2*(j+1)] = arr[2*j];
                   arr[2*j] = temp;
                   temp = arr[2*(j+1)+1];
                   arr[2*(j+1)+1] = arr[2*j+1];
                   arr[2*j+1] = temp;                          
              }          
        }        
    } 
    
    //ȥ���غ����䣬�õ��״����
    int num = 0;
    double right = -1;
    
    for(i=0;i<n;i++)
	{       
        if(i==0)
		{
            num++; 
            right = arr[2*i+1];        
        }
		else
		{  
            if(arr[2*i]<=right)
			{
                  if(arr[2*i+1]<right)
				  {            
                     right = arr[2*i+1];                     
                  }
                  continue;                            
            }
			else
			{
                  num++;
                  right = arr[2*i+1];      
            }
        }
    } 
    
    return num;
}
