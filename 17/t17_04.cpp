#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex() : real(0), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    void input() {
        cout << "Enter the real part: ";
        cin >> real;
        cout << "Enter the imaginary part: ";
        cin >> imag;
    }

    void output() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cerr << "Error: Division by zero!" << endl;
            exit(1);
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    double getReal() const { return real; }

    double getImag() const { return imag; }
};

Complex arctgSeries(const Complex& z, double epsilon) {
    if (z.modulus() >= 1) {
        cerr << "Error: The value of |z| must be less than 1." << endl;
        exit(1);
    }
    Complex sum = z;
    Complex term = z;
    int n = 1;

    while (true) {
        term = term * z * z;
        term = Complex(term.getReal() * -1, term.getImag());
        Complex nextTerm = term / Complex(2 * n + 1, 0);

        if (nextTerm.modulus() < epsilon)
            break;

        sum = sum + nextTerm;
        ++n;
    }

    return sum;
}


int main() {
    Complex z;
    cout << "Enter the complex number z:\n";
    z.input();

    double epsilon;
    cout << "Enter the value of epsilon: ";
    cin >> epsilon;

    Complex result = arctgSeries(z, epsilon);
    cout << "Series sum: ";
    result.output();

    return 0;
}
