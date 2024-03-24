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
	double c = 90.0-atan(a/(2.0*b-2.0*x/(a*a)))*(180.0/M_PI);
	double d = 90.0-atan(2.0*x/(a*b*b))*(180.0/M_PI);
	if (2.0*x/(a*a)-b>=0) printf("%.10f\n",c);
	else printf("%.10f\n",d);
	return 0;
}