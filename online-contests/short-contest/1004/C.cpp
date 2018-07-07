#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n; 
  i64 ans = 0;

  cin >> n;
  vector <int> v(n);
  map <int,int> mL, mR;
  for (int &vi : v) {
    cin >> vi;
    ++mR[vi];
  }
  for (int i=0; i<n; ++i)
  {
    int &vi = v[i];
    if (mR[vi] == 1) mR.erase(vi);
    else --mR[vi];
    if (mL[vi]) continue;
    ++mL[vi];
    ans += mR.size();
  }
  cout << ans << endl;
  return 0;
}

