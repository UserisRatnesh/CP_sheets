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

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> applicant(n);
  vector<ll> apartments(m);
  for (auto &it : applicant) {
    cin >> it;
  }
  for (auto &it : apartments) {
    cin >> it;
  }
  sort(all(applicant));
  sort(all(apartments));

  ll ans = 0;
  ll left = n - 1;
  ll right = m - 1;
  while (left >= 0 && right >= 0) {
    if (apartments[right] <= applicant[left] + k &&
        apartments[right] >= applicant[left] - k) {
      ans++;
      left--;
      right--;
    } else if (apartments[right] < applicant[left] - k) {
      left--;
    } else {
      right--;
    }
  }
  cout << ans << nline;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fastio();

  solve();
}