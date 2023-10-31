#ifndef ADD_H
#define ADD_H

int add(int, int);

#ifdef USE_SQR_MACRO // conditional compilation
#define SQR(n) ((n) * (n));
#else
inline int SQR(int n) { return n * n; }
#endif // USE_SQR_MACRO

#endif // ADD_H