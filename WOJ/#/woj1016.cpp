#include <stdio.h> 
#include <stdlib.h> 

#define MAXN 1010 

typedef struct node // ��������Ϣ,x,yΪ���� 
{ 
    int x,y; 
} Node; 

Node s[MAXN],r[MAXN];  // s,r�ֱ�Ϊ����ͽ��������Ϣ 
int n; 

int cmp1(const void *a,const void *b)  // ��������ж� 
{ 
    Node *aa=(Node *)a; 
    Node *bb=(Node *)b; 
    return((aa->y==bb->y)?(aa->x-bb->x):(aa->y-bb->y)); 
} 

int cmp2(const void *a,const void *b)  // ��������ж� 
{ 
    Node *aa=(Node *)a; 
    Node *bb=(Node *)b; 
    return((aa->y==bb->y)?(aa->x-bb->x):(bb->y-aa->y)); 
} 

int check() // �жϺ���,�ԳƷ���1,���򷵻�0 
{ 
    int i,k,sum; 
    k=n/2+1; 
    sum=s[0].y+r[0].y;  // y�����y��Сֵ�� 
    for(i=0;i<k;i++)    // �ж��Ƿ�Գ� 
    { 
        if(s[i].y+r[i].y!=sum) return(0);  // ���㲻�ԳƵ���� 

        if(s[i].x!=r[i].x) return(0);      // ����y�ԳƵ���x��һ�� 
    } 
    return(1); 
} 

int main() 
{ 
    int i; 
    while(scanf("%d",&n)!=EOF) 
    { 
        for(i=0;i<n;i++)    // �������ݲ����� 
        { 
            scanf("%d%d",&s[i].x,&s[i].y); 
            r[i]=s[i]; 
        } 
        qsort(s,n,sizeof(s[0]),cmp1);  // ��s����������� 
        qsort(r,n,sizeof(r[0]),cmp2);  // ��r���н������ 
        if(check()==1) printf("YES\n"); // �ж� 
        else printf("NO\n"); 
    } 
    return(0); 
}