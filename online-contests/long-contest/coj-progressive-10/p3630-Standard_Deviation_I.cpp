/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Math, simplify formula.
 * Average of n odd numbers is n
*/

#include <cstdio>
#include <cmath>
#include <algorithm> 

using namespace std;

int main() {
	int k;
	double two=2.0f, three=3.0f, one=1.0f;
	while( scanf("%d",&k), k ) {
		double sum = two, ans, n = (k>>1), nn = (k-1);
		// Apply sum of even numbers
		if(k & 1) {
			sum *= (two*n) * (n+one) * (two*n+one);
		} else { // Apply sum of odd numbers
			sum *= n * (two*n-one) * (two*n+one);
		}
		sum /= three;
		sum /= nn;
		printf("%.6lf\n",sqrt(sum));
	}
	return 0;
}