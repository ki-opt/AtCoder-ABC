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
	int N;
	cin >> N;
	vector<int> X(N);
	vector<pair<int,int>> pairs(N);
	rep(i,N) {
		cin >> X[i];
		pairs[i] = {X[i],i};
	}
	sort(pairs.begin(),pairs.end());


	vector<pair<int,int>> B(N);
	rep(i,N) {
		if (i < N / 2) B[i].first = pairs[N/2].first;
		else B[i].first = pairs[N/2-1].first;
		B[i].second = pairs[i].second;
	}

	sort(B.begin(),B.end(), [&](pair<int,int>left, pair<int,int>right) -> bool {
		return left.second < right.second;
	});
	
	rep(i,N) cout << B[i].first << endl;

	return 0;
}