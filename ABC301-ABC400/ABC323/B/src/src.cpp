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

bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	rep(i,N) cin >> S[i];

	vector<pair<int,int>> ans(N);
	rep(i,N) { ans[i] = {0,i+1}; }
	rep(i,N) {
		rep(j,N) {
			if (S[i][j] == 'o') ans[i].first++;
		}
	}

	sort(ans.begin(), ans.end(), desc_asc);
	rep(i,N) {
		cout << ans[i].second << " ";
	}
	cout << endl;


	return 0;
}