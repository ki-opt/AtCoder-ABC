#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, K;
	cin >> N >> K;

	if (K == 0) {
		cout << N * N << endl;
		return 0;
	}

	ll ans = 0;
	for (int b = K+1; b <= N; b++) {
				
	}
	cout << ans << endl;
	return 0;
}