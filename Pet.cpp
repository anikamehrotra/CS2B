// Pet.cpp
// 2a-Lab-06-Pets
//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Pet.h"
using namespace std;
// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;

Pet::Pet(string name, long id, int num_limbs) {
  _name = name;
  //if(!set_name(name)) {_name = "";}
  _id = id;
  //if(!set_id(id)) {_id = -1;}
  _num_limbs = num_limbs;
  //if(!set_num_limbs(num_limbs)) {_num_limbs = 0;}
  _population++;
}
Pet::~Pet() {
  _population--;
}
string Pet::get_name() const { return _name; }
long Pet::get_id() const {
  return _id;
}
int Pet::get_num_limbs() const {
  return _num_limbs;
}
bool Pet::set_name(string name) { 
  if (name == "") {return false;}
  else {_name = name; return true;}
}
bool Pet::set_id(long id) {
  if (id < 0) {return false;}
  else {_id = id; return true;}
}
bool Pet::set_num_limbs(int num_limbs) {
  if (num_limbs < 0) {return false;}
  else {_num_limbs = num_limbs; return true;}
}
string Pet::to_string() const {
  stringstream ss;
  ss << _id;
  string id = ss.str();

  stringstream s;
  s << _num_limbs;
  string num_limbs = s.str();
  cout << _num_limbs;
  cout << num_limbs;

  return "(Name: " + _name + ", ID: " + id + ", Limb Count: " + num_limbs + ")";
}
// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.
void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len) {
  // TODO - Resize pets as necessary
  pets.resize(n);
  long prev_id = 0;
  string name = "";
  for (size_t i = 0; i < n; i++) {
    long id = prev_id + 1 + rand() % 10;
    pets[i].set_id(id);
    pets[i].set_num_limbs(rand() % 9); // up to arachnids
    // TODO - make and set a name of the requested length
    name = make_a_name(name_len);
    pets[i].set_name(name);
    // TODO - adjust prev_id as necessary
    prev_id = id;
  }
}
// ---------------------------------------------------------------------
string Pet::make_a_name(int len) {
  string vowels = "aeiou";
  string consonants = "bcdfghjklmnpqrstvwxyz";
  string finalString = "";
  bool startWithConsonant = false;
  
  // if startLetter is true -> consonant
  if (rand() % 2 == 0) {startWithConsonant = true;}
  if (startWithConsonant == false) {
    for (int i = 0; i < len; i++) {
      if (i % 2 == 0) {finalString.push_back(vowels[rand() % vowels.length()]);}
      else {finalString.push_back(consonants[rand() % consonants.length()]);}
    }
  }
  else {
    for (int i = 0; i < len; i++) {
      if (i % 2 == 0) {finalString.push_back(consonants[rand() % 21]);}
      else {finalString.push_back(vowels[rand() % 5]);}
    }
  }
  return finalString;
}
// Optional EC points
// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2) {
  return true;
} 
bool operator!=(const Pet& pet1, const Pet& pet2) {
  return true; 
}
ostream& operator<<(ostream& os, const Pet& pet) {
  return os;
}
