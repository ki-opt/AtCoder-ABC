#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> h(N);
	rep(i,N) cin >> h[i];

	int ans = 0;
	vector<int> h_dash(N,0);
	auto iter = min_element(h.begin(), h.end());
	auto index = distance(h.begin(), iter);
	ans += h[index] - 0;
	rep(i,N) h_dash[i] += h[index];
	
	queue<pair<int,int>> que;
	if (index != 0) que.push(make_pair(0,index));
	if (index != N - 1) que.push(make_pair(index+1,N));
	while (!que.empty()) {
		pair<int,int> b_idx = que.front(); que.pop();
		auto it = min_element(h.begin()+b_idx.first, h.begin()+b_idx.second);
		auto idx = distance(h.begin(), it);
		int tmp = h[idx] - h_dash[idx];
		repp(i, b_idx.second , b_idx.first) h_dash[i] += tmp;
		ans += tmp;
		if (idx != b_idx.first) que.push(make_pair(b_idx.first,idx));
		if (idx != b_idx.second - 1) que.push(make_pair(idx+1,b_idx.second));
	}
	cout << ans << endl;
	
	return 0;
}