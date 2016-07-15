/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Use greedy to select the elephants
 * with less weight, then lineal iteration to know index  
*/

#include <iostream>
#include <cstdio>
#include <algorithm> 

using namespace std;

typedef long long int i64;

int main() {
   int cases, elph[123456], ne, i;
   i64 tot_w, max_w;

   scanf("%d",&cases);
   while(cases--) {
      scanf("%d %lld",&ne,&max_w);
      for(i=0; i<ne; ++i) {
         scanf("%d",&elph[i]);
      }
      sort(elph, elph+ne);
      tot_w = 0;
      for(i=0; i<ne && (tot_w+elph[i])<= max_w; ++i) {
         tot_w += elph[i];
      }
      printf("%d\n",i);
   }
   return 0; 
}

