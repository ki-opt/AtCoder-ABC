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

int main() {
	int N, M; cin >> N >> M;
	vector<int> A(M), B(M); 
	rep(i,M) cin >> A[i] >> B[i];
	int K; cin >> K;
	vector<int> C(K), D(K);
	rep(i,K) cin >> C[i] >> D[i];

	ll ans = 0;
	for (int i = 0; i < (1 << K); i++) {
		bitset<100> bs(i);
		vector<int> dish(N+1,0);
		rep(j,K) {
			if (bs[j] == 0) dish[C[j]]++;
			else if (bs[j] == 1) dish[D[j]]++;
		}
		ll tmp = 0;
		rep(j,M) if (dish[A[j]] >= 1 && dish[B[j]] >= 1) tmp++;
		ans = max(tmp,ans);
	}
	cout << ans << endl;


	return 0;
}