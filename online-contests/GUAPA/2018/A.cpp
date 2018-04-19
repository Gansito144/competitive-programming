#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

inline double heron (double A, double B, double C)
{
  double S = (A+B+C) / 2.0f;
  return sqrt(S*(S-A)*(S-B)*(S-C));
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  const double PI = M_PI;
  int tcs;
  double ab, bc, ca, mc, nc;
  cin >> tcs;
  while (tcs--)
  {
    cin >> ab >> bc >> ca >> mc >> nc;
    double am = ca - mc;
    double bn = bc - nc; 

    double A  = acos((ca*ca+ab*ab-bc*bc) / (ab*ca*2.0f));
    double C = acos ((bc*bc+ca*ca-ab*ab) / (bc*ca*2.0f));

    double bm = sqrt((ab*ab)+(am*am)-(ab*am)*2.f*cos(A));
    double mn = sqrt((mc*mc)+(nc*nc)-(mc*nc)*2.f*cos(C));

    vector <double> V(3);
    V[0] = heron (ab, bm, am);
    V[1] = heron (bm, mn, bn);
    V[2] = heron (nc, mc, mn);

    sort(V.begin(), V.end());
    for(const double &a: V) cout << setprecision(20) << a << endl;
  }
  return 0;
}
