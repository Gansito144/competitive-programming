#include <iostream>
#include <string>

using namespace std;

int main() {
  string  num;
  int ans = 0, carry=0;
  cin >> num;
  if(num == "1") {
    cout << 0 << endl;
    return 0;
  }
  for(int i=num.size()-1; i>=0; --i) {
    int d = num[i] - '0';
    if(d + carry == 0) {
      ++ans;
    } else {
      if(i == 0) {
        ans += carry;
      } else {
        ans += (d+carry == 2) ? 1 : 2;
      }
      carry = 1;
    }
    //cout<<i<<" "<<num[i]<<" "<<d<<" "<<carry<<" "<<ans<<endl;
  }
  cout << ans << endl;
  return 0;
}

