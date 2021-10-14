/*
Problem:
https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
    * Open brackets must be closed by the same type of brackets.
    * Open brackets must be closed in the correct order.


Examples:
Input -
"{[]({})}"

Output-
true

Input -
"{[]({}})"

Output -
false

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Use stack
        vector<string> stack;
        int top = -1;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            string ch = s.substr(i,1);
            
            if(ch == "(") {
                top++;
                stack.push_back("(");
                
            }
            else if(ch == "[") {
                top++;
                stack.push_back("[");
            }
            else if(ch == "{") {
                top++;
                stack.push_back("{");
            }
            else if(ch == ")") {
                if(top >= 0 && stack[top] == "(") {
                    stack.pop_back();
                    top--;
                }
                else {
                    return false;
                }
            }
            else if(ch == "]") {
                if(top >= 0 && stack[top] == "[") {
                    stack.pop_back();
                    top--;
                }
                else {
                    return false;
                }
            }
            else if(ch == "}") {
                if(top >= 0 && stack[top] == "{") {
                    stack.pop_back();
                    top--;
                }
                else {
                    return false;
                }
            }
        }
        if(top != -1) {
            return false;
        }
        return true;
    }
};