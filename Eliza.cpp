// Student ID: 20480681

// Eliza.cpp
// 2a.Lab-05-Eliza
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
//
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.
string rotate_vowels(string& s) {
  char toLookFor;
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  string finalString = s;
  for (int vowelCount = 0; vowelCount < 5; vowelCount++) {
    toLookFor = vowels[vowelCount];
    if (vowelCount < 4) {
      for (size_t i=0; i < s.size(); i++) {
        if (s[i] == toLookFor) {finalString[i]=vowels[vowelCount+1];}
      }
    }
    else {
      for (size_t i=0; i<s.size(); i++) {
        if (s[i] == toLookFor) {finalString[i]='a';}
      }
    }
  }
  s = finalString;
  return s;
}
// Return a string in which all occurrences of s have been replaced by th
string lispify(string s) {
  string string;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == 's') {string.push_back('t'); string.push_back('h');}
    else if (s[i] == 'S') {string.push_back('T'); string.push_back('h');}
    else {string.push_back(s[i]);}
  }
  return string;
}
// Enter the user-interaction loop as described earlier
void enter() {
  
  bool stop = true;
  string line = "";
  int exclamationCount = 0;
  int sCount = 0;
  while(stop == true) {
    getline(cin, line);
    if(line.size() == 0) {enter();}
    else {
      cout << "    " << line << endl << endl;
      for(size_t i=0; i<line.size(); i++) {
        if (line[i] == '!') {exclamationCount++;}
      }
      for(size_t i=0; i<line.size(); i++) {
        if (line[i] == 's') {sCount++;}
      }
      if (exclamationCount > 0) {cout << "OMG! You don't say!! " << line << "!!!!!" << endl; enter();}
      else if (!line.find("why") || !line.find("what")) {cout << "I'm sorry, I don't like questions that contain what or why."; enter();}
      else if (sCount > 0) {cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl << lispify(line) << "! Sheesh! Now what?"; enter();}
      else if (!line.find("bye") || !line.find("Bye") || !line.find("quit") || !line.find("Quit")) {cout << "Ok Bye. Nice being a force of change in your life." << endl; stop = false;}
      else {
        if (rand() % 10 == 8 || rand() % 10 == 9) {
          cout << "Huh? Why do you say: " << line << "?" << endl;
        }
        else {cout << rotate_vowels(line) << "?" << endl;}
      }
    }
  }
}

