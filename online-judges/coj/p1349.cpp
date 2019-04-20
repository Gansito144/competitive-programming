#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long int;

i64 ans;

void backtrack(int n, vector <i64> v, vector <string> &op) {
  if (v.size() == 1) {
    ans = min(ans, v[0]);
  } else {
    for (int i=0; i<v.size(); ++i)
      for (int j=i+1; j<v.size(); ++j) {
        vector <i64> nv;
        for (int k=0; k<v.size(); ++k)
        {
          if (k==i||k==j) continue;
          nv.push_back(v[k]);
        }
        nv.push_back(op[n] == "*" ? v[i]*v[j] : v[i]+v[j]);
        backtrack(n+1, nv, op);
      }
  }
}

int main () {
  int T, N = 3;
  string op;

  cin >> T;

  while (T--) {
    vector <i64> v(N+1);
    vector <string> op(N);
    for (i64 &vi : v) cin >> vi;
    for (string &opi : op) cin >> opi;
    ans = 12345678912345678LL;
    backtrack(0, v, op);
    cout << ans << endl;
  }

  return 0;
}

