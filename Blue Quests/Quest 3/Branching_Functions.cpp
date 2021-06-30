// Student ID: 20480681

//
// Branching-Functions.cpp
// 2a-Lab-03
//

/* UNFINISHED DID NOT RECEIVE ALL TROPHIES */

#include <iostream>
using namespace std;

// Forward declarations of functions that will be used in this file
// before their definitions are encountered by the compiler
double mean_of_3(int n1, int n2, int n3);
int max_of_5(int n1, int n2, int n3, int n4, int n5);
int min_of_5(int n1, int n2, int n3, int n4, int n5);
bool sides_make_triangle(int a, int b, int c);
bool angles_make_triangle(int A, int B, int C);
bool is_a_leap_year(int year);

// This function returns the mean the three numbers passed
// in as parameters. Note that the mean may not be a round
// number. So you must use the double datatype for it.
double mean_of_3(int n1, int n2, int n3) {
  double average = double (n1 + n2 + n3)/3;
  return average;
}
// This function returns the maximum of the 5 given numbers
int max_of_5(int n1, int n2, int n3, int n4, int n5) {
  int array[] = {n1, n2, n3, n4, n5};
  int max = array[0];
  for(int i=0; i<5; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}
// This function returns the minimum of the 5 given numbers
int min_of_5(int n1, int n2, int n3, int n4, int n5) {
  int array[] = {n1, n2, n3, n4, n5};
  int min = array[0];
  for(int i=0; i<5; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}
// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid trianges. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays
bool sides_make_triangle(int a, int b, int c) {
  bool test1 = false;
  bool test2 = false;
  bool test3 = false;
  if (a + b >= c) {test1 = true;};
  if (a + c >= b) {test2 = true;};
  if (b + c >= a) {test3 = true;};

  if (test1 == false || test2 == false || test3 == false) {return false;}
  else {return true;}
}
// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle. Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle
bool angles_make_triangle(int A, int B, int C) {
  if (A + B + C == 180) {return true;}
  else {return false;}
}
// Return true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy) {
  if (yyyy % 4 == 0) {
      if (yyyy % 100 == 0) {
        if (yyyy % 400 == 0) {return true;}
        else {return false;};
      } 
      else {return true;};
  } 
  else {return false;};
}
