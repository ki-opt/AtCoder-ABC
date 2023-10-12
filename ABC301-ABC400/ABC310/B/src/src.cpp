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
	int N, M;
	cin >> N >> M;
	vector<int> P(N), C(N);
	vector<vector<int>> F(N);
	vector<unordered_map<int,int>> umap(N);
	rep(i,N) {
		cin >> P[i] >> C[i];
		int tmp;
		rep(j,C[i]) {
			cin >> tmp;
			F[i].push_back(tmp);
			umap[i][tmp] = 1;
		}
	}

	rep(i,N) {
		rep(j,N) {
			if (P[i] >= P[j]) {
				int tmp = 0;
				int flag = 0;
				rep(k,C[i]) {
					int kino = F[i][k];
					if (umap[j].count(kino) == 0) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) continue;
				if (C[j] > C[i] || P[i] > P[j]) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}