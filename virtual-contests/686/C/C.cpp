#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int l, r, nn, mm;
bool dbg = false;

long long int base (string &s) 
{
  long long int r = 0;
  for (char &c : s) {
    r = r * 7 + (c-'0');
  }
  return r;
}

void bck(int k, string &s, int N, int &ans)
{
  if (k == N) {
    string izq = s.substr(0, l);
    string der = s.substr(l);
    if (izq != "" && der != "") {
      long long int A = base(izq), B = base(der);
      if (dbg) cout << izq << " || " << der << endl;
      if (dbg) cout << A << " -- " << B << endl;
      if (A < nn && B < mm) {
        if (dbg) cout << A << " ** " << B << endl;
        ++ans;
      }
    }
  } else {
    int msk = 0;
    ++k;
    for (int i=0; i<k; ++i) msk |= (1<<(s[i]-'0'));
    if (dbg) printf("%d %s %x\n", k, s.c_str(), msk); 
    for (char c = '0'; c<'7'; ++c) {
      int  b = c - '0';
      if((msk>>b) & 1) continue;
      s[k-1] = c;
      bck(k, s, N, ans);
      s[k-1] = 0;
    }
  }
}

int main () {
  int n, m;
  
  cin >> nn >> mm;
  n = nn - 1;
  m = mm - 1;

  do {++l; n/=7;} while (n);
  do {++r; m/=7;} while (m);

  int ans = 0;
  int N = l+r;

  if (N <= 7) {
    string s(N, 0);
    bck(0, s, N, ans);
  }

  cout << ans << endl;

  return 0;
}

