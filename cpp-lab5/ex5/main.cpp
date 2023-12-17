#include <iostream>
#include <vector>


class StackOfInts
{
public:
  virtual int pop() = 0;
  virtual void push(int x) = 0;
  virtual bool isEmpty()const = 0;
  virtual int size() = 0;
  virtual int peek() const = 0;
  virtual ~StackOfInts() {}
};

class QueueOfInts
{
public:
  virtual void enqueue(int x) = 0;
  virtual int dequeue() = 0;
  virtual bool isEmpty()const = 0;
  virtual int peek() const = 0;
  virtual ~QueueOfInts() {}
};

class VectorStack : public StackOfInts{
private:
    std::vector<int> stack;
public:
    int pop()override{
        if(!isEmpty()){
            int popped = stack.back();
            stack.pop_back();
            return popped;
        }
        else{
            throw std::runtime_error("Stack is empty!");
        }
    }
    void push(int x)override{
        stack.push_back(x);
    }
    bool isEmpty()const override{
        return stack.empty();
    }
    int size()override{
        return static_cast<int>(stack.size());
    }
    int peek()const override{
        if(!isEmpty()){
            int peek = stack.back();
            return peek;
        }
        else{
            throw std::runtime_error("Stack is empty!");
        }
    }
    ~VectorStack() {std::cout<<"VectorStack destroyed"<<std::endl;}
};

class VectorQueue : public QueueOfInts{
private:
    std::vector<int> que;
public:
    void enqueue(int x)override{
        que.push_back(x);
    }
    int dequeue(){
        if(!isEmpty()){
            int dequeued = que.front();
            que.erase(que.begin());
            return dequeued;
        }
        else{
            throw std::runtime_error("Queue is empty!");
        }
    }
    bool isEmpty()const override{
        return que.empty();
    }
    int peek() const override{
        if(!isEmpty()){
            int dequeued = que.front();
            return dequeued;
        }
        else{
            throw std::runtime_error("Queue is empty!");
        }
    }
    ~VectorQueue() {std::cout<<"VectorQueue destroyed"<<std::endl;}
};


int main(){
    // Testing VectorStack
    VectorStack vectorStack;
    vectorStack.push(4);
    vectorStack.push(5);
    vectorStack.push(6);

    std::cout << "VectorStack size: " << vectorStack.size() << std::endl;
    std::cout << "VectorStack top: " << vectorStack.peek() << std::endl;

    while (!vectorStack.isEmpty()) {
        std::cout << "VectorStack pop: " << vectorStack.pop() << std::endl;
    }
    // Testing VectorQueue
    VectorQueue vectorQueue;
    vectorQueue.enqueue(10);
    vectorQueue.enqueue(11);
    vectorQueue.enqueue(12);

    std::cout << "VectorQueue front: " << vectorQueue.peek() << std::endl;

    while (!vectorQueue.isEmpty()) {
        std::cout << "VectorQueue dequeue: " << vectorQueue.dequeue() << std::endl;
    }
    
    return 0;
}