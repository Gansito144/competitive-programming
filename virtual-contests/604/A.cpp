#include <stdio.h>
#include <iostream>
#include <math.h> 
#include <algorithm>

using namespace std;

const int kPr = 5;

int main() {
  double m[kPr], w[kPr], ans = 0.0f;
  double x[kPr] = {500, 1000, 1500, 2000, 2500}; 

  for(int i=0; i<kPr; ++i) {
    cin >> m[i];
  }

  for(int i=0; i<kPr; ++i) {
    cin >> w[i];
    ans += max(0.3f*x[i], ((1.0f-(m[i]/250.0f))*x[i])-50.0f*(w[i]));
  }

  double sh, uh;
  cin >> sh >> uh;
  ans += (sh*100.0f) - (uh*50.0f);
  printf("%d\n",(int)(ans));
  return 0;
}


