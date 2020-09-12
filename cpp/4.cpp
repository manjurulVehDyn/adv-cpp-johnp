// Standard exception.
#include <iostream>
using namespace std;

class CanGoWrong {
 public:
  CanGoWrong() {
      char *pMemory = new char[99999999999999999];
      delete pMemory;
  }
};

int main() {
  CanGoWrong();

  return 0;
}