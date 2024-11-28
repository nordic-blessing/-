#include <iostream>
using namespace std;
int a;
static int b;
int main()
{
    static int c;
    register int d;
    int e;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    cout << "d=" << d << endl;
    cout << "e=" << e << endl;
    return 0;
}
