## [Tanques](https://omegaup.com/arena/problem/tanques#problems)

### Descripción
    Dada la descripción de una lista de tanques[coordenadas] puntos(Xi,Yi), debemos desplazarnos a
    cada uno de ellos y destruirlos, ya sea compartiendo coordenadas X o Y. ¿Cuál es el mínimo total
    de desplazaientos que debemos realizar para eliminar todos los tanques?


### Límites
* 2 ≤ Tanques ≤ 5000
* -1000 ≤ x,y ≤ 1000

### Análisis
Para la resolución de este problema se utiliza una técnica llamada [Programación dinámica](https://en.wikipedia.org/wiki/Dynamic_programming), para ellos nos apoyamos en el hecho de que para destruir el  **i-ésimo**  tanque, sólo es posible llegar desde una de las *2001* posibles coordenadas en **X** o en **Y**. 


### Código
```cpp
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define X 0
#define Y 1

using namespace std;

const int offset = 1000;
const int oo = 2e9;
const int  M = 2001;
const int  N = 5003;

int dp[2][M][2];
int cr[2][M][2];

int main() {
  int n, ans = oo, pr = 1, nw = 0, tx, ty;
  int ncost, other;
  scanf("%d",&n);
  for(int i=0; i<M; ++i) {
    dp[nw][i][X] = oo;
    dp[nw][i][Y] = oo;
  }
  dp[nw][offset][X] = dp[nw][offset][Y] = 0;
  cr[nw][offset][X] = cr[nw][offset][Y] = offset;
  for(int t=1; t<=n; ++t) {
    swap(pr, nw);
    scanf("%d %d",&tx,&ty);
    tx += offset;
    ty += offset;
    for(int i=0; i<M; ++i) {
      dp[nw][i][X] = oo;
      dp[nw][i][Y] = oo;
    }
    for(int i=0; i<M; ++i) {
      // Coming from X
      if(dp[pr][i][X] != oo) {
        // End in prv X
        ncost = dp[pr][i][X] + abs(cr[pr][i][X]-ty);
        if(ncost < dp[nw][i][X]) {
           dp[nw][i][X] = ncost;
           cr[nw][i][X] = ty;
        }
        if(ncost < dp[nw][ty][Y]) {
           dp[nw][ty][Y] = ncost;
           cr[nw][ty][Y] = i;
        }
        // End in cur X
        ncost = dp[pr][i][X] + abs(i-tx);
        if(ncost < dp[nw][tx][X]) {
           dp[nw][tx][X] = ncost;
           cr[nw][tx][X] = cr[pr][i][X];
        }
        other =  cr[pr][i][X];
        if(ncost < dp[nw][other][Y]) {
           dp[nw][other][Y] = ncost;
           cr[nw][other][Y] = tx;
        }
      }
      // Coming from Y
      if(dp[pr][i][Y] != oo) {
        // End in prv Y
        ncost = dp[pr][i][Y] + abs(cr[pr][i][Y]-tx);
        if(ncost < dp[nw][i][Y]) {
           dp[nw][i][Y] = ncost;
           cr[nw][i][Y] = tx;
        }
        if(ncost < dp[nw][tx][X]) {
           dp[nw][tx][X] = ncost;
           cr[nw][tx][X] = i;
        }
        // End in cur Y
        ncost = dp[pr][i][Y] + abs(i-ty);
        if(ncost < dp[nw][ty][Y]) {
           dp[nw][ty][Y] = ncost;
           cr[nw][ty][Y] = cr[pr][i][Y];
        }
        other = cr[pr][i][Y];
        if(ncost < dp[nw][other][X]) {
           dp[nw][other][X] = ncost;
           cr[nw][other][X] = ty;
        }
      }
    }
  }
  for(int i=0; i<M; ++i) {
    ans = min(ans, dp[nw][i][X]);
    ans = min(ans, dp[nw][i][Y]);
  }
  printf("%d\n",ans);
  return 0;
}
```
