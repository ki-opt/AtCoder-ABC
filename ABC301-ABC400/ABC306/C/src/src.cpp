#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> A(3*N);
	vector<vector<int>> check(N);
	rep(i,3*N) {
		cin >> A[i];
		check[A[i]-1].push_back(i+1);
	}
	vector<pair<int,int>> tmp(N);
	rep(i,N) tmp[i] = make_pair(check[i][1],i+1);

	sort(tmp.begin(),tmp.end());
	rep(i,N) cout << tmp[i].second << " ";
	cout << endl;

	return 0;
}