#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <queue>
#include <map>

using namespace std;
using vs = vector< string >;
using vb = vector< bool >;
using vvb = vector < vb >;
using vi = vector< int >;
using vvi = vector< vi >;
using msi = map<string, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  const int oo = 12345678;
  int N;
  cin >> N;

  vs files( N );
  vvi G( N );
  vvb E(N, vb(N));
  msi file_id;

  for (int u = 0; u < N; ++u) {
    cin >> files[ u ];
    file_id[ files[ u ] ] = u;
  }

  int K;
  string file, line;
  for (int u = 0; u < N; ++u) {
    cin >> file >> K;
    cin.ignore();
    for (int j = 0; j < K; ++j) {
      getline(cin, line);
      line = line.substr( 7 ); // Removing "import "
      replace(line.begin(), line.end(), ',', ' ');
      istringstream in( line );
      while (in >> file) {
        int v = file_id[ file ];
        G[ u ].push_back( v );
        E[ u ][ v ] = true; 
      }
    }
  }

  int ans = -1;
  int best = oo;
  for (int i = 0; i < N; ++i) {
    // BFS For the Win.
    vi dist(N, oo);
    dist[ i ] = 0;
    queue < int > Q;
    Q.push( i );
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (const int &v : G[ u ]) {
        if (dist[ v ] == oo) {
          Q.push( v );
          dist[ v ] = dist[ u ] + 1;
        }
      }
    }
    // Calculate cycles lenght
    int cost = oo;
    for (int j = 0; j < N; ++j) {
      if (dist[ j ] != oo && E[ j ][ i ]) {
        cost = min(dist[ j ] + 1, cost);
      }
    }
    if (cost < best) {
      ans = i;
      best = cost;
    }
  }
  // Solution
  if (ans == -1) {
    cout << "SHIP IT\n";
  } else {
    // BFS For the Win.
    vi dist(N, oo);
    vi path(N, -1);
    dist[ ans ] = 0;
    queue < int > Q;
    Q.push( ans );
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (const int &v : G[ u ]) {
        if (dist[ v ] == oo) {
          Q.push( v );
          dist[ v ] = dist[ u ] + 1;
          path[ v ] = u;
        }
      }
    }
    // Get the best cycle.
    int cost = oo;
    int bb = -1;
    for (int j = 0; j < N; ++j) {
      if (dist[ j ] < cost && E[ j ][ ans ]) {
        cost = dist[ j ];
        bb = j;
      }
    }
    vector < int > sol;
    while (bb != ans) {
      sol.push_back( bb );
      bb = path[ bb ];
    }
    reverse(sol.begin(), sol.end());
    cout << files[ ans ];
    for (const int & u : sol) cout << " " << files[u];
    cout << "\n";
  }

  return 0;
}


