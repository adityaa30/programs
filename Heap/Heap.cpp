// adityaa30
#include <bits/stdc++.h>
#define var(x) #x, x
#define int long long int
using namespace std;

template <typename A, typename B> string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) { return to_string(string(1, c)); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N> string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void print() { cout << endl; }

template <typename Head, typename... Tail> void print(Head H, Tail... T) {
  cout << " " << to_string(H);
  print(T...);
}

const int MOD = 1e9 + 7;

int PosX[] = {0, 1, 0, -1, 1, 1, -1, -1};
int PosY[] = {1, 0, -1, 0, 1, -1, 1, -1};

// i'th -> 2i, 2i+1
// [Nil, 5, 2, 4, 6]

//      6
//   2     4
// 5

class MaxHeap {
  vector<int> arr;

  void heapify(int idx) {
    int left = idx * 2;
    int right = (idx * 2) + 1;
    int change = idx;
    if (left < arr.size() && arr[left] > arr[change]) {
      change = left;
    }
    if (right < arr.size() && arr[right] > arr[change]) {
      change = right;
    }
    if (idx != change) {
      swap(arr[idx], arr[change]);
      heapify(change);
    }
  }

  int parent(int i) { return (i / 2); }

public:
  MaxHeap() {
    this->arr = vector<int>(1); // 0'th index is not used
  }

  void Print() {
    for (int x : arr) {
      cout << x << " ";
    }
    cout << "\n";
  }

  void push(int x) {
    this->arr.push_back(x);

    int idx = arr.size() - 1;
    while (parent(idx) != 0 && arr[parent(idx)] < arr[idx]) {
      swap(arr[parent(idx)], arr[idx]);
      idx = parent(idx);
    }
  }

  void pop() {
    swap(arr[1], arr[arr.size() - 1]);
    arr.pop_back();
    heapify(1);
  }

  int top() { return this->arr[1]; }

  bool empty() { return (this->arr.size() == 1); }
};

void Check(vector<int> arr) {
  MaxHeap h;
  for (int i = 0; i < arr.size(); ++i) {
    h.push(arr[i]);
  }

  while (!h.empty()) {
    // h.Print();
    cout << h.top() << ' ';
    h.pop();
  }
  cout << '\n';
}

void CheckSTL(vector<int> arr) {
  priority_queue<int> h; // Max Heap
  for (int i = 0; i < arr.size(); ++i) {
    h.push(arr[i]);
  }

  while (!h.empty()) {
    // h.Print();
    cout << h.top() << ' ';
    h.pop();
  }
  cout << '\n';
}

struct Compare {
  bool operator()(int a, int b) {
    // cehck
    return !(a < b);
  }
};

void CheckSTLMin(vector<int> arr) {
  priority_queue<int, vector<int>, Compare> h; // Min Heap
  for (int i = 0; i < arr.size(); ++i) {
    h.push(arr[i]);
  }

  while (!h.empty()) {
    // h.Print();
    cout << h.top() << ' ';
    h.pop();
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  Check({1, 2, 3, 4, 5, 6, 7});
  CheckSTL({1, 2, 3, 4, 5, 6, 7});
  CheckSTLMin({7, 6, 5, 4, 3, 2, 1});

  return 0;
}