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

/* Related problems:
Longest non-decreasing subsequence: change inequality signs. Adjust the binary search.
Number of longest increasing subsequences: implemented in O(n^2); impossible using the 
   O(nlogn) binary search approach; can be implemented in O(nlogn) using a segtree.
Smallest number of non-increasing subsequences covering a sequence:
   https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#toc-tgt-13

*/

//Time complexity: O(n^2)
//Space complexity: O(n)
void quadratic_approach() {
	str s;read(s);
	int n=s.length();
	vi d(n,1), p(n,-1);
	vector<char> subseq;
	fr(i,n)
		fr(j,i)
			if(s[j]<s[i]&&d[j]+1>d[i]) {
				d[i] = d[j]+1;
				p[i] = j;
			}
	int lissize=d[0];
	int liscount=1;
	int pos=0;
	frr(i,n-1) {
		if(d[i]>lissize) {
			lissize=d[i];
			pos=i;
			liscount=1;
		} else if(d[i]==lissize) liscount++;
	}
	while(pos!=-1) {
		subseq.pb(s[pos]);
		pos=p[pos];
	}
	reverse(all(subseq));
	fr(i,sz(subseq))cout<<subseq[i];
	gnl;
	dbg(lissize);
	dbg(liscount);
}

//Time complexity: O(n*logn)
//Space complexity: O(n)
void linearithmic_approach() {
	str s;read(s);
	int n=s.length();
	vi d(n+1,INF);
	d[0]=-INF;
	fr(i,n) {
		int j=upper_bound(all(d),s[i])-d.begin();
		if(s[i]>d[j-1]&&s[i]<d[j])d[j]=s[i];
	}
	int lissize=0;
	frr(i,n) {
		if(d[i]<INF)lissize=i;
	}
	dbg(lissize);
}

void solve() {
	
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