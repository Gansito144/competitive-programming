#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k, e;
  while (cin >> n >> k, n) {
    deque <int> Q;
    vector <int> v(n);

    for (int &vi : v) cin >> vi;
    
    for (int i=0; i<k-1; ++i) {
      while (!Q.empty() && v[Q.back()] <= v[i]) {
        Q.pop_back();
      }
      Q.push_back(i);
    }

    for (int i=k-1; i<n; ++i) {
      while (!Q.empty() && v[Q.back()] <= v[i]) {
        Q.pop_back();
      }
      Q.push_back(i);
      cout << v[Q.front()] << (i==n-1?"\n":" ");
      if ((i - Q.front()) >= k-1) {
        Q.pop_front();
      }
    }
  }
  return 0;
}

