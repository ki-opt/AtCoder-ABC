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

vector<pair<long long, long long>> prime_factorize(long long N) {
	// 答えを表す可変長配列
	vector<pair<long long, long long>> res;
	// √N まで試し割っていく
	for (long long p = 2; p * p <= N; ++p) {
		// N が p で割り切れないならばスキップ
		if (N % p != 0) continue;
		// N の素因数 p に対する指数を求める
		int e = 0;
		while (N % p == 0) {
			// 指数を 1 増やす
			++e;
			// N を p で割る
			N /= p;
		}
		// 答えに追加
		res.emplace_back(p, e);
	}

	// 素数が最後に残ることがありうる
	if (N != 1) res.emplace_back(N, 1);
	return res;
}

int main() {
	int A,B,W; cin >> A >> B >> W;
	W *= 1000;
	vector<int> dp_max(W+1,0);

	int min_ans = INT_MAX, max_ans = 0;
	repp(i,1,W+1) {
		int l = i * A, r = i * B;
		if (l <= W && W <= r) {
			max_ans = max(max_ans,i);
			min_ans = min(min_ans,i);
		}
	}
	/*
	repp(i,A,B+1) {
		int i_tmp = 0;
		while (1) {
			int val = W - ((W / i) - i_tmp) * i;
			if (val == 0 || (val >= A && val <= B)) {
				int tmp;
				if (val == 0) tmp = W/i;
				else tmp = W / i - i_tmp + 1;
				max_ans = max(max_ans,tmp);
				min_ans = min(min_ans,tmp);
			}
			i_tmp++;
			//if (val > B) break;
			if (W / i - i_tmp <= 0) break;
		}
	}
	*/

	//vector<pair<ll,ll>> p = prime_factorize(W);

	if (min_ans == INT_MAX) cout << "UNSATISFIABLE" << endl;
	else cout << min_ans << " " << max_ans << endl;

	return 0;
}