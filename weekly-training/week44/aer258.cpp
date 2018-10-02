#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k, e;
  while (cin >> n >> k, n) {
    multiset <int> Q;
    vector <int> v(n);

    for (int &vi : v) cin >> vi;
    
    for (int i=0; i<k-1; ++i) {
      Q.insert(v[i]);
    }

    for (int i=k-1; i<n; ++i) {
      Q.insert(v[i]);
      auto it = Q.end();
      --it;
      cout << *it << (i==n-1?"\n":" ");
      Q.erase(Q.find(v[i-k+1]));
    }
  }
  return 0;
}

