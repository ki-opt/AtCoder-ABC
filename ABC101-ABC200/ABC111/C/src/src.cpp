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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<pair<int,int>> v_gusu(100000,{0,-1}), v_kisu(100000,{0,-1});
	rep(i,n) {
		cin >> v[i];
		v[i]--;
		if (i % 2 == 0) { v_gusu[v[i]].first++; v_gusu[v[i]].second = v[i]; }
		else { v_kisu[v[i]].first++; v_kisu[v[i]].second = v[i]; }
	}

	bool isFound = true;
	rep(i,n-2) if (v[i] != v[i+2]) { isFound = false; break; }
	if (isFound && v[0] != v[1]) { cout << 0 << endl; return 0; }

	sort(v_gusu.rbegin(),v_gusu.rend());
	sort(v_kisu.rbegin(),v_kisu.rend());
	vector<int> ans;
	queue<pair<int,int>> que;
	que.push({0,0});
	while (!que.empty()) {
		pair<int,int> tmp = que.front(); que.pop();
		int i = tmp.first, j = tmp.second;
		if (v_gusu[i].second == -1 || v_kisu[i].second == -1) {
			ans.push_back(n-v_gusu[i].first-v_kisu[j].first);
			continue;
		}
		if (v_gusu[i].second == v_kisu[j].second) {
			que.push({i+1,j}); que.push({i,j+1});
		} else {
			ans.push_back(n-v_gusu[i].first-v_kisu[j].first);
		}
	}
	/*for (auto g : v_gusu) {
		if (g.second == -1) break;
		for (auto k : v_kisu) {
			if (k.second == -1) break;
			if (g.second == k.second) continue;
			ans.push_back(n-g.first-k.first);
		}
	}*/
	if (ans.empty()) cout << n / 2 << endl;
	else cout << *min_element(ans.begin(),ans.end()) << endl;;
	
	return 0;
}