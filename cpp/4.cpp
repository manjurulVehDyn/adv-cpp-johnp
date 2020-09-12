// Standard exception.
#include <Windows.h>

#include <iostream>
using namespace std;

class CanGoWrong {
 public:
  CanGoWrong() {
    char *pMemory = new char[99999999999999999];
    delete[] pMemory;
  }
};

int main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  try {
    CanGoWrong wrong;
  } catch (bad_alloc &e) {
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Caught exception: " << e.what() << endl;
  }
  SetConsoleTextAttribute(hConsole, 7);
  cout << "Still running" << endl;
  return 0;
}