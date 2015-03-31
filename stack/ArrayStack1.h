
#ifndef ZHLIB_ARRAYSTACK_H_
#define ZHLIB_ARRAYSTACK_H_

#include <iostream>
#include <iterator>
#include <algorithm>

namespace zhlib {

template<class T>
	class ArrayStack {

	private:
		/**
		* Default array size
		*/
		const static int DEFAULT_SIZE = 5;

		/**
		* Index pointing to the top of the stack
		*/
		int topIndex_;

		/*
		* Current allocated array size
		*/
		int currArraySize_;

		/**
		* Data array pointer
		*/
		T * ary_;
		
	public:

		/**
		* Default constructor to allocate array
		*/
		ArrayStack(): topIndex_(0), currArraySize_(ArrayStack::DEFAULT_SIZE) {
		 	ary_ = new T[ArrayStack::DEFAULT_SIZE];
		}

		/**
		* Explicit delete copy constructor and assignmenet copy operator to avoid memory leak
		*/
		ArrayStack(const ArrayStack &) = delete;
		ArrayStack & operator=(const ArrayStack &) = delete;

		inline ~ArrayStack() {delete[] ary_;}
		void push(const T &);
		inline void pop() {--topIndex_;}
		inline int size() const {return topIndex_;}
		void print() const;
		inline T top() const {return ary_[topIndex_-1];}
		inline bool empty() const{ return topIndex_ == 0;}

	};

}

template<class T>
void zhlib::ArrayStack<T>::push(const T & a) {

	//Double the array when it's full
	if(topIndex_ >= currArraySize_) {
		// Create new temp array
		T * newArray = new T[currArraySize_ * 2];
		std::copy(ary_, ary_ + currArraySize_, newArray);
		currArraySize_ *= 2;
		delete [] ary_;
		ary_ = newArray;
		//std::cout<<"Array Full! new size:" << currArraySize_ << std::endl;
	}

	ary_[topIndex_++] = a;
}

template<class T>
void zhlib::ArrayStack<T>::print() const{
	for (int i = 0; i < topIndex_; i++) {
		std::cout << ary_[i] << " ";
	}

	std::cout << std::endl;
}


#endif	//ZHLIB_ARRAYSTACK_H_
