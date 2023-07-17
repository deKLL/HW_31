#include <iostream>
using namespace std;

class drib {
private:
    int integerPart;
    short dribPart;

public:
    drib(int integer = 0, short drib = 0) : integerPart(integer), dribPart(drib) {}
    drib operator+(const drib& other) const {
        int newInteger = integerPart + other.integerPart;
        short newdrib = dribPart + other.dribPart;
        if (newdrib > 999) {
            newdrib -= 1000;
            newInteger++;
        }
        return drib(newInteger, newdrib);
    }
    drib operator-(const drib& other) const {
        int newInteger = integerPart - other.integerPart;
        short newdrib = dribPart - other.dribPart;
        if (newdrib > dribPart) {
            newdrib += 1000;
            newInteger--;
        }
        return drib(newInteger, newdrib);
    }
    void print() const {
        cout << integerPart << "." << dribPart << endl;
    }
};

int main() {
    drib drib1(1);  // you can change numbers
    drib drib2(2, 500);
    
    drib sum = drib1 + drib2;
    drib difference = drib1 - drib2;

    cout << "Sum: ";
    sum.print();
    cout << "Minus: ";
    difference.print();

    return 0;
}
