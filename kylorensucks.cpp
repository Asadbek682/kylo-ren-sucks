// ============================================================
// 10 Intermediate C++ Code Examples
// ============================================================

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <functional>
#include <memory>
#include <stdexcept>
using namespace std;


// ============================================================
// 1. BINARY SEARCH
// ============================================================
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void demo_binarySearch() {
    cout << "=== 1. Binary Search ===" << endl;
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int idx = binarySearch(arr, 7);
    cout << "Found 7 at index: " << idx << endl; // 3
    cout << "Found 4 at index: " << binarySearch(arr, 4) << endl; // -1
    cout << endl;
}


// ============================================================
// 2. LINKED LIST
// ============================================================
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head = nullptr;
public:
    void push_front(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    void print() {
        Node* cur = head;
        while (cur) { cout << cur->data << " -> "; cur = cur->next; }
        cout << "NULL" << endl;
    }
    void reverse() {
        Node *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    ~LinkedList() {
        Node* cur = head;
        while (cur) { Node* tmp = cur->next; delete cur; cur = tmp; }
    }
};

void demo_linkedList() {
    cout << "=== 2. Linked List ===" << endl;
    LinkedList list;
    for (int i = 1; i <= 5; i++) list.push_front(i);
    cout << "Original: "; list.print();
    list.reverse();
    cout << "Reversed: "; list.print();
    cout << endl;
}


// ============================================================
// 3. STACK-BASED BALANCED PARENTHESES CHECKER
// ============================================================
bool isBalanced(const string& s) {
    stack<char> st;
    map<char,char> match = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else if (match.count(c)) {
            if (st.empty() || st.top() != match[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}

void demo_balancedParens() {
    cout << "=== 3. Balanced Parentheses ===" << endl;
    cout << "({[]})  -> " << (isBalanced("({[]})") ? "Balanced" : "Not balanced") << endl;
    cout << "({[)})  -> " << (isBalanced("({[)})") ? "Balanced" : "Not balanced") << endl;
    cout << endl;
}


// ============================================================
// 4. MERGE SORT
// ============================================================
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin()+l, arr.begin()+m+1);
    vector<int> right(arr.begin()+m+1, arr.begin()+r+1);
    int i=0, j=0, k=l;
    while (i<(int)left.size() && j<(int)right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i<(int)left.size()) arr[k++] = left[i++];
    while (j<(int)right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

void demo_mergeSort() {
    cout << "=== 4. Merge Sort ===" << endl;
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, arr.size()-1);
    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";
}


// ============================================================
// 5. FIBONACCI WITH MEMOIZATION
// ============================================================
map<int,long long> memo;
long long fib(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}

void demo_fibonacci() {
    cout << "=== 5. Fibonacci with Memoization ===" << endl;
    for (int i = 0; i <= 10; i++) cout << "fib(" << i << ") = " << fib(i) << endl;
    cout << endl;
}


// ============================================================
// 6. TEMPLATE STACK
// ============================================================
template<typename T>
class Stack {
    vector<T> data;
public:
    void push(T val) { data.push_back(val); }
    void pop() { if (!data.empty()) data.pop_back(); }
    T top() const { return data.back(); }
    bool empty() const { return data.empty(); }
    int size() const { return data.size(); }
};

void demo_templateStack() {
    cout << "=== 6. Template Stack ===" << endl;
    Stack<string> s;
    s.push("Hello");
    s.push("World");
    s.push("C++");
    while (!s.empty()) { cout << s.top() << " "; s.pop(); }
    cout << "\n\n";
}


// ============================================================
// 7. GRAPH BFS (Adjacency List)
// ============================================================
void bfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout << "BFS from " << start << ": ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "\n\n";
}

void demo_bfs() {
    cout << "=== 7. Graph BFS ===" << endl;
    int n = 6;
    vector<vector<int>> adj(n);
    auto addEdge = [&](int u, int v){ adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0,1); addEdge(0,2); addEdge(1,3); addEdge(2,4); addEdge(3,5);
    bfs(0, adj);
}


// ============================================================
// 8. LAMBDA + STL ALGORITHMS
// ============================================================
void demo_lambdaSTL() {
    cout << "=== 8. Lambda + STL Algorithms ===" << endl;
    vector<int> nums = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // Sort descending
    sort(nums.begin(), nums.end(), [](int a, int b){ return a > b; });
    cout << "Sorted desc: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // Filter evens
    vector<int> evens;
    copy_if(nums.begin(), nums.end(), back_inserter(evens), [](int x){ return x % 2 == 0; });
    cout << "Even numbers: ";
    for (int x : evens) cout << x << " ";
    cout << "\n\n";
}


// ============================================================
// 9. SMART POINTERS (unique_ptr + shared_ptr)
// ============================================================
class Animal {
public:
    string name;
    Animal(string n) : name(n) { cout << name << " created\n"; }
    ~Animal() { cout << name << " destroyed\n"; }
    void speak() { cout << name << " says hello!\n"; }
};

void demo_smartPointers() {
    cout << "=== 9. Smart Pointers ===" << endl;
    {
        unique_ptr<Animal> dog = make_unique<Animal>("Dog");
        dog->speak();
    } // auto-destroyed here

    shared_ptr<Animal> cat1 = make_shared<Animal>("Cat");
    {
        shared_ptr<Animal> cat2 = cat1; // shared ownership
        cout << "Ref count: " << cat1.use_count() << endl;
    }
    cout << "Ref count after inner scope: " << cat1.use_count() << endl;
    cout << endl;
}


// ============================================================
// 10. CUSTOM EXCEPTION HANDLING
// ============================================================
class DivisionByZeroException : public runtime_error {
public:
    DivisionByZeroException() : runtime_error("Division by zero!") {}
};

double safeDivide(double a, double b) {
    if (b == 0) throw DivisionByZeroException();
    return a / b;
}

void demo_exceptions() {
    cout << "=== 10. Custom Exception Handling ===" << endl;
    try {
        cout << "10 / 2 = " << safeDivide(10, 2) << endl;
        cout << "5 / 0 = " << safeDivide(5, 0) << endl;
    } catch (const DivisionByZeroException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << endl;
}


// ============================================================
// MAIN
// ============================================================
int main() {
    demo_binarySearch();
    demo_linkedList();
    demo_balancedParens();
    demo_mergeSort();
    demo_fibonacci();
    demo_templateStack();
    demo_bfs();
    demo_lambdaSTL();
    demo_smartPointers();
    demo_exceptions();
    return 0;
}
