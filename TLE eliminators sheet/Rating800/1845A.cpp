#include <iostream>
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

void solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  if (k == 1) {
    cout << "NO" << endl;
    return;
  }
  if (n % 2 == 1 && k == 2 && x == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;

  // Now k = anything and n is also anything
  if (x != 1) {
    cout << n << endl;
    ll sum = 0;
    // print 1 till sum gets to n
    while (sum < n) {
      sum += 1;
      cout << 1 << " ";
    }
    cout << endl;
    return;
  }

  int two = n / 2;
  if (n % 2 == 1) {
    cout << two << endl;
    // print two twos-1 number of times and one three
    while (two > 1) {
      cout << 2 << " ";
      two--;
    }
    cout << 3 << endl;
  } else {
    cout << two << endl;
    // print two twos number of times
    while (two--) {
      cout << 2 << " ";
    }
    cout << endl;
  }
}

void solveBetter() {
  ll n, k, x;
  cin >> n >> k >> x;
  if (x != 1) {
    // print one n times
    cout << "YES" << endl << n << endl;
    while (n--) {
      cout << 1 << " ";
    }
    return;
  }

  // Down here x will always be one
  if (k == 1 || (k == 2 && n % 2 == 1)) {
    cout << "NO";
    return;
  }

  int mid = n / 2;

  cout << "YES" << endl;
  cout << mid << endl;
  if (n % 2 == 0) {
    while (mid--) {
      cout << 2 << " ";
    }
    return;
  }

  while (mid > 1) {
    cout << 2 << " ";
    mid--;
  }
  cout << 3;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solveBetter();
    cout << endl;
  }
}
