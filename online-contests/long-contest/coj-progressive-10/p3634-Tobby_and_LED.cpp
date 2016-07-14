/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Using modular arithmetic, calculate 
 * the string representation after R displacement.  
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int i64;

int main() {
   i64 t;
   int n, k, sg, p;
   // problem state fast I/O
   char str[123456], mov;
   while(gets(str)){
      sscanf(str,"%d %lld %c",&n,&t,&mov);
      gets(str);
      puts(str);
      gets(str);
      t = t % (i64) n;
      k = t;
      t = (t << 1) % n;
      sg = (mov == 'L') ? 1 : -1;   
      for(int i=0; i<n; ++i) {
         p = ((i + sg*k)+n) % n;
         p = (p<<1) + 1;
         printf("|%c",str[p]);
      }
      puts("|");
      gets(str);
      puts(str);
   }
   return 0; 
}

