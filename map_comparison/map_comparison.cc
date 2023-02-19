#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void func_map (vector<pair<int,string>>&);
void func_unordered_map (vector<pair<int,string>>&);

int main (){
  vector<pair<int,string>> items = {
    {3, "three"},
    {13, "thirteen"},
    {2, "two"},
    {7, "seven"},
    {11, "eleven"},
    {20, "twenty"},
    {5, "five"},
    {96, "ninety six"},
    {97, "ninety seven"},
    {23, "twenty three"},
    {4, "four"},
    {59, "fifty nine"},
    {17, "seventeen"},
    {1, "one"}
  };

  func_map(items);
  func_unordered_map(items);

  return 0;
}

void func_map (vector<pair<int,string>>& items){
  cout << endl << "=== BEGIN func_map ===" << endl;

  map<int,string> maptastic;
  
  for (const auto& pair : items){
    maptastic.insert(pair);
  }

  for (const auto& pair : maptastic){
    cout << "Key: " << pair.first << endl;
    cout << "Val: " << pair.second << endl;
  }

  cout << endl << "=== END func_map ===" << endl;
}


void func_unordered_map (vector<pair<int,string>>& items){
  cout << endl << "=== BEGIN func_unordered_map ===" << endl;

  unordered_map<int,string> sloppy;
  
  for (const auto& pair : items){
    sloppy.insert(pair); 
    cout << "Inserted: " << pair.first << endl;
    cout << "[N,B,LF] = [" << sloppy.size() << "," << sloppy.bucket_count() << "," << sloppy.load_factor() << "]" << endl;
  }
  
  cout << endl;

  for (const auto& pair : sloppy){
    cout << "Key: " << pair.first << endl;
    cout << "Val: " << pair.second << endl;
  }

  cout << endl << "=== END func_unordered_map ===" << endl;
}
