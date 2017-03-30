#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main() {
  int n, m, k, person;

  scanf("%d %d",&n,&m);
  for(int i=0; i<m; ++i) {
    bool match = false;
    map <int, int> cnt;
    scanf("%d",&k);
    while(k--) {
      scanf("%d",&person);
      if(cnt[-person]) match = true;
      cnt[person]++;
    }
    if(!match) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}

