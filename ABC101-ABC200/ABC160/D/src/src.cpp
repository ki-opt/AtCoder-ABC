#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

int main() {
	int N, X, Y;
	cin >> N >> X >> Y;

	vector<int> ans(N+1,0);
	repp(i,1,N+1) {
		repp(j,i+1,N+1) {
			int k = INT_MAX;
			chmin(k,j-i);
			chmin(k,abs(X-i)+abs(Y-j)+1);
			ans[k]++;
		}
	}
	repp(i,1,N) cout << ans[i] << endl;

	return 0;
}