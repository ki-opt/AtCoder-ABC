/*
	osa_k法: 高速素因数分解
	前準備O(NlogN), クエリO(logN)
*/
const int N_MAX = ;	// maxval
ll spf[N_MAX]; // smallest prime factors
void prepare_factorize(){
	rep(i,N_MAX) spf[i] = i;
	for(int p=2; p*p <= N_MAX; p++){
		for(int i=p; i<N_MAX; i+=p){
		if(spf[i]==i) spf[i] = p;
		}
	}
}

// 素因数分解
// その素因数が何個あるかのmapを返す
// map.first => 奇数, map.second = 指数
map<ll,ll> factorize_fast(ll n){
	if(spf[1]==0){
		p("please initialize");
		exit(0);
	}
	map<ll,ll> mp;
	while(n!=1){
		ll p = spf[n];
		mp[p]++;
		n/=p;
	}
	return mp;
}
