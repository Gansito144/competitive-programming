#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  if (n <= 2) {
    cout << "-1" << endl;
    return 0;
  }

  vector <int> ans(n, 1LL);
  ans[0] *= 5LL; ans[n-1] *= 5LL;
  for (int i=0; i<n-1; i++) ans[i] *= 2LL;
  for (int i=1; i<n;   i++) ans[i] *= 3LL;
  for (int i=2; i<n-1; i++) ans[i] *= 5 * i;

  for (int i=0; i<n; ++i) {
    cout << ans[i] << endl; 
  }

  return 0;
}


