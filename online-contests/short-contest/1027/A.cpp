#include <iostream>
#include <string>

using namespace std;

bool inline fit (char a, char b) {
  for (char ca = a-1; ca <= a+1; ++ca)
    for (char cb = b-1; cb <= b+1; ++cb) {
      if (ca < 'a' || cb < 'a') continue;
      if (ca > 'z' || cb > 'z') continue;
      if (ca == a || cb == b) continue;
      if (ca == cb)
        return true;
    }
  return false;
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    bool pal = true;
    string s;
    cin >> n;
    cin >> s;

    for (int i=0; i<n; ++i)
      if ( !fit(s[i], s[n-1-i]) ) {
        pal = false;
        break;
      }
    cout << (pal ? "YES\n" : "NO\n") ;
  }
  return 0;
}

