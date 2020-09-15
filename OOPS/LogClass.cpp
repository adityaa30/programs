#include <bits/stdc++.h>
using namespace std;

// Linked internally to `this` translation unit only.
// Linker will not search for this in global scope.
static int s_Variable = 10;

// extern int s_Variable = 10; // => Look for variable outside (External
// Linkage)

class Log {
public:
  enum Level { ErrorLevel = 0, WarningLevel = 1, InfoLevel = 2 };

private:
  Level m_Level = InfoLevel; // Class member variable

public:
  void SetLevel(Level level) { m_Level = level; }

  void Error(const char *message) {
    if (m_Level >= ErrorLevel)
      cout << "[ERROR]: " << message << endl;
  }
  void Warn(const char *message) {
    if (m_Level >= WarningLevel)
      cout << "[WARNING]: " << message << endl;
  }
  void Info(const char *message) {
    if (m_Level >= InfoLevel)
      cout << "[INFO]: " << message << endl;
  }
};

int main() { return 0; }