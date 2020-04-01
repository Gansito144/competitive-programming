#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  for(int tc=0; tc <T; ++tc) {
    int a, b;
    cin >> a >> b;
    cout << (b - a%b)%b << "\n";
  }

  return 0;
}

