#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Automaton.h"
#include "Automaton.cpp"
using namespace std;

class Tests {
    public:
        int errorCount = 0;

   public:
      std::string bitsToString(const vector<int>& bits) {
         int size = bits.size();
         std::string s(bits.begin(), bits.end());
         return s;
      }
      int test_binary_to_decimal(Automaton &a, const vector<int>& bits, size_t expectedResult) {
         int result = a.binary_to_decimal(bits);
         if (result != expectedResult) {
            cout << "Error: binary_to_decimal(" << bitsToString(bits) << ") = " << result << ", expected " << expectedResult << endl;
            errorCount++;
            return false;
         }
         else {
            cout << "OK: binary_to_decimal(" << bitsToString(bits) << ") = " << result << endl;
            return true;
         }
      }

      int test_decimal_to_binary(Automaton &a, size_t n, const vector<int>& expectedResult) {
         vector<int> result = a.decimal_to_binary(n);
         if (result != expectedResult) {
            cout << "Error: decimal_to_binary(" << n << ") = " << bitsToString(result) << ", expected " << bitsToString(expectedResult) << endl;
            errorCount++;
            return false;
         }
         else {
            cout << "OK: decimal_to_binary(" << n << ") = " << bitsToString(result) << endl;
            return true;
         }
      }
};

int main()
{
    /*
   size_t rule, k;

   // get rule from user
   do
   {
      cout << "Enter Rule (0 - 255): ";
      cin >> rule;
   } while (rule < 0 || rule > 255);

   // create automaton with this rule and single central dot
   Automaton aut(3, rule);

   // now show it
   cout << "   start"  << endl;
   for (k = 0; k < 100; k++)
   {

      cout << aut.generation_to_string(k, 79) << endl;
      aut.make_next_gen(k, 79);
   }
   cout << "   end"  << endl;
   
   return 0;
   */
   // cout << "hello" << endl;
   Automaton aut(3, 30);
   Tests t;
   t.test_binary_to_decimal(aut, {1, 0, 1, 0}, 10);
   t.test_binary_to_decimal(aut, {1, 0, 1, 0, 1, 0}, 42);
   t.test_decimal_to_binary(aut, 10, {1, 0, 1, 0});
   t.test_decimal_to_binary(aut, 42, {1, 0, 1, 0, 1, 0});
}