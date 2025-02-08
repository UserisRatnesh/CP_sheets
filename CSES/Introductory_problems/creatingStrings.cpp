#include <algorithm>
#include <iostream>
#include <map>
#include <set>
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

// using inbuilt function
void solve(string str, set<string> &ans) {
  sort(all(str));

  do {
    ans.insert(str);
  } while (next_permutation(all(str)));
}

// Brute force
void bruteF(int n, string str, set<string> &ans, map<char, int> mp) {
  if (str.size() == n) {
    ans.insert(str);
    return;
  }
  for (auto &pair : mp) {
    if (pair.second != 0) {
      // select this char fo now and call recursive function
      string newS = str + pair.first;
      // update map freq
      pair.second--;
      bruteF(n, newS, ans, mp);
      pair.second++;
    }
  }
}

int main() {
  fastio(); // Call here to enable fast IO.

  string str;
  cin >> str;
  // set<string> ans;
  // solve(str, ans);
  // cout << ans.size() << endl;
  // for (string s : ans) {
  //   cout << s << endl;
  // }

  // Brute force solution
  int n = str.size();
  set<string> ans;
  map<char, int> mp;
  for (char c : str) {
    mp[c]++;
  }
  bruteF(n, "", ans, mp);
  cout << ans.size() << endl;
  for (string s : ans) {
    cout << s << endl;
  }
}
