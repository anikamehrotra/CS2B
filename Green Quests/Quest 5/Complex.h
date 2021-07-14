// Student ID: 20480681

#ifndef Automaton_h
#define Automaton_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Complex {
    private:
        double _real, _imag;

    public:
        static constexpr double FLOOR = 1e-10; // Threshold
        Complex (double re = 0.0, double im = 0.0) : _real(re), _imag(im) {
            set_real(re);
            set_imag(im);
        };
        double get_real() const { return _real; }
        double get_imag() const { return _imag; }
        void set_real(double re) { _real = re; }
        void set_imag(double im) { _imag = im; }

        string to_string() const {
            char buffer[50];
            sprintf(buffer, "(%.11g,%.11g)", _real, _imag);
            return string(buffer);
        };
        double norm_squared() const { return _real * _real + _imag * _imag;}; 
        double norm() const { return sqrt(norm_squared()); }

        Complex reciprocal() const {
            if (norm_squared() <= Complex::FLOOR) {throw Div_By_Zero_Exception();};
            return Complex(_real / norm_squared(), -_imag / norm_squared());
        };
        Complex& operator= (const Complex & rhs) {set_real(rhs.get_real()); set_imag(rhs.get_imag()); return *this;};

        class Div_By_Zero_Exception {
            public:
                string to_string() const {return "Divide by zero exception";};
                string what() const {return "Divide by zero exception";};
        };

        // operators (only the most common ones)
        Complex operator+ (const Complex & that) const {return Complex(_real + that._real, _imag + that._imag);};
        Complex operator- (const Complex & that) const {return Complex(_real - that._real, _imag - that._imag);};
        Complex operator* (const Complex & that) const {return Complex(_real * that._real - _imag * that._imag, _real * that._imag + _imag * that._real);};
        Complex operator/ (const Complex & that) const {return *this * that.reciprocal();};

        bool operator==(const Complex & that) const {if (_real == that._real && _imag == that._imag) return true; else return false; };
        bool operator!=(const Complex & that) const { return !(*this == that);};
        bool operator<(const Complex & that) const { return norm() < that.norm();};

        friend ostream& operator<< (ostream& os, const Complex& x) {return os << x.to_string();};
        friend class Tests;
        
};

#endif /* Automaton_h */