#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

class PingPongQueue {
  public:
    vi whoPlaysNext(vi skills, int N, int K) {
      int wins[51];
      memset(wins, 0, sizeof wins);
      deque <int> waiting, table;
      vi ans = {0,0};
      for(int i=0; i<skills.size(); ++i) {
        table.push_back(skills[i]);
      }
      while(K--) {
        ans[0] = table.front();
        table.pop_front();
        ans[1] = table.front();
        table.pop_front();
        if(ans[0] > ans[1]) swap(ans[0],ans[1]);
        printf("%d %d\n",ans[0],ans[1]);
        wins[ans[1]] = (wins[ans[1]] + 1) % N;
        wins[ans[0]] = 0;
        table.push_back(ans[0]);
        if(wins[ans[1]]) table.push_front(ans[1]);
        else table.push_back(ans[1]);
      }
      return ans;
    }
};
