#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

#define F first
#define S second

using namespace std;
using dd = pair<double, double>;
using dds = pair<dd, string>;

int main() {
  int N;
  cin >> N;
  vector <dds> R( N );
  vector <int> ans;
  for (int i = 0; i < N; ++i) {
    cin >> R[ i ].S >> R[ i ].F.S >> R[ i ].F.F;
  }
  double best = 123456789.0;
  sort(R.begin(), R.end());
  for (int i = 0; i < N; ++i) {
    double cost = R[ i ].F.S;
    vector <int> cnt = {i};
    for (int j = 0; j < N && cnt.size() < 4; ++j) {
      if (i == j) continue;
      cost += R[ j ].F.F;
      cnt.push_back( j );
    }
    if (cost < best) {
      best = cost;
      ans = cnt;
    }
  } 

  printf("%.9lf\n",best);
  for (const auto &a : ans) cout << R[ a ].S << "\n";

  return 0;
}



