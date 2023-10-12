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

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(M);
	rep(i,M) cin >> A[i];
	vector<string> S(N);
	rep(i,N) cin >> S[i];

	vector<int> ans(N,0);
	rep(i,N) {
		rep(j,M) {
			if (S[i][j] == 'o') ans[i] += A[j];
		}
		ans[i] += (i+1);
	}

	int max_val = 0, index = -1;
	rep(i,N) { if (ans[i] > max_val) { max_val = ans[i]; index = i; } }


	vector<pair<int,int>> tokuten(M);
	rep(i,M) tokuten[i] = {A[i],i};
	sort(tokuten.rbegin(),tokuten.rend());
	
	vector<int> toku(N);
	rep(i,N) {
		if (i == index) {
			toku[i] = 0;
			continue;
		}
		int cnt = 0;
		rep(j,M) {
			if (S[i][tokuten[j].second] != 'o') {
				cnt++;
				ans[i] += tokuten[j].first;
				if (ans[i] >= max_val) break;
			}
		}
		toku[i] = cnt;
	}
	
	rep(i,N) {
		cout << toku[i] << endl;
	}

	return 0;
}