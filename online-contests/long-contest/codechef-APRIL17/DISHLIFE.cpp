#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
  int tests, N, K, nd, d;

  scanf("%d",&tests);
  while(tests--) {
    scanf("%d %d",&K,&N);
    vector < vector<int> > vi(K);
    map <int,int> fr;
    for(int i=0; i<K; ++i) {
      scanf("%d",&nd);
      while(nd--) {
        scanf("%d",&d);
        vi[i].push_back(d);
        fr[d]++;
      }
    }
    if(fr.size() != N) puts("sad");
    else {
      bool some = false;
      for(int i=0; i<K && !some; ++i) { 
        some = true;
        for(int j=0; j<vi[i].size(); ++j) {
          if(fr[ vi[i][j] ] == 1) {
            some = false;
            break;
          }
        }
      }
      puts(some?"some":"all");
    }
  }
  return 0;
}

