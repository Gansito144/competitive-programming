#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  string s, ans;
  cin >> n >> s;
  deque <char> dq;
  int op = 1 - (n & 1);
  for (int i=0; i<n; ++i) {
    if (op)
      dq.push_front(s[i]);
    else
      dq.push_back(s[i]);
    op = 1 - op;
  }
  while (!dq.empty()) {
    cout << dq.front() ;
    dq.pop_front();
  }
  cout << endl;
  return 0;
}

