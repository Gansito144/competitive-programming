#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
  int N, ans = 0;

  cin >> N;
  vector <int> v(N);

  for (int &vi: v) cin >> vi;
  sort(v.begin(), v.end());

  for (int i=1; i<v.size(); i += 2)
    ans += v[i] - v[i-1];

  cout << ans << endl;

  return 0;
}


