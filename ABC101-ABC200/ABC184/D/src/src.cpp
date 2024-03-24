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
#include <set>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

double ans = 0;
double dp[101][101][101];

double dfs(int a, int b, int c) {
	if (dp[a][b][c] >= DBL_EPSILON) return dp[a][b][c];
	if (a == 100 || b == 100 || c == 100) return 0;
	double ans = 0;
	ans += (1+dfs(a+1,b,c))*((double)a/(double)(a+b+c));
	ans += (1+dfs(a,b+1,c))*((double)b/(double)(a+b+c));
	ans += (1+dfs(a,b,c+1))*((double)c/(double)(a+b+c));
	dp[a][b][c] = ans;
	return ans;
}

int main() {
	int A, B, C; cin >> A >> B >> C;
	printf("%.10f\n",dfs(A,B,C));
}
/*
int main() {
	int A, B, C; cin >> A >> B >> C;
	vector<vector<vector<double>>> dp(101,vector<vector<double>>(101,vector<double>(101,0)));
	dp[A][B][C] = 1.0;

	repp(i,A,100) {
		repp(j,B,100) {
			repp(k,C,100) {				
				if (dp[i][j][k] <= DBL_EPSILON) continue;
				bool isFound = false;
				if (A != 0 && i + 1 <= 100) {
					dp[i+1][j][k] += dp[i][j][k] + (double)i / (double)(i+j+k);
					isFound = true;
				}
				if (B != 0 && j + 1 <= 100) {
					if (!isFound) dp[i][j+1][k] += dp[i][j][k] + (double)j / (double)(i+j+k);
					else dp[i][j+1][k] += (double)j / (double)(i+j+k);
					isFound = true;
				}
				if (C != 0 && k + 1 <= 100) {
					if (!isFound) dp[i][j][k+1] += dp[i][j][k] + (double)k / (double)(i+j+k);
					else dp[i][j][k+1] += (double)k / (double)(i+j+k);
					isFound = true;
				}
				//if (!is)
			}
		}
	}


	double ans = 0;
	rep(i,100) rep(j,100) ans += dp[i][j][100];
	rep(i,100) rep(j,100) ans += dp[i][100][j];
	rep(i,100) rep(j,100) ans += dp[100][i][j];
	
	printf("%.12f\n",ans - 1.0);
	return 0;
}
*/
/*
double mp[101][101][101];

void dfs(int A, int B, int C) {
	double tmp = (double)A / (double)(A+B+C);
	if (A != 0 && A+1 != 100) dfs(A+1,B,C);
	
	tmp = (double)B / (double)(A+B+C);
	ans += tmp;
	if (B != 0 && B+1 != 100) dfs(A,B+1,C);


	tmp = (double)C / (double)(A+B+C);
	ans += tmp;
	if (C != 0 && C+1 != 100) dfs(A,B,C+1);
}

int main() {
	int A, B, C; cin >> A >> B >> C;
	double ans = dfs(A,B,C);
	
	printf("%.12f\n",ans);
	return 0;
}
*/