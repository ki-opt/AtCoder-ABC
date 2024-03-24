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

class Node{
public:
	ll s, t, p;
};
bool operator>(const Node &n1, const Node &n2) {
	if (n1.s < n2.s) return n1.s < n2.s;
	else if (n1.t < n2.t) return n1.t < n2.t;
	else return n1.p < n2.p;
}

int main() {
	ll N, W; cin >> N >> W;
	vector<ll> used(200001,0);
	rep(i,N) {
		ll S,T,P;
		cin >> S >> T >> P;
		used[S] += P;
		used[T] -= P;
	}

	ll oyu = 0;
	rep(i,200001) {
		oyu += used[i];
		if (oyu > W) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	



	return 0;
}