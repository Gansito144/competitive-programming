#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <vector>

using namespace std;

const int kZ = 27;
const int kM = 31;
const int kI = 2e9;

bool is[kZ];
int  di[kM];
string G[kM];

int main() {
  int n, m, x;
  bool Ss = false;  
  cin >> n >> m >> x;
  x *= x;
  for(int i=0; i<kZ; ++i) di[i] = kI;
  vector <int> pS;
  for(int i=0; i<n; ++i) {
    cin >> G[i];
    for(int j=0; j<m; ++j) {
      if(G[i][j] != 'S') {
        is[G[i][j]-'a'] = true;
      } else {
        Ss = true;
        pS.push_back(i*100 + j);
      }
    }
  }
  for(int k=0; k<pS.size(); ++k) {
    int ni = pS[k]/100;
    int nj = pS[k]%100;
    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        int nd = (ni-i)*(ni-i)+(nj-j)*(nj-j);
        if(nd > x) continue;
        if(G[i][j] == 'S') continue;
        di[G[i][j]-'a'] = min(nd, di[G[i][j]-'a']);
      }
    }
  }
  string s;
  int ans = 0, sz;
  cin >> sz;
  cin >> s;
  for(int i=0; i<s.size(); ++i) {
    int lo = tolower(s[i])-'a';
    if(!is[lo]) {
      ans = -1;
      break;
    }
    if(s[i]>='A' && s[i]<='Z') {
      if(!Ss) {
        ans = -1;
        break;
      }
      ans += (di[lo] > x);
    }
  }
  cout << ans << endl;
  return 0;
}

