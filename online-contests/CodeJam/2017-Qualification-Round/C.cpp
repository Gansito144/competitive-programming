#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using i64 = long long int;

int main() {
  int tests;
  i64 N, K, gap, a, b, cnt, total;
  
  cin >> tests;
  for(int tc=1; tc<= tests; ++tc) {
    cin >> N >> K;
    map <i64, i64> PQ;
    PQ[N] = 1LL;
    total = 0LL;
    while(true) {
      tie(gap, cnt) = *prev(PQ.end());
      PQ.erase(prev(PQ.end()));
      if (total + cnt >= K)
      {
        a = gap >> 1;
        --gap;
        b = gap >> 1;
        break;
      }
      PQ[gap >> 1] += cnt;
      --gap;
      PQ[gap >> 1] += cnt;
      total += cnt;
    }
    cout << "Case #" << tc << ": " << a << " " << b << endl; 
  }
  return 0;
}

