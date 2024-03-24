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
	ll N, M, L, Q; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	cin >> M;
	vector<ll> B(M);
	rep(i,M) cin >> B[i];
	cin >> L;
	vector<ll> C(L);
	rep(i,L) cin >> C[i];	
	cin >> Q;
	vector<ll> X(Q);
	rep(i,Q) cin >> X[i];

	sort(A.begin(),A.end()); sort(B.begin(),B.end()); sort(C.begin(),C.end());

	unordered_map<ll,ll> umap;
	rep(i,N) {
		rep(j,M) {
			rep(k,L) {
				umap[A[i]+B[j]+C[k]]++;
			}			
		}
	}
	rep(q,Q) {
		if (umap.count(X[q]) > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}



	return 0;
}