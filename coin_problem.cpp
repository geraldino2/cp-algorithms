#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using ll =  long long;
using db =  long double;
using str = string;

using vi =  vector <int>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define INF 1001001001
#define PI  3.1415926535897932384626
#define MOD 1000000007

#define eb  emplace_back
#define pb  push_back
#define mp  make_pair
#define mt  make_tuple
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define rfr(i,n)    for(int i=n-1;i>=0;i--)

#define all(x)      x.begin(),x.end()
#define sz(x)       ((int)x.size())
#define ms(a,x)     memset(a,x,sizeof(a))

#define gnl cout << endl
#define uga cout << "uga" << endl
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define print(x) cout << (x) << endl
#define prints(x) cout << (x) << " "

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

template<typename... T> void read(T&... args){((cin >> args), ...);}
template<typename... T> void write(T&&... args){((cout << args << " "), ...);cout << '\n';}

const char nl = '\n';

void solve() {
	int n,desired;read(n,desired);
	ll coins[n];
	for(ll &x : coins)read(x);
	ll value[desired+1];
	ll solution_count[desired+1];
	ll first[desired];
	ms(solution_count,0);
	solution_count[0] = 1;
	value[0] = 0;
	frr(i, desired) {
		value[i] = INF;
		fr(j, n) {
			int c = coins[j];
			if(i-c >= 0) {
				solution_count[i] += solution_count[i-c];
				if(value[i-c]+1 < value[i]) {
					value[i] = value[i-c]+1;
					first[i] = c;
				}
			}
		}
	}
	print(solution_count[desired]);
	print(value[desired]);
	while(desired>0) {
		cout << first[desired] << " ";
		desired -= first[desired];
	}
}

int main() {
	fastio;
	int test_cases=1;
	//cin >> test_cases;
	while(test_cases--) {
		solve();
	}
	return 0;
}