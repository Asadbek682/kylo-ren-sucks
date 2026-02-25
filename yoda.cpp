#include <iostream>
#include <memory>

template<typename T>
class SmartPtr {
private:
    T* ptr;
public:
    explicit SmartPtr(T* p = nullptr) : ptr(p) {}
    
    ~SmartPtr() {
        delete ptr;
    }
    
    SmartPtr(SmartPtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    
    SmartPtr& operator=(SmartPtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
};

class Test {
public:
    void show() { std::cout << "Test class\n"; }
};

int main() {
    SmartPtr<Test> sp(new Test());
    sp->show();
    return 0;
}
