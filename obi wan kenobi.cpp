#include <iostream>
#include <vector>

template<typename T>
class VectorIterator {
private:
    typename std::vector<T>::iterator it;
    
public:
    VectorIterator(typename std::vector<T>::iterator iter) : it(iter) {}
    
    T& operator*() { return *it; }
    
    VectorIterator& operator++() {
        ++it;
        return *this;
    }
    
    bool operator!=(const VectorIterator& other) const {
        return it != other.it;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    for (VectorIterator<int> it(vec.begin()); it != VectorIterator<int>(vec.end()); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
