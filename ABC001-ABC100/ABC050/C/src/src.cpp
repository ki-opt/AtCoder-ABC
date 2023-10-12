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
	ll N;
	cin >> N;
	vector<ll> A(N), check(N,0);
	rep(i,N) {
		cin >> A[i];
		check[A[i]]++;
	}
	
	vector<ll> cnt(N,0);
	if (N % 2 == 0) {
		for (int i = 1; i < N; i+=2) {
			if (check[i] > 1) {
				cnt[i] = check[i];	// abs(i-(N-1-i))
			} else {
				cout << 0 << endl;
				return 0;
			}
		}
	} else {
		for (int i = 0; i < N; i+=2) {
			if (check[i] > 0) { 
				cnt[i] = check[i]; 
			} else {
				cout << 0 << endl;
				return 0;
			}
		}
	}

	ll ans = 0;
	if (N % 2 == 0) {
		ans = 1;
		ll tmp;
		for (int i = 1; i < N; i+=2) {
			tmp = cnt[i] * (cnt[i] - 1);
			ans = (ans * tmp) % ((ll)pow(10,9)+7);
		}
	} else {
		ans = cnt[0] % ((ll)pow(10,9)+7);
		ll tmp;
		for (int i = 2; i < N; i+=2) {
			tmp = cnt[i] * (cnt[i] - 1);
			ans = (ans * tmp) % ((ll)pow(10,9)+7);
		}
	}
	cout << ans << endl;
}