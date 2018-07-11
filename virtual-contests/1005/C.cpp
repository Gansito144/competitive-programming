#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  map <i64, int> fr;
  
  cin >> n;
  vector <i64> a(n);

  for (i64 &ai : a) {
    cin >> ai;
    ++fr[ai];
  }

  int ans = 0;

  for (int i=0; i<n; ++i) {
    int del = 1;
    for (int b=0; b<32; ++b) {
      if ( (1LL<<b) <= a[i] )
        continue;
      i64 cmp = (1LL<<b) - a[i];
      if (fr.count(cmp))
      {
        if (cmp == a[i] && fr[cmp] < 2) 
          continue;
        del = 0;
        break;
      }
    }
    ans += del;
  }
  
  cout << ans << endl;
  return 0;
}

