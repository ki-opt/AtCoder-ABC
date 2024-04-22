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
#include <math.h>
#include <float.h>
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
	ll N; cin >> N;
	vector<ll> A(N), a(N); rep(i,N) cin >> A[i];
	rep(i,N) a[i] = A[i] % 200;

	vector<ll> amari(200);
	amari[a[0]]++;
	ll ans = 0;
	repp(i,1,N) {
		/*
		if (a[i] == 0) ans += amari[0];
		else ans += amari[200-a[i]];
		*/
		ans += amari[a[i]];
		amari[a[i]]++;
	}
	cout << ans << endl;

	return 0;
}