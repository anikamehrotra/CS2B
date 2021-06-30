// Student ID: 20480681

#include <iostream>
#include <sstream>

#include "Hanoi.h"

using namespace std;

void tower(int a,char from,char aux,char to){
    if(a==1){
       cout<<"\t\tMove disc 1 from "<<from<<" to "<<to<<"\n";
       return;
    }
    else{
       tower(a-1,from,to,aux);
       cout<<"\t\tMove disc "<<a<<" from "<<from<<" to "<<to<<"\n";
       tower(a-1,aux,from,to);
    }
}