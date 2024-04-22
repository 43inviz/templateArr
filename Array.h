#pragma once
#include <iostream>
using namespace std;

template <typename T>

class Array
{
	enum{EMPTY = -1};
	int capacity;
	int size;
	T* arr;
public:

	
	Array(int size,T* arr); // в конструкторе capacity сразу +5 эл от size
	~Array();

	void setSize(int size, int grow = 5);

	int getSize() const;
	int getUpperBound();

	bool isEmpty();
	bool isFull();
	void freeExtra();
	void removeAll();

	T getAt(int index) const;

	void setAt(T val, int index);

	void operator[](int index) ;
	void operator=(const Array& arr);

	void addEl(T val);

	void append(const Array& arr);
	T* getData();

	void insertAt(T val,int index);
	void removeAt(int index);
	void showArr();
};



template<typename T>
inline Array<T>::Array(int size, T* arr)
{
	this->size = size;
	this->capacity = size + 5;
	this->arr = new T[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] arr;
}


template<typename T>
inline void Array<T>::setSize(int size, int grow)
{
	if (size > this->capacity) {
		this->size = size;
		this->capacity += grow;
		T* arr = new T[capacity];
		for (int i = 0; i < this->size; i++) {
			arr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = arr;
	}
	else {
		this->size = size;
		T* arr = new T[size];
		for (int i = 0; i < size; i++) {
			arr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = arr;
	}
}
//template<typename T>
//inline void Array<T>::setSize(int size, int grow )
//{
//	if (size > this->capacity) {
//		this->size = size;
//		this->capacity += grow;
//		T* arr = new T[capacity];
//		for (int i = 0; i < this->size; i++) {
//			arr[i] = this->arr[i];
//		}
//
//		delete[] this->arr;
//		this->arr = arr;
//
//	}
//	else {
//		this->size = size;
//		T* arr = new T[size];
//		for (int i = 0; i < size; i++) {
//			arr[i] = this->arr[i];
//		}
//		delete[] this->arr;
//		this->arr = arr;
//		
//	}
//	
//}

template<typename T>
inline int Array<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline int Array<T>::getUpperBound()
{
	return this->size;
}

template<typename T>
inline bool Array<T>::isEmpty()
{
	if (this->arr == nullptr) {
		return true;
	}
	return false;
}

template<typename T>
inline bool Array<T>::isFull()
{
	if (this->size == this->capacity) {
		return true;
	}
	return false;
}

template<typename T>
inline void Array<T>::freeExtra()
{
	this->capacity = this->size;
}

template<typename T>
inline void Array<T>::removeAll()
{
	this->capacity = 0;
	delete[] this->arr;
	this->arr = nullptr;
	this->size = 0;
}

template<typename T>
inline T Array<T>::getAt(int index) const
{
	return this->arr[index];
}

template<typename T>
inline void Array<T>::setAt(T val, int index)
{
	if (index>=0&& index <= this->size)
	{
		this->arr[index] = val;
	}
	else {
		setSize(index);
		this->arr[index] = val;
	}
}

template<typename T>
inline void Array<T>::operator[](int index) 
{
	if (index >= 0 && index <= this->size) {
		return this->arr[index];
	}
}

template<typename T>
inline void Array<T>::operator=(const Array& arr)
{
	if (this != &arr) {

		this->capacity = arr.capacity;
		this->size = arr.size;

		delete[] this->arr;
		this->arr = new T[arr.size];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = arr.arr[i];

		}
	}
	
	
}

template<typename T>
inline void Array<T>::addEl(T val)
{
	if (this->size == capacity) {
		setSize(this->size+1);
		
	}
	this->arr[this->size] = val;
	this->size++;
}

template<typename T>
inline void Array<T>::append(const Array& arr)
{
	int size = this->size + arr.size;
	if (size > this->capacity) {
		setSize(size); 
	}
	int index = this->size;


	for (int i = 0; i < arr.size; i++) {
		this->arr[index] = arr.arr[i];
		index++;
	}

	this->size = size;
}

template<typename T>
inline T* Array<T>::getData()
{
	return this->arr;
}

template<typename T>
inline void Array<T>::insertAt(T val, int index)
{
	this->size++;
	T* arr = new T[size];
	
	for (int i = 0; i < index; i++) {
		arr[i] = this -> arr[i];
	}

	arr[index-1] = val;

	for (int i = index; i < this->size; i++) {
		arr[i] = this->arr[i - 1];
	}
	
	delete[] this->arr;

	this->arr = arr;
	

}

template<typename T>
inline void Array<T>::removeAt(int index)
{
	--this->size;
	T* arr = new T[size];

	for (int i = 0; i < index; i++) {
		arr[i] = this->arr[i];
	}

	for (int i = index; i < this->size; i++) {
		arr[i] = this->arr[i + 1];

	}

	delete[] this->arr;
	this->arr = arr;
	this->size = size;
}

template<typename T>
inline void Array<T>::showArr()
{
	for (int i = 0; i < this->size; i++) {
		cout << this->arr[i] << " ";
	}
	cout << endl;
}


