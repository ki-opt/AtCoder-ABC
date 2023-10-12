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

#define teisu ((ll)pow(10,9)+7)

int main() {
	ll N;
	cin >> N;

	vector<ll> sosu;
	sosu.push_back(2);
	repp(i,3,N+1) {
		bool is_prime = true;
		repp(j,2,i) {
			if (i%j == 0) { is_prime = false; break; }
		}
		if (is_prime) sosu.push_back(i);
	}

	vector<ll> check(N+1,0);
	repp(i,2,N+1) {
		for (auto val : sosu) {
			ll cnt = 1;
			while (i % ((int)pow(val,cnt)) == 0) {
				cnt++;
			}
			check[val] += cnt - 1;
		}
	}

	ll ans = 1;
	for (auto val : check) {
		if (val > 0) {
			ans = (ans * (val + 1)) % teisu;
		}
	}
	cout << ans << endl;
	return 0;
}