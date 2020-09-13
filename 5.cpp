/* custom exception */
#include <Windows.h>

#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {
 public:
  virtual const char* what() const throw() { return "Something bad happened!"; }
};

class Test {
 public:
  void goesWrong() { throw MyException(); }
};

int main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  Test test;
  try {
    test.goesWrong();
  } catch (const exception& e) {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Exception: " << e.what() << endl;
  }
  SetConsoleTextAttribute(hConsole, 7);
  cout << "The program is still running!" << endl;
  return 0;
}