/* standard exception */
#include <Windows.h>

#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {
 public:
  virtual const char* what() const throw() { return "Something bad happened!"; }
};

class Test {
 private:
  /* data */
 public:
  Test(/* args */);
  ~Test();
  void goesWrong() { throw MyException(); }
};

Test::Test(/* args */) {}

Test::~Test() {}

int main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  Test test;
  try {
    test.goesWrong();
  } catch (const exception& e) {
    SetConsoleTextAttribute(hConsole, 4);
    cout << e.what() << endl;
  }
  SetConsoleTextAttribute(hConsole, 7);
  cout << "The program is still running!" << endl;
  return 0;
}