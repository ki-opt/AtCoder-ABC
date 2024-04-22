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
	ll N, Q; cin >> N >> Q;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	vector<pair<ll,ll>> K(Q);
	rep(q,Q) {
		ll tmp; cin >> tmp;
		K[q] = {tmp,q};
	}
	sort(K.begin(),K.end());

	vector<ll> ans(Q);
	int index = 0;
	rep(i,Q) {
		while (index < N && K[i].first+index >= A[index]) index++;
		if (index == N) {
			ans[K[i].second] = K[i].first + N;
		} else {
			if (K[i].first == A[index]) {
				while (index < N-1 && A[index]+1 == A[index+1]) index++;
				if (index == N-1) {
					ans[K[i].second] = K[i].first + N;
				} else {
					ans[K[i].second] = K[i].first + index;
				}
			} else {
				ans[K[i].second] = K[i].first + index;
			}
		}
	}

	/*
	unordered_map<ll,ll> umap;
	vector<ll> a;
	if (A[0] != 1) a.push_back(A[0]-1), umap[A[0]-1];
	repp(i,1,N) {
		while (i < N && A[i-1]+1 == A[i]) i++;
		if (i != N) a.push_back(A[i]-i-1), umap[A[i]-i-1];
	} 

	rep(i,Q) {
		int k; cin >> k;
		auto itr = lower_bound(a.begin(),a.end(),k);
		if (itr == a.end()) {
			ans.push_back(k+A.size());
		} else {
			if (k == *itr) ans.push_back(k);
			else ans.push_back(k-umap[*itr]+1);
		}
	}
	*/

	/*
	vector<pair<ll,ll>> K(Q);
	rep(q,Q) {
		ll tmp; cin >> tmp;
		K[q] = {tmp,q};
	}
	sort(K.begin(),K.end());

	vector<ll> ans(Q);
	int index = 0;
	rep(i,Q) {
		while (index < N && K[i].first >= A[index]) index++;
		if (index == N) {
			ans[K[i].second] = K[i].first + N;
		} else {
			if (K[i].first == A[index]) {
				while (index < N-1 && A[index]+1 == A[index+1]) index++;
				if (index == N-1) {
					ans[K[i].second] = K[i].first + N;
				} else {
					ans[K[i].second] = K[i].first + index;
				}
			} else {
				ans[K[i].second] = K[i].first + index;
			}
		}
	}
	*/

	for (auto answer : ans) {
		cout << answer << endl;
	}

	return 0;
}