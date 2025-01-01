#include <iosteam>
#include <vector>

using namespace std;


class Stack {

public:
    vector <int> stack_;

    Stack() {};

    void push(int n) {
        stack_.push_back(n);
    }

    int pop() {
        int top = stack_[stack_.size()-1];
        stack_.pop_back();
        return top;
    }
};
