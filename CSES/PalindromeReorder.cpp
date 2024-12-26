#include <iostream>
#include <vector>
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

  // take input
  string str;
  cin >> str;
  vector<int> freq(26, 0);
  for (char c : str) {
    int i = c - 'A';
    freq[i]++; // maintain freq
  }

  // main logic
  ll count = 0;
  int n = str.size();
  string ans(n, ' ');
  int left = 0;
  int right = n - 1;
  for (int i = 0; i < 26; i++) {
    int f = freq[i];
    char c = i + 'A';

    if (f % 2 == 0) {
      while (f > 0) {
        ans[left++] = ans[right--] = c;
        f -= 2;
      }

    } else {
      while (f > 1) {
        ans[left++] = ans[right--] = c;
        f -= 2;
      }
      ans[n / 2] = c;
      count++;
    }
  }

  if (count > 1) {
    cout << "NO SOLUTION" << endl;
    return;
  }
  cout << ans << endl;
}

int main() { solve(); }
