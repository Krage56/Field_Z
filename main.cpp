#include "Field_Z.h"
using namespace std;
int main() {
    Field_Z l1, l2(4, 3);
    l1 = 6;
    l1 = l2;
    cout << l2 << '\n';
    l1[8] = 9;
    cout << l1 << '\n';
    l2[8] = 7;
    Field_Z l3(l2 + l1);
    //l3 = l2 + l1;
    l3 = 10;
    cout << l3 << '\n';
    Field_Z l4;
    l4 = l2 * 3;
    //l4 = 3 * l2;
    cout << l4 << endl;
    l4 = l4 - 3;
    cout << l4 << endl;
    l4[11] = 5;
    cout << l4 << endl;
    l3[11] = 2;
    Field_Z l5 = l4 / l3;
    cout << l5 << endl;
    l5 = l5/4;
    cout << l5 << endl;
    l5 = 3 + l5;
//    cout << l5 << endl;
//    l5 = 6 - l5;
    cout << l5 << endl;
    l5 = 8 / l5;
    cout << l5 << endl;
    return 0;
}
