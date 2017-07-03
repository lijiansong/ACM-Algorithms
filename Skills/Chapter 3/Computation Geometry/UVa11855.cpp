// UVa11855 Buzzwords
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
template <int maxn>
struct SuffixArray {
  int s[maxn];      // ԭʼ�ַ����飨���һ���ַ�Ӧ������0����ǰ����ַ������0��
  int sa[maxn];     // ��׺����
  int rank[maxn];   // ��������. rank[0]һ����n-1�������һ���ַ�
  int height[maxn]; // height����
  int t[maxn], t2[maxn], c[maxn]; // ��������
  int n; // �ַ�����

  void clear() { n = 0; memset(sa, 0, sizeof(sa)); memset(s, 0, sizeof(s));}

  // mΪ����ַ�ֵ��1������֮ǰ�����ú�s��n
  void build_sa(int m) {
    int i, *x = t, *y = t2;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1) {
      int p = 0;
      for(i = n-k; i < n; i++) y[p++] = i;
      for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i]-k;
      for(i = 0; i < m; i++) c[i] = 0;
      for(i = 0; i < n; i++) c[x[y[i]]]++;
      for(i = 0; i < m; i++) c[i] += c[i-1];
      for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1; x[sa[0]] = 0;
      for(i = 1; i < n; i++)
        x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k] ? p-1 : p++;
      if(p >= n) break;
      m = p;
    }
  }

  void build_height() {
    int i, j, k = 0;
    for(i = 0; i < n; i++) rank[sa[i]] = i;
    for(i = 0; i < n; i++) {
      if(k) k--;
      int j = sa[rank[i]-1];
      while(s[i+k] == s[j+k]) k++;
      height[rank[i]] = k;
    }
  }
};

const int maxLen = 1024;
char line[maxLen]; 
int len;
SuffixArray<maxLen> sa;

void solve()
{
    sa.clear();       
    for(int i = 0; i < len; i++) if(isupper(line[i])) 
        sa.s[sa.n++] = line[i] - 'A' + 1;
     
    if(!sa.n) { puts("0\n"); return; }
    sa.s[sa.n++] = 0;
    
    sa.build_sa('Z' - 'A' + 2);
    sa.build_height();        
    
    vector<int> x;
    for(int l = 1; l <= sa.n; l++)
    {
        x.clear();
        int cnt = 0;
        for(int i = 1; i < sa.n; i++){
            int h = sa.height[i];
            if(h >= l) cnt++;
            else { x.push_back(cnt); cnt = 0; }
        }
        x.push_back(cnt);
        
        sort(x.begin(), x.end(), greater<int>());
        
        int ans = x[0] + 1;
        if(ans > 1) printf("%d\n", ans);
        else break;
    }
    puts("");
}

int main()
{
    while(true)
    {
        fill_n(line, maxLen, 0);
        if(!gets(line)) break;
        len = strlen(line);
        if(len < 1) break;
        solve();
    }
    
    return 0;
}

