/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Probability
 * Ulises Tirado formula
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm> 

using namespace std;

int main() {
   double xa, ya, xb, yb, a, b, ans;
   while(scanf("%lf %lf %lf %lf",&xa,&ya,&xb,&yb) == 4) {
      a = xb - xa;
      b = yb - ya;
      ans = ((a*a)+(b*b))/6.0f;
      printf("%.10lf\n",ans);
   }

   return 0;
}