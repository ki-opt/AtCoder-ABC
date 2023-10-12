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
	ll N, M;
	cin >> N >> M;
	if (N >= M + 2 || M >= N + 2) {
		cout << 0 << endl;
		return 0;
	}
	
	if (N < M) swap(N,M);
	ull ans = 1;
	if (N != M) {
		for (int i = 0; i < N; i++) {
			if (M - i > 0) {
				ans = (ans * (N-i) * (M-i)) % ((ll)pow(10,9)+7);
			} else {
				ans = (ans * (N-i) * 1) % ((ll)pow(10,9)+7);
			}
		}
	} else {
		for (int i = 0; i < N; i++) {
			ans = (ans * (N-i) * (M-i)) % ((ll)pow(10,9)+7);
		}
		ans = (2 * ans) % ((ll)pow(10,9)+7);
	}
	cout << ans << endl;

	return 0;
}