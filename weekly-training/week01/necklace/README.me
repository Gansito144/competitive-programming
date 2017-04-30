## [Acomoda el número](https://omegaup.com/arena/problem/AcomodandoOMI#problems)

### Descripción
    Daena tenía un collar con cuentas muy coloridas. Cada par de cuentas consecutivas
    en el collar compartía un color en común en su punto de unión. La figura de abajo
    muestra un segmento de dicho collar. Pero un día el collar se rompió y las cuentas
    quedaron dispersas. Daena hizo su mayor esfuerzo para recolectar las cuentas, pero
    no está segura de haber recolectado todas.
    El problema consiste en verificar si es posible reconstruir dicho collar.

![Neclkace image](https://github.com/Gansito144/competitive-programming/blob/master/weekly-training/week01/necklace/necklace.gif)

### Límites
* 1< N ≤ 2000
* 1 ≤ color ≤ 50

### Análisis
El problema se puede modelar como un grafo, donde cada color representa un nodo, despés de hacer este modelado nos damos cuenta que la pregunta es en realidad encontrar un recorrido de Euler[^1].

[^1]: [Wikipedia Entry](https://en.wikipedia.org/wiki/Eulerian_path).


### Código
```cpp
#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

const int N = 51;

int g[N][N], d[N];

list< int > cyc;
list<int> ::iterator it;

void euler(list<int> ::iterator i, int u) {
    for(int v=0; v<N; ++v) if( g[u][v] > 0) {
        g[u][v]--;
        g[v][u]--;
        euler(cyc.insert(i, u), v);
    }
}

int main() {
    int n, u, v, T, r, ans;
    bool can;
    
    scanf("%d",&T);
    for(int b = 0; b<T; ++b)
    {
        scanf("%d",&n);
        memset(g, 0 , sizeof g);
        memset(d, 0 , sizeof d);
        r = N;
        for(int i=0; i<n; ++i) {
            scanf("%d %d",&u,&v);
            u--; v--;
            g[u][v]++;
            g[v][u]++;
            d[u]++;
            d[v]++;
            r = min(r, min(u,v));
        }
        can = true;

        for(int i=0; i<N; ++i) can = can && (d[i]%2==0);
        printf("%sCase #%d\n",(b?"\n":""),b+1);
        if( !can ) puts("some beads may be lost");
        else {
            cyc.clear();
            euler(cyc.begin(), r);
            int fr = *cyc.begin() + 1;
            for( it = cyc.begin(); it !=cyc.end();) {
                ans = *it + 1;
                printf("%d",ans);
                it++;
                if( it == cyc.end()) break;
                ans = *it + 1;
                printf(" %d\n",ans);
            }
            printf(" %d\n",fr);
        }
    }

    return 0;
}
```


