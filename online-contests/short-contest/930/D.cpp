#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map <int, int> lvl; 
vector <int> S[123456];

void dfs(int u, int p, int d)
{
  ++lvl[d];
  for (int &v : S[u]) 
  {
    if (v != p)
      dfs(v, u, d+1);
  }
}

int main ()
{
  int n;
  scanf("%d",&n);
  for (int s=2; s<=n; ++s)
  {
    int p;
    scanf("%d",&p);
    S[p].push_back(s);  
  }
  dfs(1, 0, 0);
  int ans = 0;
  for (auto &l : lvl )
    ans += (l.second & 1);
  cout << ans << endl;
  return 0;
} 

