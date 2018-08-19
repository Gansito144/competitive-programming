#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

#define F first
#define S second

using namespace std;
using i64 = long long int;
using ii = pair <int,int>;


int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  int n;
  cin >> n;
  vector <ii> v(n);

  for (ii &vi : v) {
    cin >> vi.F >> vi.S;
  }

  bool can = true;

  int prv = max(v[0].F, v[0].S);

  for (int i=1; i<n; ++i) {
    int mx = max(v[i].F, v[i].S);
    if (mx <= prv) prv = mx;
    else {
      mx = min(v[i].F, v[i].S);
      if (mx > prv) {
        can = false;
        break;
      }
      prv = mx;
    }
  }

  cout << (can?"YES":"NO") << endl;

  return 0;
}

