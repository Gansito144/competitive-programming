#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC;
  cin >> TC;
  for (int tc=0; tc<TC; ++tc) {
    string aa, bb;
    cin >> aa >> bb;
    int mx = 0;
    for(char &a: aa)
      for (char &b: bb) {
        swap(a, b);
        mx = max(mx, stoi(aa) + stoi(bb));
        swap(a, b);
      }
    cout << mx << endl;
  }


  return 0;
}

