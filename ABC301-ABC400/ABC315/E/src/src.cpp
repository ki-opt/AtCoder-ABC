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

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

void DFS(const int &node, vector<int> &seen, const vector<vector<int>> &P, 
			vector<int> &ans) {
	for (int i = 0; i < P[node].size(); i++) {
		if (seen[P[node][i]] == 0) {
			seen[P[node][i]] = 1;
			DFS(P[node][i], seen, P, ans);
			ans.push_back(P[node][i]);
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> C(N+1);
	vector<vector<int>> P(N+1,vector<int>());
	repp(i,1,N+1) {
		cin >> C[i];
		P[i] = vector<int>(C[i]);
		rep(j,C[i]) cin >> P[i][j];
	}

	vector<int> ans;
	vector<int> seen(N+1,0);
	int tmp = 1;
	DFS(tmp, seen, P, ans);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	/*
	queue<pair<int,int>> que;
	vector<int> unique(N,0);
	rep(i,C[0]) { que.push({P[0][i],1}); unique[P[0][i]-1] = 1; }
	vector<vector<int>> ans;
	int kaiso = 0;
	while(que.empty() == false) {
		pair<int,int> tmp = que.front(); que.pop();
		if (ans.size() <= kaiso) { ans.push_back(vector<int>()); }
		ans[kaiso].push_back(tmp.first);
		rep(i,C[tmp.first-1]) {
			if (unique[P[tmp.first-1][i]-1] == 1) continue;
			que.push({P[tmp.first-1][i],kaiso+1});
			unique[P[tmp.first-1][i]-1] = 1;
		}
	}*/

	/*	
	queue<pair<int,int>> que;
	vector<int> unique(N,0);
	rep(i,C[0]) { que.push(P[0][i]); unique[P[0][i]-1] = 1; }
	vector<int> ans;
	while(que.empty() == false) {
		int tmp = que.front(); que.pop();
		ans.push_back(tmp);
		rep(i,C[tmp-1]) {
			if (unique[P[tmp-1][i]-1] == 1) continue;
			que.push(P[tmp-1][i]);
			unique[P[tmp-1][i]-1] = 1;
		}
	}
	reverse(ans.begin(),ans.end());
	*/
	//cout << ans[ans.size()-1] << std::endl;

	return 0;
}