## Week 15

Para esta semana los dos problemas propuestos nos enseñarán a combinar lo mejor de dos técnicas para resolución de problemas: **Programación dinámica** y **Greedy**.

### 1.- [Sherlock & Cost](https://www.hackerrank.com/challenges/sherlock-and-cost)
#### Problema:
Lo primero es entender el problema: Se nos pide construir una secuencia **A = {A1, A2, A3, ..., An}** donde cada **Ai** puede ser un número natural entre **1** y **Bi** de tal manera que la sumatoria del valor absoluto de la diferencia de los los elementos continuos de **A** sea la máxima.

#### Observaciones:
* Para el caso cuando **n=1**: No importa que valor del rango **[1,B1]** elijamos el resultado es **0**.
* Cuando **n=2**: podemos realizar **B1xB2** parejas, sin embargo aquellas que pueden maximizar la diferencia se encuentran en los extremos, es decir **S = max(|1-B2|, |B1-1|)** (*Greedy*).
* Del punto anterior podríamos pensar en generalizar la elección de manera *Greedy*, esto es, realizar una especie de *zig-zag* sobre la secuencia **B**, esta idea se desvanece con el siguiente contraejemplo **B={1,12,1,1,17}** ya que con el approach *Greedy* generaríamos las secuencias **Aa={1,12,1,1,1}** y **Ab={1,1,1,1,17}** cuyas diferencias serían **Sa=22** y **Sb=16**, sin embargo la diferencia máxima se obtiene de **Ac={1,12,1,1,17}**, **Sc=38**, con esto podemos descartar el enfoque **Greedy** en general.
* Pero podemos notar que el pequño *greedy* de los extremos aún se conserva con la límitante de que es necesario revisar ambos extremos para cada posición **2<=i<=n**, es decir obtenemos la siguiente recurrencia:
  * **dp(i,0)=max(dp(i-1,0), dp(i-1,1)+b_{i-1}-1)**
  * **dp(i,1)=max(dp(i-1,0)+b_{i}-1, dp(i-1,1)+|b_{i}-b_{i-1}|)**
* Hay que notar el truco en la reducción de la segunda parte del estado, un **0** indica que el valor de **A** en la posición **i** es **1**, y un **1** que su valor será igual al valor de **Bi**.

#### Solución:
```cpp
  scanf("%d",&n);
  memset(dp,0,sizeof dp);
  now = 1, old=0;
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
#### Observaciones:
#### Solución:
```cpp
  // Read input
  cin >> S;
  N = S.size();
  // Compute the cumulative frequencies
  for(int i=1; i<=N; i++) {
    for(int k=0; k<alpha; k++)
      cnt[k][i] = cnt[k][i-1];
    chr = S[i-1]-'a';
    cnt[chr][i]++;
    need[chr]++;
  }

  // Set what is needed and the target
  for(int k=0; k<alpha; k++) {
    need[k] /= 2;
    string nw(need[k],'a'+k);
    T += nw;
    n += need[k];
  }

  //Find left boundary
  int L = 1, R = N;
  while(!check(L)) L++;

  // Lets create the string
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