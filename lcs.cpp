#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

typedef long long       ll;
typedef long double     db;
typedef string          str;
typedef vector <int>    vi;
typedef vector <ll>     vll;
typedef pair <int, int> pii;
typedef pair <ll, ll>   pll;

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

//Time complexity: O(nm)
//Space complexity: O(nm)
void solve() {
	str s = "abacate";
	str t = "tomate";
	int n = s.length();
	int m = t.length();
	int dp[n+1][m+1];
	ms(dp,0);
	frr(i,n) 
		frr(j,m)
			if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	cout << dp[n][m] << nl;
	str join="", common="";
	int i=n, j=m;
	while(i!=0 || j!=0) {
		if(j>0)
			if(dp[i][j-1] == dp[i][j]) {
				join = t[j-1]+join;
				j--;
				continue;
			}
		if(i>0)
			if(dp[i-1][j] == dp[i][j]) {
				join = s[i-1]+join;
				i--;
				continue;
			}
		if(i>0 && j>0)
			if(dp[i-1][j-1] < dp[i][j]) {
				common = s[i-1] + common;
				join = s[i-1]+join;
				i--;
				j--;
			}
	}
	dbg(common);
	dbg(join);
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