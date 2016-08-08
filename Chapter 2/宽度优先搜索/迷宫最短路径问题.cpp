/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/16 16:52
	Description: �Թ����·������
	������ȱ��� 
*/
#include<iostream>
#include<queue>
using namespace std;
const int INF=100000000;
const int MAX_N=100;
const int MAX_M=100;
//����pair��ʾ״̬ 
typedef pair<int,int> P;

//����
char maze[MAX_N][MAX_M+1];//��ʾ�Թ����ַ�������
int N,M;
int sx,sy;//�������
int gx,gy;//�յ�����
int d[MAX_N][MAX_M];//������λ�õ���̾�������
//�ĸ������ƶ�������
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
//���(sx,sy)��(gx,gy)����̾���
//����޷���������INF
int bfs()
{
	queue<P> que;
	//�����е�λ�ö���ʼ��ΪINF
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			d[i][j]=INF;
	//����������У�������һ�ص�ľ�������Ϊ0
	que.push(P(sx,sy));
	d[sx][sy]=0;
	
	//����ѭ��ֱ�����еĳ���Ϊ0
	while(que.size())
	{
		//�Ѷ��е���ǰ��Ԫ��ȡ�� 
		P p=que.front();que.pop();
		//���ȡ����״̬�Ѿ����յ㣬���������
		if(p.first==gx&&p.second==gy)break;
		//4������ѭ��
		for(int i=0;i<4;++i)
		{
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			//�ж��Ƿ�����ƶ��Լ��Ƿ��Ѿ����ʹ���d[nx][ny]!=INF��Ϊ�Ѿ����ʹ���
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF)
			{
				//�����ƶ��Ļ�����뵽���У����Ҹ�λ�õľ���ȷ��Ϊ��p�ľ����1
				que.push(P(nx,ny));
				d[nx][ny]=d[p.first][p.second]+1; 
			}
		}
	}
	return d[gx][gy];
} 
void solve()
{
	int res=bfs();
	cout<<res<<endl;
}
int main()
{
	while(cin>>N>>M)
	{
		for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			cin>>maze[i][j];
		}
		
		for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			if(maze[i][j]=='S')
			{
				sx=i;sy=j;
			}
			if(maze[i][j]=='G')
			{
				gx=i;gy=j;
			}
		}
		solve();
	}
	return 0;
}
