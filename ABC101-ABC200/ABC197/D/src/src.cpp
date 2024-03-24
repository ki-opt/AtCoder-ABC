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
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

#define PI 3.14159265359

int main() {
	double N; cin >> N;
	double x0, y0, x_n, y_n; cin >> x0 >> y0 >> x_n >> y_n;

	double x_c = (x0+x_n)/2.0, y_c = (y0+y_n)/2.0;
	x0 -= x_c, y0 -= y_c, x_n -= x_c, y_n -= y_c;
	
	double x_rot = cos(2*PI/N) * x0 + (-sin(2*PI/N)) * y0;
	double y_rot = sin(2*PI/N) * x0 + (cos(2*PI/N)) * y0;
	printf("%.10f %.10f\n", x_rot + x_c, y_rot + y_c);



	/*
	double x_abs = abs(x_n-x0), y_abs = abs(y_n-y0);
	if ((N / 2) % 2 == 0) {

		double length = sqrt((x0-x_n)*(x0-x_n)+(y0-y_n)*(y0-y_n));
		cout << length << endl;
	} else {

	}
	*/

	return 0;
}