#include <iostream>
#include <stack>
#include <mutex>

template <typename T>
class ThreadSafeStack {
private:
    std::stack<T> stack;
    mutable std::mutex mtx;

public:
    void push(const T& value) {
        std::lock_guard<std::mutex> lock(mtx);
        stack.push(value);
    }

    bool pop(T& value) {
        std::lock_guard<std::mutex> lock(mtx);
        if (stack.empty()) {
            return false;
        }
        value = stack.top();
        stack.pop();
        return true;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return stack.empty();
    }
};

int main() {
    ThreadSafeStack<int> tss;

    tss.push(1);
    tss.push(2);

    int value;
    if (tss.pop(value)) {
        std::cout << "Popped value: " << value << std::endl;
    }

    if (!tss.empty()) {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}