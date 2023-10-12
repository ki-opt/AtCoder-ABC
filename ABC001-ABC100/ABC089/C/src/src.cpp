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


template <class BidirectionalIterator, class Compare>
bool next_combination(BidirectionalIterator first, BidirectionalIterator last,
                      Compare comp, size_t r)
{
  BidirectionalIterator subset = first + r;
  BidirectionalIterator src = subset;
  BidirectionalIterator dst = subset;
 
  if (first == last || first == subset || last == subset) {
    return false;
  }
 
  while (first != src) {
    src--;
 
    if (comp(*src, *(last - 1))) {
      while (*src >= *dst) {
        dst++;
      }
 
      std::iter_swap(src, dst);
      std::rotate(src + 1, dst + 1, last);
      std::rotate(subset, subset + (last - dst) - 1, last);
 
      return true;
    }
  }
 
  rotate(first, subset, last);
 
  return false;
}
 
template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first, BidirectionalIterator last,
                      size_t r)
{
  using value_type =
    typename std::iterator_traits<BidirectionalIterator>::value_type;
 
  return next_combination(first, last, std::less<value_type>(), r);
}

int main() {
	ll N;
	cin >> N;
	vector<string> S(N);
	vector<unordered_map<string,int>> check(5);
	rep(i,N) {
		cin >> S[i];
		int tmp = -1;
		if (S[i][0] == 'M') tmp = 0;
		else if (S[i][0] == 'A') tmp = 1;
		else if (S[i][0] == 'R') tmp = 2;
		else if (S[i][0] == 'C') tmp = 3;
		else if (S[i][0] == 'H') tmp = 4;
		
		if (tmp != -1) {
			if (check[tmp].count(S[i]) == 0) check[tmp][S[i]] = 1;
		}
	}
	
	vector<int> comb;
	rep(i,5)	{
		if (check[i].size() > 0) {
			comb.push_back(i);	
		}
	}

	if (comb.size() <= 2) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 0;
	do {
		int cnt = 0;
		ll tmp = 1;
		for (auto num : comb) {
			tmp *= check[num].size();
			//cerr << check[num].size() << endl;;
			cnt++;
			if (cnt == 3) break;
		}
		//cerr << endl;
		ans += tmp;
	} while (next_combination(comb.begin(),comb.end(), 3));

	cout << ans << endl;

	return 0;
}