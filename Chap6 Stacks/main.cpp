/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2023
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 *          Gavin Robertson <gavinr900@gmail.com>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 1.0.0
 * @date    09/02/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */




#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;
#include <iostream>

class StackCapacityException : public std::logic_error {
public:
    explicit StackCapacityException(const std::string &message = "") : std::logic_error(message){}

};

/**
    * The Stack ADT interface.
    * @tparam T the type of item found in this Stack
    */
template<typename T>
class Stack
{
public:
    /**
     * Assess whether this Stack contains any items.
     * @return true if there are no items contained in this Stack, false otherwise
     */
    [[nodiscard]] virtual bool isEmpty() const = 0;

    /**
     * Add a new item onto the top of this Stack.
     * @param object the new item to place on the top of this Stack
     * @return true if this Stack had the capacity to add this new item, false otherwise
     * @post If this Stack had the capacity for the object, that object is found at the top of this Stack.
     */
    virtual bool push(const T& object) = 0;

    /**
     * Remove the item located at the top of this Stack.
     * @return true if there was an item to remove, false otherwise.
     * @post The item that was on the top of the stack has been removed.
     */
    virtual bool pop() = 0;

    /**
     * Obtain a copy of the top of this Stack.
     * @return a copy of the top o this Stack is returned, assuming this Stack was not empty.
     * @pre This Stack is not empty.
     * @throws StackCapacityException if this Stack is empty when this method is invoked.
     */
    virtual T peek() const noexcept(false) = 0;

    /**
     * Virtual destructor with default implementation.
     */
    virtual ~Stack() = default;
};

template<typename ItemType>
class ArrayStack : public Stack<ItemType>{
protected:
    static int const DEFAULT_CAPACITY = 5;
    ItemType items[DEFAULT_CAPACITY];
    int top;


public:
    ArrayStack();

    [[nodiscard]] bool isEmpty() const override;
    bool push(const ItemType& object) override;
    bool pop() override;
    ItemType peek() const noexcept(false) override;





};

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1){}

template<typename ItemType>
[[nodiscard]] bool ArrayStack<ItemType>::isEmpty() const {
    return (top < 0);
}

template<typename ItemType>
bool ArrayStack<ItemType>::push(const ItemType &object){
    bool result = false;
    if(top < DEFAULT_CAPACITY - 1){
        top++;
        items[top] = object;
        result = true;
    }
    return result;
}

template<typename ItemType>
bool ArrayStack<ItemType>::pop(){
    bool result = false;

    if(!isEmpty()){
        top--;
        result = true;
    }

    return result;
}

template<typename ItemType>
ItemType ArrayStack<ItemType>::peek() const{
    if(!isEmpty()){
        return items[top];
    }
    throw StackCapacityException("stack is empty");
}



// Code below ----------------------------------------------------------------------
/**
 * check if palindrome
 *
 * @param word string to check if palindrome
 * @returns true or false if palindrome
 */
bool isPalindrome(std::string word){
    ArrayStack<char> stack;
    if((word.length() % 2)){
        word.erase(std::ceil((word.length())/2), 1);

    }

    for(int i = 0; i < word.length()/2; i++){
        stack.push(word[i]);


    }

    for(int i = word.length()/2; i <= word.length(); i++){

        if(stack.isEmpty()){
            return true;
        }

        else if(stack.peek() == word[i]){

            stack.pop();

        }
        else{return false;}
    }
}

int main() {
    std::cout << isPalindrome("anna") << endl;
    std::cout << isPalindrome("tacocat") << endl;
    std::cout << isPalindrome("god") << endl;
    std::cout << isPalindrome("goddog") << endl;
    std::cout << isPalindrome("orange");


}
