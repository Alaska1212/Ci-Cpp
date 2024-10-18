#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int m;
    int j;

    cout << " m =  ";
    cin >> m;
    cout << " j = ";
    cin >> j;

    int x = ~(1 << j);
    m = m & x;

    cout << "Result in 10 system : " << m << endl;
    cout << "Result in 16 system : " << hex << m << endl;

    return 0;
}
