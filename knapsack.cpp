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

int val[] = { 60, 100, 120 };
int wt[] = { 10, 20, 30 };
int n = sizeof(val) / sizeof(val[0]);
int C = 50;
int dp[50][50];

// Time complexity: O(nC)
// Space complexity: O(C)
int knapsack() {
	int dp[C + 1];
    ms(dp, 0);
    for (int i=1; i<=n; i++)
        for (int c=C; c>=wt[i-1]; c--)
			dp[c] = max(dp[c], dp[c-wt[i-1]]+val[i-1]);
    return dp[C];
}

// Time complexity: O(nC)
// Space complexity: recursion tree (O(nC)?)
int recursiveKnapsack(int i, int cap) {
	if(cap<0) return -INF;
	if(i==n) return 0;
	int& x = dp[i][cap];
	if(x!=-1) return x;
	return x=max(recursiveKnapsack(i+1, cap-wt[i])+val[i], recursiveKnapsack(i+1, cap));
}
void recursiveKnapsackRecover(int i, int cap) {
	if(i==n) return;
	int picking = val[i]+recursiveKnapsack(i+1, cap-wt[i]);
	int passing = recursiveKnapsack(i+1, cap);
	if(picking>=passing) {
		cout << i << " ";
		recursiveKnapsackRecover(i+1, cap-wt[i]);
	} else recursiveKnapsackRecover(i+1, cap);
}

void solve() {
	ms(dp,-1);
	cout << recursiveKnapsack(0,C) << nl;
	recursiveKnapsackRecover(0,C);
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