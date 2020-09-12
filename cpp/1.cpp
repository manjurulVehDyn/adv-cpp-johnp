#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

void mightGoWrong() {
  bool err1 = false;
  bool err2 = true;
  if (err1) {
    throw 8;
  }
  if (err2) {
    throw "Something went wrong!";
  }
}
int main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  try {
    mightGoWrong();
  } catch (int e) {
    SetConsoleTextAttribute(hConsole, 12);
    cout << "Error code: " << e << endl;
  } catch (char const* e) {
    SetConsoleTextAttribute(hConsole, 12);
    cout << "Error message: " << e << endl;
  }
  SetConsoleTextAttribute(hConsole, 7);
  cout << "still running" << endl;
  return 0;
}