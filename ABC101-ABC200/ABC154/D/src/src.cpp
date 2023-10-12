#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int N, K;
	cin >> N >> K;
	vector<long int> p(N);
	rep(i,N) cin >> p[i];

	long int max_val = 0, max_index = 0;
	rep(i,K) max_val += p[i];

	long int tmp = max_val;
	repp(i,N-K+1,1) {
		tmp = tmp - p[i-1] + p[i+K-1];
		if (tmp > max_val) {
			max_val = tmp;
			max_index = i;
		}
	}

	double ans = 0;
	repp(i,max_index+K,max_index) {
		repp(j,p[i]+1,1) ans += (1.0 / p[i]) * (double)j;
	}

	printf("%.10f\n", ans);

	return 0;
}