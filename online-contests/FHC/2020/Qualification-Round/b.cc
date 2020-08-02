#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc) {
    int n, f[2] = {0,0};
    string s;
    cin >> n >> s;
    for (const char &c : s) ++f[c-'A'];
    cout << "Case #" << tc << ": " << ((abs(f[0] - f[1]) < 2) ? "Y\n" : "N\n");
  }
  return 0;
}

