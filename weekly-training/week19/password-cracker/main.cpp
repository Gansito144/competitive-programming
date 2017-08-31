#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int       kMaxN = 10;
vector <int> ans(2003);
int dp[2003];
vector <string> pwd(kMaxN); 

// Needed for each test
int N;
bool can;
string tgt;

int backtrack(int k, int len) {
  // Check if solution
  if(dp[len] != -1) return dp[len];
  if(len == tgt.size()) {
    for(int i=0; i<=k; ++i) {
      if(i) cout << " ";
      cout << pwd[ans[i]];
    }
    cout << "\n";
    return dp[len] = 1;
  } else {
    ++k;
    bool ret = false;
    // Look for candidates and go
    for(int i=0; i<N && !can; ++i) {
      if(pwd[i].size() == 0) continue;
      if(len + pwd[i].size() > tgt.size()) continue;
      bool fit = true;
      for(int j=0; j<pwd[i].size(); ++j) {
        if(pwd[i][j] != tgt[len+j]) {
          fit = false;
          break;
        }
      }
      if(fit) {
        ans[k] = i;
        ret = backtrack(k,len+pwd[i].size());
      }
      if(ret) return dp[len] = 1;
    }
    return dp[len] = 0;
  }
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> N;
    int msk_src = 0;
    int msk_tgt = 0;
    for(int i=0; i<N; ++i) {
      cin >> pwd[i];
      for(char & c: pwd[i]) msk_src |= 1<<(c-'a');
    }
    cin >> tgt;
    for(char & c : tgt) msk_tgt |= 1<<(c-'a');
    for(int i=0; i<N; ++i) {
        if(tgt.find(pwd[i]) == string::npos) {
            pwd[i] = "";
        }
    }
    can = false;
    if( (msk_tgt&msk_src) == msk_tgt) {
     memset(dp, -1, sizeof dp);
     can = backtrack(-1, 0);
    }
    if(!can) cout << "WRONG PASSWORD\n";
  }
  return 0;
}

