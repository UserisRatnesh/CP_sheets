#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
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
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
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

// NOTE: Check if num is prime or not
// TC: O(d^(1/2) = O(100)
bool isPrime(ll num) {
  for (ll i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// NOTE: Find prime >= start
// HACK: The max difference between the nth prime ans (n+1)th prime is at most
// ln(n)
// TC: O(1e3)
ll findPrime(ll start) {
  for (ll i = start;; i++) {  // ln(d) = ln(1e4) = 10
    if (isPrime(i)) {         // O(100)
      return i;
    }
  }
  return -1;
}

// TC: O(1e6)
void solve() {
  ll d;
  cin >> d;
  ll p = findPrime(d + 1);
  ll q = findPrime(p + d);

  ll ans = min(1ll * p * p * p, 1ll * p * q);

  cout << ans << nline;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}