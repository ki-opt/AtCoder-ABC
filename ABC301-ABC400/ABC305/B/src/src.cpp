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
	char p, q;
	cin >> p >> q;
	unordered_map<char,int> umap;
	umap['A'] = 0;
	umap['B'] = 3;
	umap['C'] = 4;
	umap['D'] = 8;
	umap['E'] = 9;
	umap['F'] = 14;
	umap['G'] = 23;
	cout << abs(umap[p]-umap[q]);
	return 0;
}