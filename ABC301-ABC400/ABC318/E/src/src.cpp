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
	int N;
	cin >> N;
	vector<int> A(N);
	vector<vector<int>> val(N+1,vector<int>());
	rep(i,N) {
		cin >> A[i];
		val[A[i]].push_back(i);
	}
	
	int ans = 0;
	repp(i,1,N+1) {
		rep(j,val[i].size()-1) {
			if (val[i][j] + 1 == val[i][j+1]) continue;
			int sum = 0;
			repp(k,j,val[i].size()-1) {
				if (k == 0) {
					ans += val[i][k+1] - val[i][j] - 1;
				} else {
					ans += val[i][k+1] - val[i][j] - 1 - sum;
				}
				sum++;
			}			
		}
	}
	
	cout << ans << endl;
	
	return 0;
}