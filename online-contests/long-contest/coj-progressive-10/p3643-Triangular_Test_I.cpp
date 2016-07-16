/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Maximum numbers needed to
 * sum up N is 3.
 * Source: https://en.wikipedia.org/wiki/
 * Fermat_polygonal_number_theorem
*/

#include <cstdio>
#include <bitset>

using namespace std;

#define N 10000007

bitset < N > isTri;

int main() {
	int n;
	isTri.reset();
	for (int i=0, j=0; (j+=i) <N; ++i)
		isTri[j]=1;

	while (scanf("%d", &n) == 1){
		if (isTri[n]){
			printf("1\n");
			continue;
		}
		
		int i, j;
		for (i = 0, j = 0; (j += i) <= n; ++i)
			if (isTri[n-j])
				break;

		if (n-j >= 0)
			printf("2\n");
		else
			printf("3\n");
	}
}