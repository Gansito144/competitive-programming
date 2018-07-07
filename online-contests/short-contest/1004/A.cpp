#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using i64 = long long int;

int main () {
  int n, d;
  set <int> s;

  cin >> n >> d;
  vector <int> v(n);

  for (int &vi : v) cin >> vi;
  for (int i=0; i<n; ++i) {
    int prv = v[i] - d;
    int nxt = v[i] + d;
    if (i==0 || (v[i-1]+d <= prv)) s.insert(prv);
    if (i==(n-1) || (v[i+1]-d >= nxt)) s.insert(nxt);
  }

  cout << s.size() << endl;

  return 0;
}

