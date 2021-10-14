/*
Problem:
https://leetcode.com/problems/implement-queue-using-stacks/

Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
*/
#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
private:
    vector<int> stack;
    int top;
    
public:
    MyQueue() {
        this->top = -1;
    }
    
    void push(int x) {
        this->top += 1;
        this->stack.push_back(x);
    }
    
    int pop() {
        vector<int> tmp;
        int tmpTop = this->top;
        
        while(tmpTop >= 0) {
            tmp.push_back( this->stack[tmpTop] );
            this->stack.pop_back();
            tmpTop--;
        }
        
        int val = tmp[this->top];
        tmpTop = this->top-1;
        tmp.pop_back();
        this->top -= 1;
        
        while(tmpTop >= 0) {
            this->stack.push_back( tmp[tmpTop] );
            tmp.pop_back();
            tmpTop--;
        }
        
        return val;
    }
    
    int peek() {
        vector<int> tmp;
        int tmpTop = this->top;
        
        while(tmpTop >= 0) {
            tmp.push_back( this->stack[tmpTop] );
            this->stack.pop_back();
            tmpTop--;
        }
        
        int val = tmp[this->top];
        tmpTop = this->top;
          
        while(tmpTop >= 0) {
            this->stack.push_back( tmp[tmpTop] );
            tmp.pop_back();
            tmpTop--;
        }
        
        return val;
    }
    
    bool empty() {
        if(this->top < 0) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

