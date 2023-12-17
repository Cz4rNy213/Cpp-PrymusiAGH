#include <iostream>
#include <iostream>

using std::cout;
using std::endl;

typedef struct ValueStruct
{
  bool boolVal;
  int intVal;
  double doubleVal;
} ValueStructT;

/*
* An enumeration - a type with a set of named constants (enumerators).
* enum class (a scoped enumeration) an enum where:
*  - the enumerators are within the scope of the enumeration,
*  - no implicit conversions to other types are provided.
*/
enum class Type { BoolT, IntT, DoubleT };

// A union is a struct that holds the value of just one of its elements at any time.
typedef union Value
{
  bool boolVal;
  int intVal;
  double doubleVal;
} ValueT;

typedef struct DataNode
{
  Type t;
  ValueT val;
} DataNode;

DataNode createBoolDataNode(bool value)
{
  DataNode dn;
  dn.t = Type::BoolT;
  dn.val.boolVal = value;
  return dn;
}

DataNode createIntDataNode(int value){
    DataNode dn;
    dn.t = Type::IntT;
    dn.val.intVal = value;
    return dn;
}

DataNode createDoubleDataNode(double value){
    DataNode dn;
    dn.t = Type::DoubleT;
    dn.val.doubleVal = value;
    return dn;
}

void unionDemo()
{
  cout << "unionDemo(): " << endl;

  cout << "sizeof(struct ValueStruct) = " << sizeof(struct ValueStruct) << endl;
  cout << "sizeof(union Value) = " << sizeof(union Value) << endl;

  DataNode d = createBoolDataNode(true);
  cout << "d.val.boolVal = " << (d.val.boolVal ? "true" : "false") << endl;
}

void cStyleStructDemo()
{
  cout << "cStyleStructDemo(): " << endl;
  // A structure is a sequence of elements (called members) of arbitrary types.
  struct S1 {
     long l1;
     double d1;
  } s {1,1.5};

  cout << "s.l1 = " << s.l1 << ", s.d1 = " << s.d1 << endl;

  typedef struct S2 {
    long l2;
    double d2;
  } S2_T;

  S2_T *pS2 = new S2_T;
  pS2->l2 = 2; // = (*pS2).i2 = 2;
  (*pS2).d2 = 2.5;
  cout << "pS2->i2 = " << pS2->l2 << ", (*pS2).d2 = " << (*pS2).d2 << endl;
  delete pS2;
}

// bitfield
struct IEEE754
{
  uint32_t mantissa: 23,
               exponent: 8,
                   sign: 1;
};

void castDemo()
{
  cout << "castDemo(): " << endl;

  const float dN = 1.5399896E-36f;
  // Note: "struct" is not needed in C++, i.e. (struct IEEE754) ~ IEEE754
  cout << "sizeof(struct IEEE754) = " << sizeof(struct IEEE754) << endl;
  cout << dN << " decomposed with the use of bitfields: ";

  // 1. Bitfield (as a memory map) + reinterpret_cast
  const IEEE754 *pI3E754 = reinterpret_cast<const IEEE754*>(&dN);
  printf("sign = 0x%x, exponent = 0x%x, mantissa = 0x%x\n",
         pI3E754->sign, pI3E754->exponent, pI3E754->mantissa);

  // 2. reinterpret_cast + bitmasks and bit-shifts
  const unsigned int floatAsUInt = *reinterpret_cast<const unsigned int*>(pI3E754);
  printf("dN as unsigned int = %x\n", floatAsUInt);

  constexpr auto signMask = 0x1u;
  const unsigned int sign = (floatAsUInt >> 31) & signMask;

  constexpr auto exponentMask = 0xFFu;
  const unsigned int exponent = (floatAsUInt >> 23) & exponentMask;

  constexpr auto mantissaMask = 0x7FFFFFu;
  const unsigned int mantissa = floatAsUInt & mantissaMask;

  cout << dN << " decomposed with the use of bitmasks: ";
  printf("sign = 0x%x, exponent = 0x%x, mantissa = 0x%x\n",
         sign, exponent, mantissa);
}

int main()
{
  cStyleStructDemo();
  cout << endl;
  unionDemo();
  cout << endl;
  castDemo();
  DataNode d;
  d = createIntDataNode(1);
  cout << "d.val.intVal = " << d.val.intVal << endl;

  d = createDoubleDataNode(1.5);
  cout << "d.val.doubleVal = " << d.val.doubleVal << endl;
  return 0;
}