#include<stdio.h>
#include <iostream>

using namespace std;

typedef long long int i64;

const int MaxN = 100005;
i64 sp[MaxN];


int main() {
  int N;
  i64 mn = 1LL << 50, K;

  cin >> N >> K;
  for(int i=0; i<N; ++i) {
    cin >> sp[i];
    if(sp[i] < mn) mn = sp[i];
  }
  i64 ans = 0LL;
  for(int i=0; i<N; ++i) {
    if((sp[i]-mn)%K != 0LL) {
      ans = -1;
      break;
    }
    ans += (sp[i]-mn) / K;
  }
  cout << ans << endl;
  return 0;
}

