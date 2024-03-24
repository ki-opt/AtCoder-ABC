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
	int N, M; cin >> N >> M;
	vector<ll> A(N-1), B(M);
	rep(i,N-1) cin >> A[i];
	rep(i,M) cin >> B[i];

	
	セグ木で多分答えられる

	return 0;
}