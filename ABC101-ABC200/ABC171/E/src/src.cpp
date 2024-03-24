#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N; cin >> N;
	vector<ll> a(N);
	ll ans = 0;
	rep(i,N) {
		cin >> a[i];
		ans = ans ^ a[i];
	}

	rep(i,N) {
		cout << (ans ^ a[i]) << " ";
	}
	cout << endl;


	return 0;
}