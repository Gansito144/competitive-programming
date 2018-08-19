#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector <int> v(n), o(n);
  for (int i=0; i<n; ++i) {
    cin >> v[i];
    o[i] = i;
  }
  
  sort(o.begin(), o.end(), 
    [&](const int &a, const int &b) -> bool {
      return v[a] > v[b]; });

  sort(o.begin(), o.begin() + k);
  int sum = 0;
  for (int i=0; i<k; ++i)
    sum += v[o[i]];

  int prv = -1;
  cout << sum << endl;
  for (int i=0; i<k; ++i) {
    if (i == k-1) 
      cout << n - prv - 1 << " ";
    else
      cout << o[i] - prv << " ";
    prv = o[i];
  }
  cout << endl;
  return 0;
}
