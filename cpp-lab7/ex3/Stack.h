template <typename T>
class Stack
{
public:
  virtual T pop() = 0;
  virtual void push(T e) = 0;
  virtual bool isEmpty() const = 0;
  virtual int size() const = 0;
  virtual T peek() const = 0;
  virtual ~Stack();
};
template <typename T>
Stack<T>::~Stack() {}