/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Compute the pascal triangle
 * calculate f(n) = 1 + C(n,2) + C(n,4) 
 * Source: https://oeis.org/A000127  
*/

#include <iostream>
#include <cstdio>
#define N 203

using namespace std;

typedef long long int i64;

i64 C[N][5];

void partial_pascal(){
   for(int i=0; i<N; ++i) {
      for(int j=0; j<=i && j<5; ++j){
         C[i][j] = (j==0||j==i)?1LL:C[i-1][j-1]+C[i-1][j];  
      }
   }
}

int main() {
   partial_pascal();
   int cases, n;
   scanf("%d",&cases);
   while(cases--) {
      scanf("%d",&n);
      printf("%lld\n",C[n][2] + C[n][4] + 1LL);
   }
   return 0; 
}

