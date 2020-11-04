#include <iostream>
using namespace std;
 
   class date {

  public: int* day; 
  date(int m) { 
      day = new int;
      *day = m; 
  }

  ~date(){ 
      delete day;
      cout << "destructor";
  } 
};

int main() { 
  date *ob1 = new date(12); 
  cout << "1";
  date ob2 = date(10); 
  cout << "2";
  date *ob3 = new date(2); 
  cout << "3";
  delete ob1;
  cout << "4";
  
  return 0; 
}