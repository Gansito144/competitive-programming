#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>


using namespace std;


class CheeseSlicing{
    public:
        int dp[102][102][102], s;
          int solve(int vv[3]) {
            int v[3] = {vv[0],vv[1],vv[2]};
            sort(v, v+3);
            if(v[0] < s) return 0;
            int &ret = dp[ v[0] ][ v[1] ][ v[2] ];
            if(ret != -1) return ret;
            ret = 0;
            v[0] -= s;
            ret = max(ret, v[1]*v[2] + solve(v));
            v[0] += s;
            v[1] -= s;
            ret = max(ret, v[0]*v[2] + solve(v));
            v[1] += s;
            v[2] -= s;
            ret = max(ret, v[0]*v[1] + solve(v));
            v[2] += s;
            return ret;
          }

          int totalArea(int A, int B, int C, int S) {
            memset(dp, -1, sizeof dp);
            int v[3] = {A,B,C};
            s = S;
            return solve(v);
          }
};


int main() {
  int a, b, c, s;
  class CheeseSlicing cs;
  while(cin >> a >> b >> c >> s) {
    printf("%d\n",cs.totalArea(a,b,c,s));
  }
  return 0;
}

