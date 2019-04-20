#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  const int N = 4;
  const string genome = "ACTG";

  int n, best = 123456789;
  string s;

  cin >> n >> s;
  for (int i=0; i+N<=n; ++i) {
    int score = 0;
    for (int j=0; j<N; ++j) {
      int a = s[i+j] - 'A';
      int b = genome[j] - 'A';
      if (a > b) swap(a, b);
      // cout << s[i+j] << ":" << a << " ";
      // cout << genome[j] << ":" << b << endl;
      score += min(b - a, (26 - b) + a);
    }
    best = min(best, score);
  }
  cout << best << endl;
  return 0;
}

