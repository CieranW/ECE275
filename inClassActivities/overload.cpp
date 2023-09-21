#include <iostream>
#include <iomanip>
using namespace std;

class Mycomplex
{
public:
    Mycomplex(); // set both to 0
    Mycomplex(double real, double imag);
    void SetReal(double real);
    void SetImag(double imag);
    double GetReal() const;
    double GetImag() const;
    void PrintComplex() const;
    // print as (C_re + iC_imag)

    // Overload arithmetic operator
    // Mycomplex operator+(Mycomplex rhs);
    // Mycomplex operator-(Mycomplex rhs);
    // Mycomplex operator*(Mycomplex rhs);
    // Mycomplex operator/(Mycomplex rhs);

private:
    double C_re;
    double C_imag;
};

Mycomplex::Mycomplex() : C_re(0.0), C_imag(0.0) {}

Mycomplex::Mycomplex(double real, double imag) : C_re(real), C_imag(imag) {}

void Mycomplex::SetReal(double real) { C_re = real; }
void Mycomplex::SetImag(double imag) { C_imag = imag; }
double Mycomplex::GetReal() const { return C_re; }
double Mycomplex::GetImag() const { return C_imag; }

void Mycomplex::PrintComplex() const
{
    if (C_re == 0 && C_imag == 0)
        cout << 0;
    else if (C_re == 0 && C_imag > 0)
        cout << "(i" << C_imag << ")";
    else if (C_re == 0 && C_imag < 0)
        cout << "(-i" << -C_imag << ")";
    else if (C_imag == 0)
        cout << C_re;
    else if (C_imag > 0)
        cout << "(" << C_re << " + i" << C_imag << ")";
    else if (C_imag < 0)
        cout << "(" << C_re << " - i" << -C_imag << ")";
}

int main(void)
{
    Mycomplex z1(5, 2);
    Mycomplex z2(1, 4);
    cout << fixed << setprecision(2);

    z1.PrintComplex();
    cout << " + ";
    z2.PrintComplex();
    cout << " = ";
    Mycomplex z3;
    z3 = z1 + z2;
    z3.PrintComplex();
    cout << endl;

    z1.PrintComplex();
    cout << " - ";
    z2.PrintComplex();
    cout << " = ";
    z3 = z1 - z2;
    z3.PrintComplex();
    cout << endl;

    z1.PrintComplex();
    cout << " * ";
    z2.PrintComplex();
    cout << " = ";
    z3 = z1 * z2;
    z3.PrintComplex();
    cout << endl;

    z1.PrintComplex();
    cout << " / ";
    z2.PrintComplex();
    cout << " = ";
    z3 = z1 / z2;
    z3.PrintComplex();
    cout << endl;

    if (z1 == z2)
        cout << "same" << endl;
    else
        cout << "not equal" << endl;
}
