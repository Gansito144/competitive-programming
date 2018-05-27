#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  double x1, x2, x3, v1, v2, eps = 1e-9;

  cin >> n;

  while (n--)
  {
    cin >> x1 >> x2 >> x3 >> v1 >> v2;

    double ct = fabs(x1 - x3) / v1;
    double kt = fabs(x2 - x3) / v2;

    if (abs(ct-kt) < eps)
     cout << "Draw" << endl;
    else if (ct < kt)
      cout << "Chef" << endl;
    else
      cout << "Kefa" << endl;
  }

  return 0;
}

