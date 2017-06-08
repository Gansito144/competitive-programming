#include <iostream>

using namespace std;

const int kMod = 1000000007; 
const int kMax = 1234567;

int dp[kMax], N;

int main() {

  cin >> N;
  dp[2] = 3;
  dp[3] = 4;
  for(int i=4; i<=N; ++i) {
    dp[i] = dp[i-2] + dp[i-1];
    if(dp[i] >= kMod) dp[i] -= kMod;
  }
  cout << dp[N] << endl;
  return 0;
}
