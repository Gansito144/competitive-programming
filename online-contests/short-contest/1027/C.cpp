#include <iostream>
#include <vector>
#include <map>

using namespace std;
using i64 = long long int;

double inline func(double A, double B) {
  return (A*A + ((B*A)*2LL) + B*B) / (A*B);
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int n, x;
    i64 A = -1, B = -1;
    map <i64, int> fr;
    vector <i64> sd;
    cin >> n;
    while (n--) {
      cin >> x;
      ++fr[x];
    }

    for (const auto &p : fr) {
      if(p.second < 2) continue;
      sd.push_back(p.first);
      if (p.second >= 4) {
        sd.push_back(p.first);
      }
    }
    A = sd[0];
    B = sd[1];
    double ret = func(A, B);
    for (int i=2; i<sd.size(); ++i) {
      double tmp = func(sd[i-1], sd[i]);
      if (tmp < ret) {
        A = sd[i-1];
        B = sd[i];
        ret = tmp;
      }
    }
    cout << A << " " << A << " " << B << " " << B << endl;
  }
  return 0;
}

