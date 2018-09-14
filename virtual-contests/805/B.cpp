#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  string p = "aabb";
  cin >> n;
  for (int i=0; i<n; ++i) {
    cout << p[i%4];
  }
  cout << endl;
  return 0;
}


