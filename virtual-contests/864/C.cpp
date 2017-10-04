#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
  int a, b, f, k, ans=0;

  cin >> a >> b >> f >> k;
  int tank = b;
  int pos = 0;
  int F = a-f;
  for(int l=1; l<=k; ++l)
  {
    if(pos == 0) {
      if(k == l) {
        if(tank >= a) continue;
        else {
          if(tank < f) {ans = -1; break;}
          if(b < F) {ans = -1; break;}
          ++ans;
        }
      } else {
        if(tank >= (a+F)) {
          tank -= a;
        } else {
          if(tank < f) {ans=-1; break;}
          if(b < F+F) {ans=-1; break;}
          ++ans;
          tank = b - F;
          if(tank < 0) {ans=-1; break;}
        }
      }
    } else {
      if(k == l) {
        if(tank >= a) continue;
        else {
          if(tank < F) {ans = -1; break;}
          if(b < f) {ans = -1; break;}
          ++ans;
        }
      } else {
        if(tank >= (a+f)) {
          tank -= a;
        } else {
          if(tank < (F)) {ans=-1; break;}
          if(b < (f+f)) {ans = -1; break;}
          ++ans;
          tank = b - f;
          if(tank < 0) {ans=-1; break;}
        }
      }
    }
    pos = a - pos;
  }
  cout << ans << endl;
  return 0;
}

