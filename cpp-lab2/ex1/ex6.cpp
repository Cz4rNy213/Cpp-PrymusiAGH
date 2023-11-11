#include <iostream>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

int sum5(int elems[], size_t size)
{
  if (size == 0) { return 0; }
  else { return sum5(elems, size - 1) + elems[size - 1]; }
}

long factR(int n)
{
  if (n <= 1) { return 1; }
  else { return n * factR(n - 1); }
}

int fibR(int n)
{
  if (n <= 0) { return 0;}
  else if (n == 1) { return 1; }
  else { return fibR(n - 2) + fibR(n - 1); }
}


int mFibR(int n){
  int nums[n];
  nums[0] = 0;
  nums[1] = 1;
  for (int i = 2; i <= n; i++){
    nums[i] = nums[i-2] + nums[i-1];
  }
  return nums[n];
}

long mFactR(int n){
    long score = 1;
    for (int i = 1; i <= n; i++){
        score *= i;
    }
    return score;
}

int maxElement(const int* p, size_t size, int curr_max = std::numeric_limits<int>::min()){
  curr_max = (*p > curr_max)? *p : curr_max;
  if(size == 1) return curr_max;
  return maxElement(p + 1, size - 1, curr_max);
}


int main()
{
  using std::cout;
  using std::endl;
  using namespace std::chrono;

  int a1[] = {0,1,2,3,4};
  constexpr size_t a1Size = sizeof(a1) / sizeof (a1[0]);

  high_resolution_clock::time_point start4, end4;
  std::vector<int> v = {1,5,9,11,22,433,3425,413};
  size_t v_size = v.size();
  start4 = high_resolution_clock::now();
  int max_element = maxElement(&v[0], v_size);
  end4 = high_resolution_clock::now();

  cout << "maxElement = " <<  max_element << " took "
       << duration_cast<duration<double>>(end4 - start4).count()
       << "seconds.\n";

  // cout << "factR(20) = " << factR(20) << endl;
  // cout << "sum5(10) = " << sum5(a1, a1Size) << endl;

  // high_resolution_clock::time_point start, end;

  // int n4Fib = 45;
  // start = high_resolution_clock::now();
  // fibR(n4Fib);
  // end = high_resolution_clock::now();

  // cout << "fibR =" << fibR(n4Fib) << " took "
  //      << duration_cast<duration<double>>(end - start).count()
  //      << "seconds.\n";

  // high_resolution_clock::time_point start1, end1;
  // start1 = high_resolution_clock::now();
  // mFibR(n4Fib);
  // end1 = high_resolution_clock::now();

  // cout << "mFibR = " << mFibR(n4Fib) << " took "
  //      << duration_cast<duration<double>>(end1 - start1).count()
  //      << "seconds.\n";
  




  // high_resolution_clock::time_point start2, end2;
  // high_resolution_clock::time_point start3, end3;

  // int fact_r = 16;
  // start2 = high_resolution_clock::now();
  // factR(fact_r);
  // end2 = high_resolution_clock::now();
  // start3 = high_resolution_clock::now();
  // mFactR(fact_r);
  // end3 = high_resolution_clock::now();

  // cout << "factR = " << factR(fact_r) << " took "
  //      << duration_cast<duration<double>>(end2 - start2).count()
  //      << "seconds.\n";

  // cout << "mFactR = " << mFactR(fact_r) << " took "
  //      << duration_cast<duration<double>>(end3 - start3).count()
  //      << "seconds.\n";


  

}