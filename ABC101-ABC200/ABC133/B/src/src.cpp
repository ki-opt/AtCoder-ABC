#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, D;
	cin >> N >> D;
	vector<vector<int>> X(N,vector<int>(D));
	rep(i,N){
		rep(j,D) cin >> X[i][j];
	}

	int ans = 0;
	rep(i,N){
		repp(j,N,i+1) {
			int check = 0;
			rep(k,D) {
				check += ((X[i][k] - X[j][k]) * (X[i][k] - X[j][k]));
			}
			repp(k,check+1,1) {
				if (k * k == check) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}