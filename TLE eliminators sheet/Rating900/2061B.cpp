#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

void solve() {
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(all(vec));
  // find if two of same size exists or not
  ll index = -1;
  ll equal = -1;
  for (ll i = 1; i < n; i++) {
    if (vec[i] == vec[i - 1]) {
      equal = vec[i];
      index = i;
    }
  }
  if (index == -1) {
    cout << -1 << endl;
    return;
  }

  // find two such elements whose diff is minimum
  ll first = -1;
  ll second = -1;
  ll diff = INT_MAX;

  ll left = 0;
  ll right = 0;
  while ((left == index || left == index - 1)) {
    left++;
  }

  while (right < n) {
    if (right == left || right == index || right == index - 1) {
      right++;
      continue;
    }
    ll d = vec[right] - vec[left];
    if (d < diff) {
      diff = d;
      first = vec[left];
      second = vec[right];
    }
    left = right;
    right++;
  }

  if ((first + 2 * equal) > second) {
    cout << equal << " " << equal << " " << first << " " << second << nline;
    return;
  }
  cout << -1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
