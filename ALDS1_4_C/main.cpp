#include <iostream>

using namespace std;

#define M 1046527

class Hash {
  int table[M];

  int h1(int key) { return key % M; }
  int h2(int key) { return 1 + (key % (M - 1)); }

  int h(int key, int i) { return (h1(key) + i * h2(key)) % M; }

  int getKey(string s) {
    int key = 0;
    for (string::iterator ptr = s.begin(); ptr != s.end(); ptr++) {
      // cout << *ptr << endl;
      switch (*ptr) {
        case 'A':
          key = key * 5 + 1;
          break;
        case 'T':
          key = key * 5 + 2;
          break;
        case 'C':
          key = key * 5 + 3;
          break;
        case 'G':
          key = key * 5 + 4;
          break;
        default:
          break;
      }
    }
    return key;
  }

 public:
  Hash() {
    for (int i = 0; i < M; i++) {
      table[i] = 0;
    }
  }

  void insert(string s) {
    int i = 0;
    int key = getKey(s);
    while (true) {
      if (table[h(key, i)] == 0) {
        table[h(key, i)] = key;
        break;
      }
      i++;
    }
  }

  bool find(string s) {
    int i = 0;
    int key = getKey(s);
    while (true) {
      if (table[h(key, i)] == 0) {
        return false;
      } else if (table[h(key, i)] == key) {
        return true;
      } else {
        i++;
      }
    }
    return false;  // should not reach
  }
};

int main() {
  size_t n;
  cin >> n;

  Hash H;

  for (size_t i = 0; i < n; i++) {
    string cmd, s;
    cin >> cmd >> s;
    if (cmd == "insert") {
      // cout << "insert " << h(s) << endl;
      H.insert(s);
    } else if (cmd == "find") {
      if (H.find(s)) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    }
  }
  return 0;
}