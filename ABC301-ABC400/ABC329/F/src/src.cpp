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
	int N, Q;
	cin >> N >> Q;
	vector<int> C(N);
	vector<unordered_map<int,int>> box(N+1);
	rep(i,N) {
		cin >> C[i];
		box[i][C[i]] = 1;
	}

	vector<int> ans;
	rep(i,Q) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		//*
		if (box[a].size() <= box[b].size()) {
			for (auto itr = box[a].begin(); itr != box[a].end(); ++itr) {
				box[b][itr->first]++;
			}
			box[a].clear();
			ans.push_back(box[b].size());
		} else if (box[a].size() > box[b].size()) {
			for (auto itr = box[b].begin(); itr != box[b].end(); ++itr) {
				box[a][itr->first]++;
			}
			box[b].clear();
			swap(box[a],box[b]);
			ans.push_back(box[b].size());
		}
		//*/
	}
	rep(i,ans.size()) cout << ans[i] << endl;
	return 0;
}