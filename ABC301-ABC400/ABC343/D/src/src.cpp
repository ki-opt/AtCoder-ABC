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
#include <set>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, T; cin >> N >> T;
	vector<ll> A(T), B(T);
	rep(i,T) {
		cin >> A[i] >> B[i];
		A[i]--;
	}

	vector<ll> tokuten(N,0);
	map<ll,ll> mp;
	rep(i,N) mp[0]++;
	rep(i,T) {
		mp[tokuten[A[i]]]--;
		if (mp[tokuten[A[i]]] == 0) mp.erase(tokuten[A[i]]);
		tokuten[A[i]] += B[i];
		mp[tokuten[A[i]]]++;
		cout << mp.size() << endl;
	}

	return 0;
}