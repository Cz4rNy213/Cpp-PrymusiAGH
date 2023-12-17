#include "Stack.h"

template <typename T>
class StackVectorBasedImpl : public Stack<T>
{
public:
  StackVectorBasedImpl() : data_{} {}
  T pop() { T last = data_.back(); data_.pop_back(); return last; }
  void push(T e) { data_.emplace_back(e); }
  bool isEmpty() const { return data_.empty(); }
  int size() const { return static_cast<int>(data_.size()); }
  T peek() const { return data_.back(); }
  virtual ~StackVectorBasedImpl();

private:
  vector<T> data_;
};

template <typename T>
StackVectorBasedImpl<T>::~StackVectorBasedImpl() {}
