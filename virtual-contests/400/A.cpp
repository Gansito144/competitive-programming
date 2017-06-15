#include <iostream>
#include <string>
#include <vector>

using namespace std;

char m[13][13];

int main() {
  int T;
  int d[] = {12, 6, 4, 3, 2, 1};
  string s;
  cin >> T;
  while(T--) {
    cin >> s;
    vector <int> ans;
    for(int i=0; i<6; ++i) {
      int sol = 0;
      for(int m=0; m<d[i]; ++m){
        int cnt = 0;
        for(int j=0;j<12; ++j) {
          cnt += ((j%d[i])==m) && (s[j]=='X');
        }
        //cout << d[i] << ":d " << m << ":m " << cnt << endl;
        if(cnt == (12/d[i])) {
          sol = 1;
          break;
        }
      }
      if(sol) {
        ans.push_back(12/d[i]);
      }
    }
    cout << ans.size();
    for(int i=0; i<ans.size(); ++i) {
      cout << " " << ans[i] <<"x" << 12/ans[i];
    }
    cout << endl;
  }
  return 0;
}

