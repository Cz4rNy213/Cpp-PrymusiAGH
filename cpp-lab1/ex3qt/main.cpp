#include <iostream>

using namespace std;

void printSizeOfTypes()
{
    cout << "size of selected C++ types:" << endl;
    cout << "sizeof(int) = " << sizeof (int) << endl;
    cout << "sizeof(int*) = " << sizeof(int*) << endl;
    cout << "sizeof(int&) = " << sizeof(int&) << endl;
    cout << "sizeof(const int) = " << sizeof(const int) << endl;
    cout << "sizeof(const int*) = " << sizeof(const int *) << endl;
    cout << "sizeof(const int&) = " << sizeof(const int&) << endl;

    printf("sizeof(bool) = %lu\n", sizeof(bool));
    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(long long int) = %lu\n", sizeof(long long int));
    printf("sizeof(unsigned char) = %lu\n", sizeof(unsigned char));
    printf("sizeof(unsigned long long int) = %lu\n", sizeof(unsigned long long int));
    printf("sizeof(float) = %lu\n", sizeof(float));
    printf("sizeof(double) = %lu\n", sizeof(double));
    printf("sizeof(long double) = %lu\n", sizeof(long double));
    printf("sizeof(int8_t) = %lu\n", sizeof(int8_t));
    printf("sizeof(int64_t) = %lu\n", sizeof(int64_t));
    printf("sizeof(uint8_t) = %lu\n", sizeof(uint8_t));
    cout << endl;
}

void printSizeOfVariables()
{
    cout << "size of variables and constant values:" << endl;

    int iv = 1;
    int *piv = &iv; // pointer to int
    int &riv = iv; // reference to T
    int &&rriv = static_cast<int &&>(iv); // rvalue reference to int

    cout << "sizeof(int iv) = " << sizeof(iv) << endl;
    cout << "sizeof(int *piv) = " << sizeof(piv) << endl;
    cout << "sizeof(int &riv) = " << sizeof(riv) << endl;
    cout << "sizeof(int &&rriv) = " << sizeof(rriv) << endl;

    const int ci = 2; // a named constant
    const int *pci = &ci; // pointer to constant int
    const int &rci = ci; // reference to constant int
    const int &&rrci = static_cast<const int &&>(ci); // rvalue reference to constant int

    cout << "sizeof(const int ci) = " << sizeof(ci) << endl;
    cout << "sizeof(const int *pci) = " << sizeof(pci) << endl;
    cout << "sizeof(const int &rci) = " << sizeof(rci) << endl;
    cout << "sizeof(const int &&rrci) = " << sizeof(rrci) << endl;

    constexpr int cexpr = 2; // constant compile-time expression
    cout << "sizeof(cexpr) = " << sizeof(cexpr) << endl;

    int a[5] = {1,2,3,4,5}; // array of 5 ints
    cout << "sizeof(a), the array of 5 int elements = " << sizeof(a) << endl;
}

int main()
{
    printSizeOfTypes();
    printSizeOfVariables();
    return 0;
}
