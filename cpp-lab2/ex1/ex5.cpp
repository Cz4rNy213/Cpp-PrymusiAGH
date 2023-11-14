#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int sum1(int elems[], size_t size)
{
  int sum = 0;
  size_t i = 0;

  while (i < size) {
    sum += elems[i];
    ++i;
  }

  return sum;
}

int sum2(int elems[], size_t size)
{
 int sum = 0;

 if (size > 0) {
   size_t i = 0;
   do {
     sum += elems[i];
     ++i;
   } while (i < size);
 }

 return sum;
}

int sum3(int elems[], size_t size)
{
  int sum = 0;

  for (size_t i = 0; i < size; ++i) {
    sum += elems[i];
  }

  return sum;
}

int sum4(const vector<int> &elems)
{
  int sum = 0;

  for (auto e : elems) {
    sum += e;
  }

  return sum;
}

int sumEven(int elems[], size_t size)
{
  int sum = 0;

  for (size_t i = 0; i < size; ++i) {
    if (elems[i] % 2 == 1) {
      // the continue statement 'jumps over' one iteration in the loop
      continue;
    }
    sum += elems[i];
  }

  return sum;
}

int indexOfM(int m, int elems[], size_t size)
{
  int idxOfM = -1;

  for (size_t i = 0; i < size; ++i) {
    if (elems[i] == m) {
      idxOfM = static_cast<int>(i);
      break; // the break statement 'jumps out' of a loop
    }
  }

  return idxOfM;
}
float fun2()
{
   float x = 0.0f;
    while(0 < x - 1.0f < 1e-6){

   //while (x != 1.0f)  pętla jest nieskończona bo float ma margines błedu z powodu ogarniczonej liczby bitów, więc należ go porównywąc inaczej na przykład
                       //używając marginesu
     x += 0.1f;
   }
   return x;
}

float meanOfA(float array[], size_t size){
    float sum = 0.0f;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }
    return sum / size;
}

float meanOfV(const vector<float> &elems){
    int sum = 0;
    for (float e : elems){
        sum += e;
    }
    return sum / elems.size(); 
}

float stdOfA(float array[], size_t size){
    float mean = meanOfA(array, size);
    float numerator = 0.0f;
    for (int i = 0; i < size ; i++){
        numerator += (array[i] - mean) * (array[i] - mean);
    }
    return sqrt(numerator / size);
}

float stdOfV(const vector<float> &elems){
    float mean = meanOfV(elems);
    float numerator = 0.0f;
    for (float e : elems){
        numerator += (e - mean) * (e - mean);
    }
    return sqrt(numerator / elems.size());
}

float sumOddsOfA(float array[], size_t size){
    float sum = 0.0f;
    for (int i = 1; i < size; i+=2){
        sum += array[i];
    }
    return sum;
}

float sumOddsOfV(const vector<float> &elems){
    float sum = 0.0f;
    for (int i = 1; i < elems.size(); i+=2){
        sum += elems[i];
    }
    return sum;
}

int main()
{
  using namespace std;

  int a1[] = {0,1,2,3,4};
  vector<int> v1{0,1,2,3,4};
  constexpr size_t a1Size = sizeof(a1) / sizeof (a1[0]);

  vector<int> sums = {
     sum1(a1, a1Size),
     sum2(a1, a1Size),
     sum3(a1, a1Size),
     sum4(v1)
  };

  cout << "sums for a1/v1 = [0,1,2,3,4]: " << endl;
  for (size_t i = 0; i < sums.size(); ++i) {
     cout << "sum" << i + 1 << " = " << sums[i] << endl;
  }

  cout << "sumEven of a1 = [0,1,2,3,4] = " << sumEven(a1, a1Size) << endl;

  for (int i = 0; i < 6; ++i) {
    cout << "indexOfM(" << i << ", [0,1,2,3,4], 5) = "
         << indexOfM(i, a1, a1Size) << endl;
  }

  cout<<fun2()<<endl;

  return 0;
}