#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

const int  MaxW = 17;           // Number of Words
const char MaxZ = 5;            // Alphabet size
int dp[1<<MaxW][MaxZ];          // DP Table
int queue[3<<MaxW], head, tail; //Queue

inline char getIdx(char c) {
  switch(c) {
    case 'A': return 0;
    case 'E': return 1;
    case 'I': return 2;
    case 'O': return 3;
    case 'U': return 4;
  }
}

int main() {
  int noCases, noWords, ans, size[MaxW], mask;
  char begin[MaxW], end[MaxW], word[102];
  
  scanf("%d",&noCases);
  while(noCases--) {
    // Read the problem
    scanf("%d",&noWords);
    for(int i=0; i<noWords; ++i) {
      scanf("%s",word);
      size [i] = strlen(word);
      begin[i] = getIdx(word[0]);
      end  [i] = getIdx(word[size[i]-1]);
      //printf("w(%s), b(%d), e(%d), s(%d)\n",word,(int)begin[i],(int)end[i],size [i]);
    }
    // Clean up
    for(int i=0; i<(1<<noWords); ++i)
      for(char j=0; j<MaxZ; ++j)
        dp[i][j] = 0;
    
    // Initialize queue and answer
    ans = 0; head=1; tail=0; queue[0]=0;
    while(head != tail) {                        // Not empty
      mask = queue[tail];
      //printf("mask(%d)\n",mask);
      ++tail;
      for(char vowel=0; vowel<MaxZ; ++vowel) {
        for(int wd=0; wd<noWords; ++wd) {
          if((mask>>wd) & 1) continue;       //Already taken
          if(begin[wd] != vowel) continue; //Not match
          int new_mask = mask | (1<<wd);
          int &now = dp[new_mask][end[wd]];
          int &prv = dp[mask][vowel];
          if((prv+size[wd]) > now) {
            now = prv+size[wd];
            //printf("  new_mask(%d) size(%d)\n",new_mask,now);
            ans = max(ans, now);
            queue[head] = new_mask;
            ++head;
          }
        }
      }
    }
    printf("%d\n",ans);
  }
  
  return 0;
}