#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int kMaxN = 1003;
int   frc[kMaxN];
int   arm[kMaxN];

int main ()
{
  int N, K;

  while(scanf("%d %d",&N,&K) == 2)
  {
    if(!N && !K) break;

    // Initialize
    memset(frc,  0, sizeof  frc);
    memset(arm,  0, sizeof  arm);
    vector< set<int> > G(N);

    // Read Graph
    for(int i=0; i<N; ++i) {
      scanf("%d",&arm[i]);
      frc[i] = arm[i];
      int m, v;
      scanf("%d",&m);
      for(int j=0; j<m; ++j) {
        scanf("%d",&v);
        G[i].insert(v);
      }
    }
    
    // Join armies
    for(int i=0; i<N; ++i)
    {
      for(const int &c : G[i])
        frc[i] += arm[c];
      // cout << i << " -- " << frc[i] << endl;
    }

    //Find and remove weak armies
    queue <int> weaks;
    for(int i=0; i<N; ++i)
      if(frc[i] < K)
        weaks.push(i);

    while(!weaks.empty())
    {
      int w = weaks.front();
      weaks.pop();
      if(frc[w] <= 0)
        continue;
      frc[w] -= arm[w];
      for(const int &c : G[w])
      {
        frc[c] -= arm[w];
        G[c].erase(w);
        if(frc[c] < K)
          weaks.push(c);
      }
      G[w].clear();
    }

    // Get answer
    int maxN = 0, maxF=0;
    for(int i=0; i<N; ++i) 
    {
      //cout << i << " ** " << frc[i]  << " -- " << G[i].size() << endl;
      //cout << maxN << " , " << maxF << endl;
      if(frc[i] < K) continue;
      //cout << G[i].size() << " || " << maxN << endl;
      /*if(((int) G[i].size()) >= maxN)
      {
        maxN = G[i].size();
        maxF = max(maxF, frc[i]);
      }*/
      ++maxN;
      maxF += arm[i];
    }
    printf("%d %d\n",maxN, maxF);
  }

  return 0;
}


