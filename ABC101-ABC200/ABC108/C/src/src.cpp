#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, K;
	cin >> N >> K;

	ll ans = 0;
	ll tmp = 0;
	for (int i = 1; i <= N; i++) {
		if (i % K == 0) tmp++;
	}
	ans += (ll)pow(tmp,3);

	if (K % 2 == 0) {
		tmp = 0;
		for (int i = 1; i <= N; i++) {
			if (i % K == K / 2) tmp++;
		}
		ans += (ll)pow(tmp,3);
	}
	cout << ans << endl;


	return 0;
}