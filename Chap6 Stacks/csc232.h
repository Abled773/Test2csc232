/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2023
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 1.0.0
 * @date    09/02/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */

#ifndef MSU_CSC232_H_
#define MSU_CSC232_H_

#define FALSE 0
#define TRUE 1

#define TEST_TASK1 TRUE
#define TEST_TASK2 TRUE
#define TEST_TASK3 TRUE

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

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
#if TEST_TASK1    
    // TODO: Task 1 - Define custom exception class
    /**
     * The exception class for the stack
     * inherits from logic error class in standard library
     */
    class StackCapacityException : public std::logic_error {
    public:
        explicit StackCapacityException(const std::string &message = "") : std::logic_error(message){}

    };

#endif

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

#if TEST_TASK2
    // TODO: Task 2a - Declare the ArrayStack ADT
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


    // TODO: Task 2b - Define the ArrayStack ADT
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






#endif

;
#if TEST_TASK3
    // TODO: Task 3a - Declare a ViewableArrayStack
    template<typename ItemType>
    class ViewableArrayStack : public ArrayStack<ItemType>{
        public:

        /**
         * @brief displays content of stack
         */
            void display() const;
        };

    // TODO:Task 3b - Define a ViewableArrayStack

    template<typename ItemType>

    void ViewableArrayStack<ItemType>::display() const{

        if(ArrayStack<ItemType>::isEmpty() == 0) {

            for (int i = ArrayStack<ItemType>::top ; i > 0; i--) {


                std::cout <<  ArrayStack<ItemType>::items[i] << " ";


            }
            std::cout << ArrayStack<ItemType>::items[0] << "\n";
        }
        else{
            std::cout << "Stack is empty!\n";
        }
    }
#endif

    // DO NOT Modify anything below this line

} // namespace csc232

#endif // MSU_CSC232_H_




















