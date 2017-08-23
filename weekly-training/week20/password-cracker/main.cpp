#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int       kMaxN = 10;
vector <int>     ans(2003);
vector <string> pwd(kMaxN); 

// Needed for each test
int N;
bool can;
string tgt;

void backtrack(int k, int len) {
  // Check if solution
  if(len == tgt.size()) {
    for(int i=0; i<=k; ++i) {
      if(i) cout << " ";
      cout << pwd[ans[i]];
    }
    cout << "\n"; can = true;
  } else {
    ++k;
    // Look for candidates and go
    for(int i=0; i<N && !can; ++i) {
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
        backtrack(k,len+pwd[i].size());
      }
    }
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
    for(char & c: tgt) msk_tgt |= 1<<(c-'a');
    can = false;
    if( (msk_tgt&msk_src) == msk_tgt) backtrack(-1, 0);
    if(!can) cout << "WRONG PASSWORD\n";
  }
  return 0;
}

