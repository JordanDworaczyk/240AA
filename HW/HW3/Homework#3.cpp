/**
* Jordan Dworaczyk
* CSC240AA -- C++
* Homeork#3
* Due Wed. Feb. 8th
* Write a program in C++ to manipulate arrays.
*/

int askUserArraySize(void);

int main() {
  int array_size;
  array_size = askUserArraySize(void);
  cout <<arraysize;
  return 0;
}

int askUserArraySize(void) {
  int user_input;

  cout <<"How big do you want the array to be?\nEnter array size: "<<endl;
  cin  >> user_input;
  cout << endl;

  return user_input;
}
