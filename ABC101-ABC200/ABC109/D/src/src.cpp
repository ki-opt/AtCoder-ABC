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
//#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Ans{
	int y, x;
	int y_dash, x_dash;
};

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> a(H,vector<int>(W));
	rep(i,H) rep(j,W) {
		cin >> a[i][j];
	}

	vector<Ans> ans;
	rep(i,H) {
		rep(j,W-1) {
			if (a[i][j] % 2 == 1) {
				ans.push_back({i,j,i,j+1});
				a[i][j+1]++;
			}
		}
	}
	rep(i,H-1) {
		if (a[i][W-1] % 2 == 1) {
			ans.push_back({i,W-1,i+1,W-1});
			a[i+1][W-1]++;
		}
	}
	/*
	vector<vector<bool>> done(H,vector<bool>(W,false));
	while(true) {
		bool isFound = false;
		rep(i,H) {
			rep(j,W) {
				if (done[i][j] || a[i][j] % 2 == 0) continue;
				Ans tmp;
				if (i-1>=0 && a[i-1][j] % 2 == 1) { 
					a[i-1][j]++; a[i][j]--; 
					ans.push_back({i,j,i-1,j});
					isFound=true; break; 
				}
				if (i+1<H && a[i-1][j] % 2 == 1) { 
					a[i+1][j]++; a[i][j]--; 
					ans.push_back({i,j,i+1,j});
					isFound=true; break;
				}
				if (j-1>=0 && a[i][j-1] % 2 == 1) { 
					a[i][j-1]++; a[i][j]--; 
					ans.push_back({i,j,i,j-1});	
					isFound=true; break; 
				}
				if (j+1<W && a[i][j+1] % 2 == 1) {
					a[i][j+1]++; a[i][j]--; 
					ans.push_back({i,j,i,j+1});
					isFound=true; break; 
				}
			}
		}
		if (!isFound) break;
	}
	*/
	cout << ans.size() << endl;
	for (auto a : ans) cout << a.y+1 << " " << a.x+1 << " " << a.y_dash+1 << " " << a.x_dash+1 << endl;
	return 0;
}