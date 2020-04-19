#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector <int> coins = {100, 20, 10, 5, 1};

  int n, ans = 0;
  cin >> n;

  for (const int &c : coins) {
    ans += n / c;
    n %= c;
  }
  
  cout << ans << "\n";
  return 0;
}

