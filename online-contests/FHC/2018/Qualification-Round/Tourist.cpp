/* ******************************* *
 * Copyright © 2018                *
 * Author: Ulises Mendez Martinez  *
 * Email: ulisesmdzmtz@gmail.com>  *
 * All rights reserved.            *
 * ******************************* */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using i64 = long long int;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tcs;
  cin >> tcs;
  
  for (int tc=1; tc<=tcs; ++tc) {
    i64 n, k, v;
    cin >> n >> k >> v;
    vector <string> vs(n);
    vector <int> ans(k);
    for (string &vsi : vs) cin >> vsi;
    i64 id = (v-1LL) * k;
    id = (id % n == 0LL) ? n : id % n;
    --id;
    for (int i=0; i<k; ++i) {
      id = (id == (n-1LL)) ? 0LL : id + 1LL;
      ans[i] = id;
    }
    sort (ans.begin(), ans.end());
    cout << "Case #" << tc << ":";
    for (int i=0; i<k; ++i)
      cout << " " << vs[ans[i]];
    cout << endl;
  }
  return 0;
}

