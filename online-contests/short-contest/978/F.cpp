#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
using i64 = long long int;

vector <int> a, p, c, ans;

bool cmp (const int &i, const int &j)
{
  return a[i] < a[j];
}

int main ()
{
  int n, m;
  scanf("%d %d",&n,&m);
  a.assign(n, 0); p.assign(n, 0);
  c.assign(n, 0); ans.assign(n, 0);

  for (int i=0; i<n; ++i)
  {
    p[i] = i;
    scanf("%d",&a[i]);
  }

  int u, v;
  while (m--)
  {
    scanf("%d %d",&u,&v);
    --u; --v;
    if (a[u] > a[v]) ++c[u];
    else if(a[v] > a[u]) ++c[v];
  }

  sort(p.begin(), p.end(), cmp);

  int cnt = 0, pr = -1, j;
  for (int i=0; i<n; ++i)
  {
    j = p[i];
    cnt = (pr == a[j]) ? cnt + 1 : 1;
    pr = a[j];
    ans[j] = ((i+1 - cnt) - c[j]);
  }
  for (const int &ai: ans) printf("%d ", ai);
  puts("");

  return 0;
}

