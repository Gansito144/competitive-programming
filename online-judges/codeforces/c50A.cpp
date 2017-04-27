#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, M, ans;
  while( cin >> N >> M ) {
    ans = 0;
    while( N > 1 || M > 1){
      if(N > M) swap(N, M);
      M -= 2;
      ans += N;
    }
    cout << ans << endl;
  }
  return 0;
}
