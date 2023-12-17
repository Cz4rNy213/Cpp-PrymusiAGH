// #include "Stack.h"

template <typename T, typename ExpansionStrategy>
class ArrayStack : public Stack<T>
{
public:
  ArrayStack(size_t init_capacity, const ExpansionStrategy& strategy) : capacity_(init_capacity), expansionStrategy_(strategy) {
    array_.resize(init_capacity);
  }
  T pop(){
    T last = array_.back(); array_.pop_back(); return last;
  }
  void push(T e){
    if (size_ == capacity_){
        expansionStrategy_.expand(array_, capacity_);
        array_.emplace_back(e);
    }
    else{
        array_.emplace_back(e);
    }
  }
  bool isEmpty() const{
    return size_ == 0;
  }
  int size() const{
    return (int)size_;
  }
  T peek() const{
    return array_[size_ - 1];
  }
  virtual ~ArrayStack();

private:
  size_t size_ = 0;
  size_t capacity_;
  std::vector<T> array_;
  ExpansionStrategy expansionStrategy_;
};

template <typename T, typename ExpansionStrategy>
ArrayStack<T, ExpansionStrategy>::~ArrayStack() {}




