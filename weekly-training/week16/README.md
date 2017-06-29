## Week 15

Para esta semana los dos problemas propuestos nos enseñarán a combinar lo mejor de dos técnicas para resolución de problemas: **Programación dinámica** y **Greedy**.

### 1.- [Sherlock & Cost](https://www.hackerrank.com/challenges/sherlock-and-cost)
#### Problema:
Lo primero es entender el problema: Se nos pide construir una secuencia **A = {A1, A2, A3, ..., An}** donde cada **Ai** puede ser un número natural entre **1** y **Bi** de tal manera que la sumatoria del valor absoluto de la diferencia de los los elementos continuos de **A** sea la máxima.

#### Observaciones:
* Para el caso cuando **n=1**: No importa que valor del rango **[1,B1]** elijamos el resultado es **0**.
* Cuando **n=2**: podemos realizar **B1xB2** parejas, sin embargo aquellas que pueden maximizar la diferencia se encuentran en los extremos, es decir **S = max(|1-B2|, |B1-1|)** (*Greedy*).
* Del punto anterior podríamos pensar en generalizar la elección de manera *Greedy*, esto es, realizar una especie de *zig-zag* sobre la secuencia **B**, esta idea se desvanece con el siguiente contraejemplo **B={1,12,1,1,17}** ya que con el approach *Greedy* generaríamos las secuencias **Aa={1,12,1,1,1}** y **Ab={1,1,1,1,17}** cuyas diferencias serían **Sa=22** y **Sb=16**, sin embargo la diferencia máxima se obtiene de **Ac={1,12,1,1,17}**, **Sc=38**, con esto podemos descartar el enfoque **Greedy** en general.
* Pero podemos notar que la elección *greedy* de los extremos aún se conserva con la límitante de que es necesario revisar ambos extremos para cada posición **2<=i<=n**, es decir obtenemos la siguiente recurrencia:
  * **dp(i,0)=max(dp(i-1,0), dp(i-1,1)+b_{i-1}-1)**
  * **dp(i,1)=max(dp(i-1,0)+b_{i}-1, dp(i-1,1)+|b_{i}-b_{i-1}|)**
* Hay que notar el truco en la reducción de la segunda parte del estado, un **0** indica que el valor de **A** en la posición **i** es **1**, y un **1** que su valor será igual al valor de **Bi**.

#### Solución ([Full](https://github.com/Gansito144/competitive-programming/blob/master/weekly-training/week16/sherlock-and-cost/main.cpp)):
```cpp
  for(int i=1; i<=n; ++i) {
    scanf("%d",&b[i]);
    if(i == 1) continue;
    dp[now][0] = max(dp[old][0], dp[old][1]+b[i-1]-1);
    dp[now][1] = max(dp[old][0]+b[i]-1, dp[old][1]+abs(b[i]-b[i-1]));
    swap(old,now);
  }
  printf("%d\n",max(dp[old][0],dp[old][1]));
```


### 2.- [Reverse Shuffle Merge](https://www.hackerrank.com/challenges/reverse-shuffle-merge)
#### Problema:
Encontrar la menor cadena lexicográficamente **A** tal que **S=_merge_(_reverse_(A), _shuffle_(A))**.

#### Observaciones:
Dado los límites de las cadena original (**|S|<10^4**) podemos descartar una solución a fuerza bruta, así que es mejor comenzar listando algunas observaciones, pero para facilitar su concepción hagámoslo sobre un ejemplo de entrada **S=aahaxxxhxhxxah**:

* Sabemos que por cada letra en **S** la respuesta **Ans** contendrá  exactamente la mitad de carácteres, en nuestra **S** de ejemplo hay *4a's*, *4h's* y *4x's*, por lo que nuestra respuesta se compondrá de *2a's*, *2h's* y *2x's*. 
* Ahora conocemos el tamaño de nuestra respuesta y las letras que las componen, la cadena lexicográficamente menor sería **lmin = aahhxx**, pero esta no es una respuesta válida. **¿Por qué?** porque al hacer la operación _reverse_(A) nos quedaría una cadena **xxhhaa** la cuál no es una subsequencia de nuestra cadena **S**.
* Del paso anterior notamos otra carácteristica importante, la influencia de _shuffle_(A) únicamente nos permite buscar a _reverse_(A) como subsequencia, por lo cuál no le prestaremos mucha atención a esta parte y en cambio debemos hallar una forma más fácil de decir si cierta letra puede ser utilizada o no.
* Una forma de lograrlo es con la ayuda de prefix sum, para ello contabilizamos la frecuencia de cada una de las letras para las distintas posiciones de **i** en **S**,luego una vez que estamos en un rango [0,L] en donde se encuentran todas las letras que necesitamos, es claro que podemos construir la respuesta eligiendo de manera greedy la menor letra que se encuentre en el rango [L,R).
* **¿Cómo manejamos los indices L, R?** Nos auxiliamos de un arreglo con las frecuencias necesarias para cada letra, inicialmente desplazamos **L** de **0** hacia la derecha hasta que para cada **k (0<=k<26)** se cumpla **cnt[k][i] >= need[k]**, **R** por su parte inicia al final de la cadena.
* Del mismo modo para saber que letra es la siguiente a concatenar se hace un barrido comenzando por la menor y la primera cuya cuenta **cnt[R]-cnt[L-1]** sea positiva, será la cuál debemos imprimir/concatenar.
* La solución esta casi lista, sólo es necesario actualizar L, ya que al procesar una letra, las anteriores pueden ser parte del _suffle_, por lo cuál es necesario volver a revisar, lo mismo para R, debemos actualizarlo a una posición anterior a donde encontramos la letra impresa/concatenada.


#### Solución ([Full](https://github.com/Gansito144/competitive-programming/blob/master/weekly-training/week16/reverse-shuffle-merge/main.cpp)):
```cpp
  //Find left boundary
  int L = 1, R = N;
  while(!check(L)) L++;

  // String answer construction
  while(ANS.size() < n) {
    for(int k=0; k<n; k++) {
      if(T[k] == '*') continue;
      chr = T[k] - 'a';
      if(cnt[chr][R] - cnt[chr][L-1]) {
        ANS += T[k];
        // Set the new boundaries
        need[chr]--;
        while(check(L-1)) L--;
        while(S[R-1] != T[k] ) R--;
        R--;
        T[k] = '*';
        break;
      }
    }
  }
  cout << ANS << endl;
```