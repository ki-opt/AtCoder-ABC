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
	ll N; cin >> N;
	vector<ll> A(N), B(N);//, total(N);
	vector<pair<ll,ll>> total(N);
	rep(i,N) {
		cin >> B[i] >> A[i];
		total[i] = {A[i]+2*B[i],i};
		//total[i] = A[i] + B[i];
	}

	ll takahashi = 0, aoki = 0;
	rep(i,N) aoki += B[i];

	int cnt = 0;
	sort(total.begin(),total.end(),greater<pair<ll,ll>>());
	while (takahashi <= aoki) {
		ll index = total[cnt].second;
		takahashi += A[index] + B[index];
		aoki -= B[index];
		cnt++;
	}
	cout << cnt << endl;


	return 0;
}