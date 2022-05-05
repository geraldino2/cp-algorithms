#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using db = long double;
using str = string;

using vi =  vector <int>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define INF 1001001001
#define PI 3.1415926535897932384626
#define MOD 1000000007

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define rfr(i,n)    for(int i=n-1;i>=0;i--)

#define all(x)  x.begin(),x.end()
#define sz(x) ((int)x.size())

#define gnl cout << endl
#define uga cout << "uga" << endl
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x)  cout << #x << " = " << x << endl

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const char nl = '\n';

void merge(int array[], int left, int mid, int right) {
    int n=mid-left+1, m=right-mid, i, j, merged=left;
    int leftArray[n], rightArray[m];
    for(i=0; i<n; i++) leftArray[i] = array[left+i];
    for(j=0; j<m; j++) rightArray[j] = array[mid+j+1];
    while (i<n && j<m)
        if (leftArray[i] <= rightArray[j])
            array[merged++] = leftArray[i++];
        else
            array[merged++] = rightArray[j++];
    while (i<n) array[merged++] = leftArray[i++];
    while (j<m) array[merged++] = rightArray[j++];
}

void merge_sort(int array[], int begin, int end) {
    if(begin >= end) return;
    int mid = begin+(end-begin)/2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid+1, end);
    merge(array, begin, mid, end);
}

void solve() {
    
}

int main() {
    fastio;
    int test_cases=1;
    cin >> test_cases;
    while(test_cases--) {
        solve();
    }
    return 0;
}