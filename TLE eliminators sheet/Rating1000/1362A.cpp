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

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

/*
   _____          _        ____       _
  / ____|        | |      |  _ \     | |
 | |     ___   __| | ___  | |_) | ___| | _____      __
 | |    / _ \ / _` |/ _ \ |  _ < / _ \ |/ _ \ \ /\ / /
 | |___| (_) | (_| |  __/ | |_) |  __/ | (_) \ V  V /
  \_____\___/ \__,_|\___| |____/ \___|_|\___/ \_/\_/

*/

// NOTE: It is working => Tried with test cases and deduced this and it's
// working
ll helper(ll a, ll b) {
  ll quo = b / a;

  ll ans = 0;
  while (quo >= 8) {
    if (quo % 8) {
      return -1;
    }
    quo /= 8;
    ans++;
  }

  while (quo >= 4) {
    if (quo % 4) {
      return -1;
    }
    quo /= 4;
    ans++;
  }
  while (quo >= 2) {
    if (quo % 2) {
      return -1;
    }
    quo /= 2;
    ans++;
  }

  return ans;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  if (gcd(a, b) != a && gcd(a, b) != b) {
    cout << -1 << nline;
    return;
  }
  if (a > b) {

    cout << helper(b, a) << nline;
    return;
  }
  cout << helper(a, b) << nline;
}

// NOTE: Mathematical approach

pair<ll, ll> getRem(ll n) {

  ll p = 0;
  while (n % 2 == 0) {
    n /= 2;
    p++;
  }

  return {n, p};
}

void solveBetter() {
  ll a, b;
  cin >> a >> b;

  pair<ll, ll> remA = getRem(a);
  pair<ll, ll> remB = getRem(b);

  ll ra = remA.first;
  ll x = remA.second;

  ll rb = remB.first;
  ll y = remB.second;

  if (ra != rb) {
    cout << -1 << nline;
    return;
  }

  ll ans = 0;
  ll diff = abs(x - y);
  ans += diff / 3;
  diff %= 3;
  if (diff) {
    ans++;
  }
  cout << ans << nline;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solveBetter();
  }
}
