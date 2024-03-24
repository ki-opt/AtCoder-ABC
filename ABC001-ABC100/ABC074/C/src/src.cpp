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
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	
	double density = 0;
	pair<int,int> ans = {100*A,0};
	for (int i = 0; 100 * A * i <= F; i++) {
		int water_a = 100 * A * i;
		for (int j = 0; water_a + 100 * B * j <= F; j++) {
			int water_ab = water_a + 100 * B * j;
			for (int k = 0; water_ab + C * k <= F && C * k * 100 <= E * water_ab; k++) {
				int total_c = water_ab + C * k;
				for (int l = 0; total_c + D * l <= F && (C * k + D * l) * 100 <= E * water_ab; l++) {
					int total_cd = total_c + D * l;
					if (total_cd == 0) continue;
					double tmp = 100.0 * ((double)(C * k + D * l) / (double)total_cd);
					if (tmp > density) {
						density = tmp;
						ans = {total_cd,C*k+D*l};
					}
				}
			}
		}
	}
	cout << ans.first << " " << ans.second << endl;

	return 0;
}