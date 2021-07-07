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
  Automaton aut(3, 0);
  vector<int> test{1, 1, 0, 0};
  cout << aut.binary_to_decimal(test);
}