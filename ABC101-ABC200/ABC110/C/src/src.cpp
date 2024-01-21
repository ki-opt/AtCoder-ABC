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
	string S, T;
	cin >> S >> T;
	int N = S.size();

	vector<vector<int>> f(26,vector<int>(26,0));
	rep(i,N) {
		int a = S[i] - 'a', b = T[i] - 'a';
		f[a][b] = 1;
	}
	rep(i,26) {
		int cnt = 0, cnt_2 = 0;
		rep(j,26) { 
			cnt += f[i][j];
			cnt_2 += f[j][i];
		}
		if (cnt > 1 || cnt_2 > 1) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;


	/*
	unordered_map<char,vector<int>> S_umap, t_up;
	rep(i,N) { S_umap[S[i]].push_back(i); }// t_up[T[i]]++; }

	rep(i,N) {
		if (S[i] != T[i]) {
			char c1 = S[i], c2 = T[i];
			for (auto p : S_umap[c1]) { 
				S[p] = c2;
			}
			for (auto p : S_umap[c2]) {
				S[p] = c1;
			}
			swap(S_umap[c1],S_umap[c2]);
		}
	}

	rep(i,N) {
		if (S[i] != T[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	*/

	return 0;
}