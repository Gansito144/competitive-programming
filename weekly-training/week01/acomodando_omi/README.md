## [Acomoda el número](https://omegaup.com/arena/problem/AcomodandoOMI#problems)

### Descripción
```
Tienes una lista desordenada con N números distintos los cuales tienen valores entre 0 y M. Llamemos al primer número de esta lista a0. Debes ordenar los números de la lista y ver en qué posición queda el número a0.
```

### Límites
* 1< N ≤ 2000000
* 0 ≤ M ≤ 10^9

### Análisis
Desde que el tamaño del arreglo es del orden de 10^6, sabemos que ordenarlo sería costoso, en su lugar notamos que basta con contar cuántos elementos son menores al primer número de nuestra lista. 


### Código
```cpp
#include <stdio.h>

int main() {
    int n, a0, x, cnt = 0;
    scanf("%d %d",&n,&a0);
    for(int i=1; i<n; ++i){
        scanf("%d",&x);
        cnt += (x < a0);
    }
    printf("%d\n",cnt);
    return 0;
}
```
