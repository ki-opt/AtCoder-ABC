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
	if (N % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = N / 10;
	N /= 10;
	ll p = 5;
	while (p <= N) {
		ans += N / p;
		p *= 5;
	}
	/*ll ans = 0, val = 10, kisu = 10, zero = 1;
	while (val <= N) {
		for (int i = 0; i < 10 && val <= N; i++) {
			ans += zero;
			val += kisu;
		}
		kisu *= 10;
		val = kisu;
		zero++;
	}
	/*
	ll keta = 0, tmp = N;
	while (tmp != 0) {
		tmp /= 10;
		keta++;
	}
	*/
	cout << ans << endl;
	
	return 0;
}