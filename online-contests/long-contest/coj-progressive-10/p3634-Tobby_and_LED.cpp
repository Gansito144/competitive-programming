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
   i64 n, t, i, k;
   // problem state fast I/O
   char str[123456], mov;
   while(gets(str)){
      sscanf(str,"%lld %lld %c",&n,&t,&mov);
      gets(str);
      puts(str);
      gets(str);
      n = (n << 1) + 1LL;
      t = (t << 1) % n;
      i = k = (mov == 'L') ? t : n-t-1LL;   
      if(k==0) i = k = n-1LL;
      //printf("n: %lld, t: %lld k: %lld\n",n,t,k);
      while(i < n) putchar(str[i++]);
      i = 1LL;
      while(i < k) putchar(str[i++]);
      puts("|");
      gets(str);
      puts(str);
   }
   return 0; 
}

