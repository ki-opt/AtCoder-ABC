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
#include <bitset>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

ll ans = LLONG_MAX;

// 次のコンビネーションを生成する関数
bool next_combination(vector<int>& combination, int n, int k) {
	for (int i = k - 1; i >= 0; --i) {
		if (combination[i] < n - k + i) {
			++combination[i];
			for (int j = i + 1; j < k; ++j) {
					combination[j] = combination[j - 1] + 1;
			}
			return true;
		}
	}
	return false;
}

int main() {
	ll N; cin >> N;
	vector<ll> A(N); rep(i,N) cin >> A[i];
	if (N == 1) {
		cout << A[0] << endl;
		return 0;
	}

	repp(k,1,N) {
		vector<int> combination(N-1);
		rep(i,N-1) combination[i] = i;
		do {
			vector<int> vec = {0};
			rep(i,k) vec.push_back(combination[i]+1);
			vec.push_back(N);

			vector<int> or_vec(k+1,0);			
			repp(i,0,k+1) {
				repp(j,vec[i],vec[i+1]) or_vec[i] |= A[j];
			}

			ll tmp = 0;
			rep(i,k+1) tmp ^= or_vec[i];
			ans = min(ans,tmp);

		} while (next_combination(combination,N-1,k));
	}
	cout << ans << endl;

	/*
	repp(i,1,N) {
		ll left = 0, right = 0;
		repp(j,0,i) left |= A[j];
		repp(j,1,N) right |= A[j];
		ans = min(ans,left^right);
	}
	cout << ans << endl;
	*/

	return 0;
}