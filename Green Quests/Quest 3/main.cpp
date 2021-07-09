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
         std::string s;
         for (int i = 0; i < size; i++) {
            s += bits[i] ? '1' : '0';
         }
         return s;
      }
      std::string bitsToString(const vector<bool>& bits) {
         int size = bits.size();
         std::string s;
         for (int i = 0; i < size; i++) {
            s += bits[i] ? '1' : '0';
         }
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

      int test_decimal_to_binary(Automaton &a, int n, const vector<int>& expectedResult) {
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

      int test_translate_n_bits_starting_at(Automaton &a, const vector<int>& bits, size_t pos, size_t n, size_t expectedResult) {
         size_t result = a.translate_n_bits_starting_at(bits, pos, n);
         // vector<int> translation(bits.begin() + pos, bits.begin() + pos + n - 1);
         if (result != expectedResult) {
            cout << "Error: translate_n_bits_starting_at(" << bitsToString(bits);
            cout << ", " << pos << ", " << n << ") = " << result << ", expected " << expectedResult << endl;
            // cout << " on translation " << bitsToString(translation) << endl;
            errorCount++;
            return false;
         }
         else {
            cout << "OK: translate_n_bits_starting_at(" << bitsToString(bits) << ", " << pos << ", " << n << ") = " << result << endl;
            return true;
         }
      }

      int test_make_next_gen(Automaton &a, const vector<int> &current_gen, vector<int> &next_gen, vector<int> expectedNextGen, int expectedExtremeBit, bool expectedResult) {
         bool result = a.make_next_gen(current_gen, next_gen);
         if (next_gen != expectedNextGen || a._extreme_bit != expectedExtremeBit || result != expectedResult) {
            cout << "Error: make_next_gen(" << bitsToString(current_gen) << ") with rule " << bitsToString(a._rules) << " = " << bitsToString(next_gen) << ", expected " << bitsToString(expectedNextGen);
            cout << " Error: extreme_bit = " << a._extreme_bit << ", expected " << expectedExtremeBit;
            cout << " Error: result = " << result << ", expected " << expectedResult << endl;
            errorCount++;
            return false;
         }
         else {
            cout << "OK: make_next_gen(" << bitsToString(current_gen) << ") with rule " << bitsToString(a._rules) << " = " << bitsToString(next_gen) << endl;
            return true;
         }
      }

      int test_set_rule(Automaton &a, size_t rule, vector<bool> expectedRuleVector, bool expectedResult) {
         bool result = a.set_rule(rule);
         if (result != expectedResult || a._rules != expectedRuleVector) {
            cout << "Error: set_rule(" << rule << ") = " << bitsToString(a._rules) << ", expected " << bitsToString(expectedRuleVector) << endl;
            errorCount++;
            return false;
         }
         else {
            cout << "OK: set_rule(" << rule << ") = " << bitsToString(a._rules) << endl;
            return true;
         }
      }

      int test_get_first_n_generations(Automaton &a, size_t n, size_t width, string expectedResult) {
         string result = a.get_first_n_generations(n, width);
         if (result != expectedResult) {
            cout << "Error: get_first_n_generations(" << n << ", " << width << ") = " << result << ", expected " << expectedResult << endl;
            errorCount++;
            return false;
         }
         else {
            cout << "OK: get_first_n_generations(" << n << ", " << width << ") = \n" << result << endl;
            return true;
         }
      }
/* 
      int test_generation_to_string(Automaton &a, const vector<int>& gen, size_t width, size_t expectedResult) {
         string result = a.generation_to_string(gen, width);
         if (result != expectedResult) {
            cout << "Error: generation_to_string(" << bitsToString(gen) << ", " << width << ") = " << result << ", expected " << expectedResult << endl;
            errorCount++;
            return false;
         }
         else {
            cout << "OK: generation_to_string(" << bitsToString(gen) << ", " << width << ") = " << result << endl;
            return true;
         }
      }
*/
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
   /*
   t.test_binary_to_decimal(aut, {0, 0, 0}, 0);
   t.test_binary_to_decimal(aut, {1, 0, 1, 0}, 10);
   t.test_binary_to_decimal(aut, {1, 0, 1, 0, 1, 0}, 42);
   t.test_decimal_to_binary(aut, 10, {1, 0, 1, 0});
   t.test_decimal_to_binary(aut, 42, {1, 0, 1, 0, 1, 0});
   for (int i = 0; i < 257; i++) {
      t.test_binary_to_decimal(aut, aut.decimal_to_binary(i), i);
   }
   t.test_binary_to_decimal(aut, aut.decimal_to_binary(-2), 0);
   t.test_binary_to_decimal(aut, {}, 0);
   
   t.test_translate_n_bits_starting_at(aut, {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1}, 2, 5, 21);
   t.test_translate_n_bits_starting_at(aut, {1, 0, 1, 0, 1}, 2, 3, 5);
   
   
   for (int i = 0; i < 257; i++) {
      vector<int> b = aut.decimal_to_binary(i);
      
      b.push_back(0);
      b.push_back(0);
      b.push_back(0);
      b.insert(b.begin(), 0);
      b.insert(b.begin(), 0);
      b.insert(b.begin(), 0);
      
      cout << aut.generation_to_string(b, b.size()+6) << " ";
      t.test_translate_n_bits_starting_at(aut, b, 3, b.size()-6, i);
   }
   cout << aut.generation_to_string({1,1,1}, 0) << endl;
   cout << aut.generation_to_string({1,1,1}, 1) << endl;
   cout << aut.generation_to_string({1,1,1}, 2) << endl;
   */
  /*
   t.test_set_rule(aut, 0, {0, 0, 0, 0, 0, 0, 0, 0}, true);
   t.test_set_rule(aut, 1, {0, 0, 0, 0, 0, 0, 0, 1}, true);
   t.test_set_rule(aut, 30, {0, 0, 0, 1, 1, 1, 1, 0}, true);
   t.test_set_rule(aut, 255, {1, 1, 1, 1, 1, 1, 1, 1}, true);
   t.test_set_rule(aut, 256, {1, 1, 1, 1, 1, 1, 1, 1}, false);
   t.test_set_rule(aut, 257, {1, 1, 1, 1, 1, 1, 1, 1}, false);
   vector<int> next_gen;
   aut.set_rule(0);   t.test_make_next_gen(aut, {},       next_gen, {1},       0, true);
   aut.set_rule(0);   t.test_make_next_gen(aut, {0},       next_gen, {0, 0, 0},       0, true);
   aut.set_rule(0);   t.test_make_next_gen(aut, {1},       next_gen, {0, 0, 0},       0, true);
   aut.set_rule(0);   t.test_make_next_gen(aut, {0, 0, 0}, next_gen, {0, 0, 0, 0, 0}, 0, true);
   aut.set_rule(0);   t.test_make_next_gen(aut, {1, 1, 1}, next_gen, {0, 0, 0, 0, 0}, 0, true);

   aut.set_rule(255);   t.test_make_next_gen(aut, {},       next_gen, {1},       0, true);
   aut.set_rule(255); t.test_make_next_gen(aut, {0}, next_gen, {1, 1, 1}, 1, true);
   aut.set_rule(255); t.test_make_next_gen(aut, {1}, next_gen, {1, 1, 1}, 1, true);
   aut.set_rule(255); t.test_make_next_gen(aut, {0, 0, 0}, next_gen, {1, 1, 1, 1, 1}, 1, true);
   aut.set_rule(255); t.test_make_next_gen(aut, {1, 1, 1}, next_gen, {1, 1, 1, 1, 1}, 1, true);

   aut.set_rule(30); 
   t.test_make_next_gen(aut, {1}, next_gen, {1, 1, 1}, 0, true);
   t.test_make_next_gen(aut, {1, 1, 1}, next_gen, {1, 1, 0, 0, 1}, 0, true);
   t.test_make_next_gen(aut, {1, 1, 0, 0, 1}, next_gen, {1, 1, 0, 1, 1, 1, 1}, 0, true);

   aut.set_rule(18);
   t.test_make_next_gen(aut, {1}, next_gen, {1, 0, 1}, 0, true);
   t.test_make_next_gen(aut, {1, 0, 1}, next_gen, {1, 0, 0, 0, 1}, 0, true);
   t.test_make_next_gen(aut, {1, 0, 0, 0, 1}, next_gen, {1, 0, 1, 0, 1, 0, 1}, 0, true);

   t.test_get_first_n_generations(aut, 4, 11, "     *     \n    * *    \n   *   *   \n  * * * *  \n");
   aut.set_rule(30);
   t.test_get_first_n_generations(aut, 4, 11, "     *     \n    ***    \n   **  *   \n  ** ****  \n");
   //cout << aut.get_first_n_generations(4, 11);
   cout << "generation to string " << aut.generation_to_string({0, 1, 1, 1, 0}, 3) << endl;
   cout << "generation to string " << aut.generation_to_string({1, 1, 1, 1, 1}, 9) << endl;
   */

  cout << aut.get_first_n_generations(100, 101) << endl;
}