#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  queue <int> lucky;
  lucky.push(4);
  lucky.push(7);
  while (true) {
    int l = lucky.front(); lucky.pop();
    if (l > n) break;
    if (n % l == 0) {
      cout << "YES" << endl;
      return 0;
    }
    lucky.push(l*10 + 4);
    lucky.push(l*10 + 7);
  }
  cout << "NO" << endl;
  return 0;
}

