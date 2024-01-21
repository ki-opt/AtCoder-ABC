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

int N, T, M;

unsigned dfs(int hito, vector<unordered_map<int,int>> umap_team,
		const vector<vector<int>> &g) {
	if (hito == N) {
		return (umap_team.size() == T);
	}

	unsigned ans{};

	rep(t,umap_team.size()) {
		bool isOk = true;
		for (auto i : g[hito]) {
			if (umap_team[t].count(i) > 0) {
				isOk = false;
				break;
			}
		}
		if (isOk) {
			umap_team[t][hito] += 1;
			ans += dfs(hito+1,umap_team,g);
			umap_team[t].erase(hito);
		}
	}

	if (umap_team.size() < T) {
		umap_team.push_back(unordered_map<int,int>());
		umap_team[umap_team.size()-1][hito] += 1;
		ans += dfs(hito+1,umap_team,g);
		umap_team.pop_back();
	}
	return ans;	
}

int main() {
	cin >> N >> T >> M;
	vector<int> A(M), B(M);
	vector<vector<int>> g(N);	//,vector<bool>(N,false));
	rep(i,M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		g[A[i]].push_back(B[i]);
		g[B[i]].push_back(A[i]);
		//g[A[i]][B[i]] = true;
		//g[B[i]][A[i]] = true;
	}
	
	vector<unordered_map<int,int>> umap_team;
	umap_team.push_back(unordered_map<int,int>());
	umap_team[0][0] += 1;
	cout << dfs(1,umap_team,g) << endl;

	return 0;
}