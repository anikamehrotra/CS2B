#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

typedef unsigned char byte;

class Base {
    public:

        int methodX() {
            cout << "Base" << endl;
            return 0;
        };
};

class Sub : public Base {
    public:

       int methodX() {
            cout << "Sub" << endl;
            return 0;
        };
};

int main() {
/*
   double *dubArray1 = new double[100];
   double *dubArray2 = new double[75];
      
   // there are no intervening statements.  
   // immediately following we have:
   dubArray1 = dubArray2;
   dubArray1[75] = 9;   
   */  

   Base *b = new Base();
   Sub *s = new Sub();

   b->methodX();
   s->methodX();
   b = s;
   b->methodX();

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
 */
}