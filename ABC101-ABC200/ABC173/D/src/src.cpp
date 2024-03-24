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
	rep(i,N) cin >> A[i];
	sort(A.begin(),A.end(),greater<ll>());

	priority_queue<pair<ll,ll>> pque;
	pque.push({A[1],A[0]}); pque.push({A[1],A[0]});
	ll ans = A[0];
	repp(i,2,N) {
		pair<ll,ll> tmp = pque.top(); pque.pop();
		ans += tmp.first;
		pque.push({A[i],tmp.first});
		pque.push({A[i],tmp.second});
	}
	cout << ans << endl;
	return 0;
}