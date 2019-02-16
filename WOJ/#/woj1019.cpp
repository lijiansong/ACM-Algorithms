#include <stdio.h> 
#include <string.h> 

void pline(void){printf("+-----+-----------+-----------+-----------+-----------+-----------+\n");} 

int main() 
{ 
  int n,i,j,k,l,t; 
  char s[50],sub[20],day[4],time[10],num,cls[8][6][12]; 
    
  while(scanf("%d",&n)!=EOF) 
  { 
    gets(s); 
    for(i=1;i<=7;i++)for(j=1;j<=5;j++)strcpy(cls[i][j],"          "); 
    for(t=1;t<=n;t++) 
    { 
      gets(s); 
        
      i=0; 
      while(s[i]!=':')i++; 
      memcpy(sub,s,i);sub[i]='\0'; 
      if (strlen(sub)%2==0){sub[i]=' ';sub[i+1]='\0';} 
        
      j=i+2; 
      while(s[j]!=' ')j++; 
      memcpy(day,&s[i+2],j-i-2); //day��ʾ���ڼ�  
        
      k=j+1; 
      while(s[k]!=' ')k++; 
      memcpy(time,&s[j+1],k-j-1); //time��ʾ���绹������  
      num=s[k+1]; //num��ʾ�ڼ��ڿ�  
        
      switch(day[1]) //�õڶ����ַ�ʶ������  
      { 
        case 'O':i=1;break;  
        case 'U':i=2;break;  
        case 'E':i=3;break;  
        case 'H':i=4;break;  
        case 'R':i=5;break; 
      }  
      switch(time[0]) //�õ�һ���ַ�ʶ�����绹������  
      { 
        case 'M':j=0;break; 
        case 'A':j=4;break; 
      } 
      k=num-'0';  
        
      strcpy(cls[j+k][i],sub); 
    } 
    pline(); 
    printf("|    |    MON    |    TUE    |    WED    |    THU    |    FRI    |\n"); 
    pline(); 
      
    //����  
      
    printf("|                          Morning                                |\n"); 
    pline(); 
    for(i=1;i<=4;i++) 
    { 
      for(j=1;j<=5;j++) 
      { 
        if(j==1)printf("|  %d  |",i); 
        k=(11-strlen(cls[i][j]))/2; //������Ҫ���ӵĿո�  
        for(l=1;l<=k;l++)printf(" "); 
        printf("%s",cls[i][j]); 
        for(l=1;l<=k;l++)printf(" "); 
        printf("|"); 
      } 
      printf("\n");pline(); 
    } 
      
    //����  
    
    printf("|                        Afternoon                              |\n"); 
    pline();  
    for(i=1;i<=3;i++)  
    { 
      for(j=1;j<=5;j++)  
      { 
        if(j==1)printf("|  %d  |",i);  
        k=(11-strlen(cls[i+4][j]))/2; //������Ҫ���ӵĿո�  
        for(l=1;l<=k;l++)printf(" ");  
        printf("%s",cls[i+4][j]);  
        for(l=1;l<=k;l++)printf(" ");  
        printf("|");  
      }  
      printf("\n");pline();  
    }    
    printf("\n"); 
  } 
}