#include <stdio.h>
#include <iostream>

using namespace std;
typedef long long int i64;

int main() {
  int n, m, a;
  i64 w, h, ans;
  
  scanf("%d %d %d",&n,&m,&a);
  w = (n+a-1)/a;
  h = (m+a-1)/a;
  ans = w*h;
  cout << ans << endl;
  return 0;
}
