#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Trio{
	int l, r;
	int val;
	bool operator<(const Trio& another) const {
		return another.val < val;
	}
};

int main() {
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	vector<Trio> hugoka;
	rep(i,N) {
		int cnt = 0;
		int j = i;
		if (S[j] == '0') {
			if (j == 0) hugoka.push_back({0,1,0});
			while (S[j] == '0') { j++; cnt++; if (j == N) break; }
			hugoka.push_back({i,j,cnt});
			if (j == N) hugoka.push_back({N,N+1,0});
			i = j - 1;
		} else if (S[j] == '1') {
			while (S[j] == '1') { j++; cnt++; if(j == N) break;}
			hugoka.push_back({i,j,cnt});
			i = j - 1;
		}
	}
	
	ll ans = 0;
	if (hugoka.size() < 2 * K + 1) {
		rep(i,hugoka.size()) ans += hugoka[i].val;
		cout << ans << endl;
		return 0;
	} else {
		for (int i = 0; i < 2 * K + 1; i++) {
			ans += hugoka[i].val;
		}
		ll tmp = ans;
		for (int i = 2; i + 2 * K < hugoka.size(); i += 2) {
			tmp = tmp - (hugoka[i-2].val + hugoka[i-1].val) + 
								(hugoka[i+2*K-1].val + hugoka[i+2*K].val);
			ans = max(tmp,ans);
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}