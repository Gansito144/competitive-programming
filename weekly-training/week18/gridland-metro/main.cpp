#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long int i64;
typedef pair<int,int> ii;

bool cmp(ii &a, ii&b) {
  return (a.second != b.second)
    ? a.second < b.second
    : a.first  < b.first;
}

void normalize( vector<ii> & v) {
  sort(v.begin(), v.end(), cmp);
  vector <ii> ans;
  for(int i=0; i<v.size(); ++i) {
    while(ans.size() > 0 && v[i].F <= ans.back().S) {
      ii tmp = ans.back(); ans.pop_back();
      v[i] = {min(v[i].F, tmp.F), max(v[i].S, tmp.S)};
    }
    ans.push_back(v[i]);
  }
  v.clear();
  v = ans;
}

int main() {
  i64 R, C, ans;
  int k;
  
  scanf("%lld %lld %d",&R,&C,&k);
  ans = R*C;
  map< int, vector<ii> > rows;
  int row, bgn, end;
  while(k--) {
    scanf("%d %d %d",&row,&bgn,&end);
    rows[row].push_back({bgn, end});
  }
  for( auto &line : rows) {
    normalize(line.second);
    for(ii &train : line.second) {
      ans -= train.second - train.first + 1;
    }
  }
  printf("%lld\n",ans);
  return 0;
}

