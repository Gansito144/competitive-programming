#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ii = pair<int,int>;

int f( vector<int> count, int dist, int N) {
  set <ii, greater<ii>> nxt;
  for (int c=1; c<=N; ++c) {
    if (count[c] > 0)
      nxt.insert( {count[c], c} );
  }
  vector <int> sol;
  for (int i=0; i<N; ++i) {
    if (i >= dist && count[sol[i-dist]]) {
      nxt.insert( {count[sol[i-dist]], sol[i-dist]} );
    }
    if (nxt.empty()) return 1;
    sol.push_back(nxt.begin()->second);
    count[nxt.begin()->second]--;
    nxt.erase(nxt.begin());
  }
  return 0;
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tcs;
  cin >> tcs;
  while (tcs--) {
    int N, candy;
    cin >> N;
    vector < int > count( N + 1 );
    for (int i=0; i<N; ++i) {
      cin >> candy;
      ++count[candy];
    }
    
    int ans = (1 << 21) - 1;
    for (int bit = 20; bit >= 0; --bit) {
      ans ^= f(count, ans ^ ( 1 << bit), N) << bit;
    }
    cout << ans-2 << "\n";
  }
  return 0;
}

