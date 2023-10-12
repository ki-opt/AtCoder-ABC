#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

struct triple{
	string s;
	int p;
	int num;

	// 演算子のオーバーロードによる比較関数
	bool operator< (const triple& another) const {
		if (s != another.s) return s < another.s;
		if (p != another.p) return p > another.p;
	}
};

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	vector<int> P(N);
	vector<triple> ans(N);
	rep(i,N) {
		cin >> S[i] >> P[i];
		ans[i] = {S[i],P[i],i+1};
	}

	sort(ans.begin(), ans.end());
	
	rep(i,N){
		cout << ans[i].s << " " << ans[i].p << " " << ans[i].num << endl;
	}

	return 0;
}