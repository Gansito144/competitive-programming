#include <iostream>
#include <set>

#define endl '\n'

using namespace std;

int main() {
  // fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int R, C, pG, pS;
  string s;

  cin >> R >> C;
  int ans = 0;
  set <int> difs;
  while(R--) {
    cin >> s;
    for(int c=0; c<C; ++c) {
      if(s[c] == 'G') pG = c;
      if(s[c] == 'S') pS = c;
    }
    if(pS < pG) { ans = -1; break; }
    difs.insert(pS - pG);
  }
  if(ans != -1) ans = difs.size();
  cout << ans << endl;

  return 0;
}

