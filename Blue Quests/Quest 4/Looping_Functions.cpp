// Student ID: 12345678
// TODO - Replace the number above with your actual Student ID
//
// Looping_Functions.cpp
//
// Created by Anand Venkataraman on 8/9/19.
// Copyright © 2019 Anand Venkataraman. All rights reserved.
//
#include <iostream>
#include <sstream>
using namespace std;
// Give the user 6 chances to guess the secret number n (0-10). If they get it,
// say so and return true. Else say so and return false.
bool play_game(int n) {
  int guess;
  string user_input;
  bool numberFound = false;
  cout << "Welcome to my number guessing game" << endl << endl;
  for (int i=0; i<6; i++) {
    if (numberFound == false) {
      cout << "Enter your guess: ";
      getline(cin, user_input);
      istringstream(user_input) >> guess;
      cout << endl << "You entered: " << guess << endl;
      if (guess == n) {cout << "You found it in " << i+1 << " guess(es).\n"; numberFound = true; return true;}
    }
  }
  if (numberFound == false) {
    cout << "I'm sorry. You didn't find my number." << endl;
    cout << "It was " << n;
    return false;
  }
  return false;
}
// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term.
double etox(double x, size_t n) {
  double sum;
  if (n == 0) {return 0;};
  if (n == 1) {return 1;};
  for (size_t i = 0; i < n; i++) {
  double currentX = 1;
  double currentFactorial = 1;
    for (size_t j = 0; j < i; j++) {
      currentX *= x;
    }
    for (size_t k = 1; k <= i; k++) {
      //cout << "currentFactorial before is " << currentFactorial << endl;
      currentFactorial *= k;
      //cout << "currentFactorial after is " << currentFactorial << endl;
    }
    //cout << x << "^" << i << " is " << currentX << endl;
    //cout << i << "! is " << currentFactorial << endl << endl;
    sum += double (currentX) / currentFactorial;
  }
  return sum;
} 
// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c) {
  size_t count = 0;

  for (size_t i = 0; i < s.size(); i++)
    if (s[i] == c) count++;

  return count;
}
// Use Euclid's algorithm to calculate the GCD of the given numbers
size_t gcd(size_t a, size_t b) {
  while (a != b)
    {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
 
    return a;
}
// Return a string of the form n1,n2,n3,... for the given AP.
string get_ap_terms(int a, int d, size_t n) {
  string s = "";
  int currentTerm;
  for (size_t i=0; i<n; i++) {
    currentTerm = a+(i)*d;
    s = s + to_string(currentTerm) + ",";
  }
  s = s.substr(0,s.size()-1);
  return s;
}
// Return a string of the form n1,n2,n3,... for the given GP.
string get_gp_terms(double a, double r, size_t n) {
  string s = "";
  double currentTerm;
  double currentPower = 1;
  for (size_t i=0; i<n; i++) {
    for (size_t j=0; j<i; j++) {
      currentPower *= r;
    }
    currentTerm = a*currentPower;
    currentPower = 1;
    s = s + to_string(currentTerm) + ", ";
  }
  return s;
}
double get_nth_fibonacci_number(size_t n) {
  if (n <= 1)
      return n;
   return get_nth_fibonacci_number(n-1) + get_nth_fibonacci_number(n-2);
}


// 5 Ratnaprakasa Rubies polished for Royal Crowns (play game).