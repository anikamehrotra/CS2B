#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Pet.cpp"
#include "Pet.h"
using namespace std;

int main() {
  Pet p("pet", 102, -78);
  cout << p.to_string();
  vector<Pet> pets;
  p.get_n_pets(5, pets, 1);
  for (int i=0; i < 5; i++) {
    cout << pets[i].to_string() << endl;
  }
}