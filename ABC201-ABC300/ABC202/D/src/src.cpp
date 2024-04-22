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

/*
    前処理: O(MAX_N*MAX_N)
    nCk(n,k): nCk の計算。O(1)
*/
const int MAX_N = 60;         // n の最大値
vector<vector<long long>> com;  // 前計算の結果を保存
// 動的計画法で前処理
void init() {
	com.assign(MAX_N, vector<long long>(MAX_N));
	com[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		com[i][0] = 1;
		for (int j = 1; j < MAX_N; j++) {
			com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]);
		}
	}
}
// nCk を取得
long long nCk(int n, int k) {
	assert(!(n < k));
	assert(!(n < 0 || k < 0));
	return com[n][k];
}

int main() {
	ll A, B, K; cin >> A >> B >> K; K--;
	ll N = A + B;

	init();
	string ans;
	rep(i,N) {
		if (A > 0) {
			if (K < nCk(A-1+B,B)) {
				ans += 'a';
				A--;
			} else {
				ans += 'b';
				K -= nCk(A-1+B,B);
				B--;
			}
		} else {
			ans += 'b';
			B--;
		}
	}
	cout << ans << endl;

	/*string S;
	rep(i,A) S += 'a';
	rep(i,B) S += 'b';*/



	return 0;
}