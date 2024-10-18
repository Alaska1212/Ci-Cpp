#include <iostream>
using namespace std;

double v(int i){
    double v0 = 1;
    double v1 = 0.3;
    double v2;
    if(i == 0){
        return 1;
    }
    else if (i == 1){
        return 0.3;
    }
    else{
        for(double a = 2; a <= i; a++){
        v2 = (a + 2)*v0;
        v0 = v1;
        v1 = v2;
    }
    return v2;
    }

}


int main(){
    cout << "i = ";
    int i;
    cin >> i;
    cout << v(i) << endl;

    return 0;
}
