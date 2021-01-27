#include <bits/stdc++.h>
#define int long long int
using namespace std;

struct splitmix64_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = unordered_map<K, V, Hash>;

template <typename k, typename hash = splitmix64_hash>
using hash_set = unordered_set<k, hash>;

int32_t main() {
  int n, x, a;
  cin >> n >> x;

  hash_map<int, int> count;
  count[0] = 1;
  int prefix = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    prefix += a;
    ans += count[prefix - x];
    ++count[prefix];
  }
  cout << ans << '\n';
  return 0;
}