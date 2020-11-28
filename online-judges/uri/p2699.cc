#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using vi   = vector  <int>;
using vb   = vector <bool>;
using vvi  = vector   <vi>;
using vvb  = vector   <vb>;
using vvvi = vector  <vvi>;
using vvvb = vector  <vvb>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  int D, M = 1;

  cin >> s >> D;

  const int N = s.size();
  const int B = 10;
  int last = (s[N - 1] - '0');
  vvvb  can(N, vvb(B, vb(D, false)));
  vvvi path(N, vvi(B, vi(D, -1)));

  if (s[N - 1] == '?') {
    for (int d = 0; d < B; ++d) {
      can[N - 1][ d ][ d % D] = true;
    }
  }
  else {
    can[N - 1][ last ][ last % D] = true;
  }
  
  char prev_c;
  int  prev_d, prev_m;
  for (int p = N - 1; p > 0; --p) {
    M = ((B % D) * M) % D;
    prev_c = s[p - 1];
    prev_d = s[p - 1] - '0';
    prev_m = prev_d % D;
    for (int d = 0; d < B; ++d) {
      for (int m = 0; m < D; ++m) {
        if (!can[ p ][ d ][ m ]) continue;
        int mask = (m) * B + d;
        for (int nd = 0; nd < B; ++nd) {
          if (prev_c != '?' && prev_d != nd) continue;
          int nm = (m + (M * (nd % D))) % D;
          if (!can[p - 1][ nd ][ nm]) {
            can[p - 1][ nd ][ nm ] = true;
            path[p - 1][ nd ][ nm ] = mask;
          } else {
            int cd = path[p - 1][ nd ][ nm ] % B;
            if (cd < d) continue;
            path[p - 1][ nd ][ nm ] = mask;
          }
        }
      }
    }
  }

  bool found = false;
  int p = 0;
  int m = 0;
  for (int d = 1; d < B && !found; ++d) {
    if ( !can[ p ][ d ][ m ] ) continue;
    found = true;
    while (p < N) {
      cout << d;
      int nd = path[ p ][ d ][ m ] % B;
      int nm = path[ p ][ d ][ m ] / B;
      ++p; d = nd; m = nm;
    }
  }

  if (!found) cout << "*";
  cout << "\n";

  return 0;
}

