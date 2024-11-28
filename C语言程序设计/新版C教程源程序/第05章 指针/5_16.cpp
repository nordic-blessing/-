#include <iostream>
using namespace std;
int main()
{
    char *str[] = {"First", "Second", "Third"};
    char **p = 0;
    p = str;
    cout << *++p << endl;
    return 0;
}
