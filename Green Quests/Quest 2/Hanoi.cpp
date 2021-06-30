// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Hanoi.h"

using namespace std;

std::string get_moves(int num_discs, int src, int dst, int tmp) {
    if (num_discs == 0) {return "";}
    return get_moves(num_discs - 1, src, tmp, dst) + " " + to_string(src) + " -> " + to_string(dst);
    if (num_discs == 1) {return ;}
}

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