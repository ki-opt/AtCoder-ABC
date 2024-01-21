#define _USE_MATH_DEFINES
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
#include <math.h>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	double a, b, x;
	cin >> a >> b >> x;
	printf("%.6f\n",atan(b-x/(a*a)/a)*(180/M_PI));
	return 0;
}