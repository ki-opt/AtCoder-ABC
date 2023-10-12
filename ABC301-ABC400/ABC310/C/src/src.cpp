#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N;
	cin >> N;
	vector<string> S(N);
	unordered_map<string,int> umap;
	rep(i,N) {
		string s;
		cin >> s;
		S[i] = s;
		//*
		if (umap.count(s) > 0) umap[s]++;
		else umap[s] = 0;
		reverse(s.begin(),s.end());
		if (s != S[i]) {
			if (umap.count(s) > 0) umap[s]++;
			else umap[s] = 0;
		}
		//*/
	}

	ll ans = 0;
	unordered_map<string,int> check;
	rep(i,N) {
		string s_inv = S[i];
		reverse(s_inv.begin(),s_inv.end());
		cerr << umap.count(S[i]) << endl;
		if (S[i] != s_inv) {
			//if (umap[S[i]] == 0 && umap[s_inv] == 0) {
			if (check.count(S[i]) == 0 || check.count(s_inv) == 0) {
				ans++;
				check[S[i]] = 1;
				check[s_inv] = 1;
			}
			//}
		} else {
			//if (umap[S[i]] == 0) {
			if (check.count(S[i]) == 0) {
				ans++;
				check[S[i]] = 1;
			}
			//}
		}
	}
	cout << ans << endl;


	return 0;
}