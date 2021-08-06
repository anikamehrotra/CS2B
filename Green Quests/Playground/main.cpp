#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

typedef unsigned char byte;
/*
class Base {
    public:

        void methodX() {
            cout << "Base" << endl;
        };
};

class Sub : public Base {
    public:

        void methodX() {
            cout << "Sub" << endl;
        };
};

int main() {

   double *dubArray1 = new double[100];
   double *dubArray2 = new double[75];
      
   // there are no intervening statements.  
   // immediately following we have:
   dubArray1 = dubArray2;
   dubArray1[75] = 9;   
   

   Base *b = new Base();
   Sub *s = new Sub();

   b->methodX();
   s->methodX();
   b = s;
   b->methodX();
s->methodX();
   /*
    byte bits[128];
    for (size_t i = 0; i < 128; i++) {
            byte b = (byte)i;
            bits[i] = b;
    }

    for (size_t i = 0; i < 128; i++) {
            cout << (int)(bits[i]) << "\n";
    }
    
   for (int n = 0; n < 65; n++) {
    cout << "n: " << n;
    cout << " | bits[n/8]: " << (std::bitset<8>) bits[n/8];
    cout << " | (bits[n/8] >> (n%8 + 1) & 1): " << (int)(bits[n/8] >> (n%8 + 1) & 1);
    cout << " | (bits[n/8] >> (8 - n%8 - 1) & 1): " << (int)(bits[n/8] >> (8-n%8 - 1) & 1);
    cout << endl;
   }
}
 */


/*
// --------- BASE AND DERIVED CLASSES -------------
class Base
{
public:
  void fun() { cout << "Base\n"; }
};

class Derived : public Base
{
public:
  void fun(){ cout << "Derived\n"; }
};

// ---------------- CLIENT -------------------------
void main()
{
  Base b, *bp = &b;
  Derived d, *dp = &d;

  bp->fun();
  dp->fun();
  bp = dp;
  bp->fun();
}
*/

void main() {
	
}