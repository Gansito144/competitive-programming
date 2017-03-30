#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MaxN  = 1000006;
int scream[MaxN];

int main() {
  int a, b, c, d, t;
  cin >> a >> b;
  cin >> c >> d;


  if( (d-b) % __gcd(a,c)) {
    puts("-1");
  } else {
    while(b != d) {
      if(b < d) b += a;
      else d += c;
    }
    printf("%d\n",b);
  }

  return 0;
}

