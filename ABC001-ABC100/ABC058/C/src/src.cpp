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
	int n;
	cin >> n;
	vector<string> S(n);
	rep(i,n) cin >> S[i];

	//vector<vector<bool>> check(n,vector<bool>(26));
	vector<vector<int>> cnt(n,vector<int>(26,0));
	//map<char,vector<int>> mp;
	rep(i,n) {
		rep(j,S[i].size()) {
			int tmp = S[i][j] - 97;
			//check[i][tmp] = true;
			cnt[i][tmp]++;
		}
	}

	char c = 'a';
	rep(i,26) {
		c = char('a' + i);
		bool flag = true;
		rep(j,n) {
			if (cnt[j][i] == 0) { flag = false; break;}
		}
		if (flag) {
			int min_val = INT_MAX;
			rep(j,n) min_val = min(min_val,cnt[j][i]);
			rep(j,min_val) cout << c;
		}
	}
	cout << endl;

	/*
	rep(i,S[0].size()) {
		string tmp = S[i];
		bool flag = false;
		repp(j,1,n) {
			rep(k,S[j].size()) {
				if (S[j][k] == tmp) 
			}
		}
	}
	*/

	return 0;
}