#include <stdio.h>
#include <iostream>

using namespace std;

const int maxDays = 1000006;
const int oo = 2e8;
char line[maxDays];
int day[maxDays];
int chgs[maxDays][2];
int cnts[maxDays][2];
int K, no_days;

const bool dbg = true;//false;

int func(int con) {
  if(con == 0) return 0;
  int n = no_days - 1;
  chgs[0][0] = day[0] != 0;
  cnts[0][0] = cnts[0][1] = 1;
  chgs[0][1] = day[0] != 1;
  for(int i=1; i<= n; ++i)
  {
    for(int d=0; d<2; ++d) {
      int op = 1-d;
      if(day[i] == d)
      {
        if(cnts[i-1][d] == con) {
          // No option came from opposite
          chgs[i][d] = chgs[i-1][op];
          cnts[i][d] = 1;
        } else {
          // Choose the best
          if(chgs[i-1][op] <= chgs[i-1][d]) {
            chgs[i][d] = chgs[i-1][op];
            cnts[i][d] = 1;
          } else { // Come from the same
            chgs[i][d] = chgs[i-1][d];
            cnts[i][d] = cnts[i-1][d] + 1;
          }
        }
      } else {
        chgs[i][d] = chgs[i-1][op] + 1;
        cnts[i][d] = 1;
      }
      if(dbg)printf("** s(%d) i(%d)[%d] => chg(%d),cnt(%d)\n",day[i],i,d,chgs[i][d],cnts[i][d]);
    }
  }
  if(dbg)printf("con(%d), chgs(%d)\n\n",con, min(chgs[n][0], chgs[n][1]));
  return min(chgs[n][0], chgs[n][1]) <= K; 
}

int main()
{
  int no_cases, ans;

  sscanf(gets(line),"%d",&no_cases);
  while(no_cases--)
  {
    sscanf(gets(line),"%d %d",&no_days, &K);
    gets(line);
    // Transform to {0,1}
    for(int i=0; i<no_days; ++i) {
      day[i] = line[i]-'0';
    }
    // Binary Search
    ans = (1 << 21)-1;
    for(int b=20; b>=0; --b)
    {
      ans ^= func(ans ^(1<<b)) << b;
    }
    printf("%d\n",ans);
  }

  return 0;
}

