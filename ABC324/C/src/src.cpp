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
	ll N;
	string T_dash;
	cin >> N >> T_dash;
	vector<string> S(N);
	rep(i,N) cin >> S[i];

	/*
	unordered_map<string,int> umap;
	umap[T_dash] = 1;
	rep(i,T_dash.size()+1) {
		for (char moji = 'a'; moji <= 'z'; moji++) {
			string ins{moji};
			string tmp = T_dash;
			tmp.insert(i,ins);
			umap[tmp] = 1;
		}
	}
	rep(i,T_dash.size()) {
		string tmp = T_dash;
		tmp.erase(i,1);
		umap[tmp] = 1;
	}
	rep(i,T_dash.size()) {
		for (char moji = 'a'; moji <= 'z'; moji++) {
			string rep{moji};
			string tmp = T_dash;
			tmp.replace(i,1,rep);	
			umap[tmp] = 1;
		}
	}*/

	vector<int> ans;
	rep(i,N) {
		if (S[i] == T_dash) ans.push_back(i);
		else if (S[i].size() + 1 == T_dash.size()) {
			int miss = 0;
			int t = 0;
			rep(j,S[i].size()) {
				if (S[i][j] != T_dash[t]) {
					miss++;
					j--;
				}
				t++;
				if (miss > 1) break;
			}
			if (miss <= 1) ans.push_back(i);
		} else if (S[i].size() - 1 == T_dash.size()) {
			int miss = 0;
			int t = 0;
			rep(j,S[i].size()) {
				if (S[i][j] != T_dash[t]) {
					miss++;
					t--;
				}
				t++;
				if (miss > 1) break;
			}
			if (miss <= 1) ans.push_back(i);
		} else if (S[i].size() == T_dash.size()) {
			int miss = 0;
			rep(j,S[i].size()) {
				if (S[i][j] != T_dash[j]) miss++;
				if (miss > 1) break;
			}
			if (miss <= 1) ans.push_back(i);
		}
	}

	cout << ans.size() << endl;
	rep(i,ans.size()) {
		cout << ans[i]+1 << " ";
	}

	return 0;
}