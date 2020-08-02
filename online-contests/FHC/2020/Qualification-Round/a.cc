#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tcs;
  cin >> tcs;
  for (int tc=1; tc<=tcs; ++tc) {
    int n;
    cin >> n;
    vector <string> m(n, string(n, 'N'));
    string in, out;
    cin >> in >> out;
    for(int i=0; i<n; ++i) {
      m[i][i] = 'Y';
      for (int jj=-1; jj<2; jj+=2) {
        int j = i + jj; 
        if (j < 0 || j >= n) continue;
        if (in[i] == 'Y' && out[j] == 'Y')
          m[j][i] = 'Y';
        if (in[j] == 'Y' && out[i] == 'Y')
          m[i][j] = 'Y';
      }
    }
    for (int k=0; k<n; ++k) {
      for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
          if (m[i][j] == 'Y') continue;
          if (m[i][k] == 'Y' && m[k][j] == 'Y') {
            m[i][j] = 'Y';
          }
        }
      }
    }
    // print output
    cout << "Case #" << tc << ": \n";
    for (const string &mr : m) cout << mr << "\n";
  }
  return 0;
}

