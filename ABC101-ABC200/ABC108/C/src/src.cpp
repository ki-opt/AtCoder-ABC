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
	ll N, K;
	cin >> N >> K;

	ll ans = 0;
	repp(a,1,N+1) {
		for (int z = 1; z * K <= 2 * N; z++) {
			
		}
		/*
		repp(b,K-a,N+1)
		ll b = K - a;
		ll c = K - b;
		if (b <= 0 || c <= 0) break;
		if (b + c == 0 && !(a + b == K && b + c == K && c + a == K)) continue;
		if ((K % (b + c)) == 0) {
			ans++;	
		}
		*/
	}
	cout << ans << endl;
	return 0;
}