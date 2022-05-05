#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using db = long double;
using str = string;

#define INF 1001001001
#define PI 3.1415926535897932384626

using vi =  vector <int>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)       for(int i=0;i<n;i++)
#define frr(i,n)      for(int i=1;i<=n;i++)
#define rfr(i,n)      for(int i=n-1;i>=0;i--)

#define all(x)        x.begin(),x.end()
#define sz(x)         ((int)x.size())
#define lowerb(x,v)   lower_bound(all(x),v)-x.begin()
#define uperb(x,v)    upper_bound(all(x),v)-x.begin()

#define gnl cout << endl
#define uga cout << "uga\n"
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x)  cout << #x << " = " << x << "\n"
#define prt(x) cout << x << "\n"
#define prtarr(x,n) fr(i,n) cout << x[i] << " ";

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool sortbysec(const pair <int,int> &a, const pair <int,int> &b) { return (a.snd < b.snd); }

int main() {
	fastio;
	int n, x;
	cin >> n;
	int arr[n];
	fr(i, n) {
		cin >> arr[i];
	}
	cin >> x;
	sort(arr, arr+n);
	int temp, i = 0, j = n-1, mid;
	while(i <= j) {
		mid = i + (j-i)/2;
		temp = arr[mid];
		if(temp < x)
			i = mid+1;
		else if(temp > x)
			j = mid-1;
		else
			break;
	}
	if(temp == x)
		yes;
	else
		no;
	return 0;
}
