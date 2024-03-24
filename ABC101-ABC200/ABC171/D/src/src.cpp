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
	vector<ll> A(N);
	vector<ll> val(100001,0);
	ll sum = 0;
	rep(i,N) {
		cin >> A[i];
		val[A[i]]++;
		sum += A[i];
	}
	ll Q; cin >> Q;
	rep(i,Q) {
		ll b, c; cin >> b >> c;
		sum -= val[b] * b;
		sum += val[b] * c;
		val[c] += val[b];
		val[b] = 0;
		cout << sum << endl;
	}

	return 0;
}