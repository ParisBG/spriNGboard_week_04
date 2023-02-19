#include <iostream>
#include <vector>
//for iota
#include <numeric>
//for reverse, fill, and sort
#include <algorithm>
using namespace std;


void print_vector (const vector<int>&,string);
void test_algorithms (int);
bool sortAsEven(int,int);

int main (){
  test_algorithms(15);
  return 0;
}


void test_algorithms (int s){
  cout << endl; 
  
  //Vector of s size filled with zeros
  vector<int> v(s,0);
  print_vector(v, "Original");

  //Iota takes a 2 iterators that represent a range and a starting value.
  //It then fills the given range by contiguously incrementing the starting value
  iota(v.begin(),v.end(),5);
  print_vector(v, "Iota");

  //The reverse function also takes 2 range iterators
  //It then swaps the vals at those positions, then does the same for every subsequent pair of values that follows
  reverse(v.begin(),v.end());
  print_vector(v, "Reverse");

  //Sort also takes 2 range iterators and sorts the range ascending
  auto start = next(v.begin(),1);
  auto stop = prev(v.end(), 2);
  sort(start,stop);
  print_vector(v, "Sort");
  
  //Using a custom comparing function to sort the vector accordingly
  //sort(v.begin(),v.end(),sortAsEven(int num1, int num2));
  sort(v.begin(),v.end(),[](int num1, int num2){ 
    if (num1 % 2 == 0 && num2 % 2 != 0) {
      return true;
    } else {
      return false; //keep current order
    }
  });

  print_vector(v, "Sort-Compar Lambda");
  
  //Fill also takes 2 range iterators and fills that range with the given value
  fill(v.begin(),v.end(),20);
  print_vector(v, "Fill");
  cout << endl; 
}

void print_vector (const vector<int>& v, string type){
  cout << type << " v = ";
 
  for (auto& elem : v) {
    cout << elem << " ";
  }
  
  cout << endl;
}

bool sortAsEven(int num1, int num2){
  //Since num1 is even and num2 is not, bring num1 to front and num2 to back
  if (num1 % 2 == 0 && num2 % 2 != 0) {
    return true;
  } else {
    return false; //keep current order
  }
}

