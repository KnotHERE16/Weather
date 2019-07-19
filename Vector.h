/**
*********************************************************
*
* @file		Vector.h
* @brief	A custom vector template class
* @version	1
* @date		11/03/2018
* @author	Aung Kyaw Myint
*
*****************************************************************
*/


#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <string>

using namespace std;

template <class Type>
class Vector
{
public:
	Vector();	///Constructor
	~Vector();	///Destructor

	/**
	*@brief		add new data to the vector		
	*@return	void
	*/
	void push_back(const Type& i);

	/**
	*@brief		return the value at the Index
	*@return	list[i]
	*/
	Type& at(int i);

	/**
	*@brief		change the capacity of the vector
	*@return	void
	*/
	void resize(int newSize);

	/**
	*@brief		return the length of the vector
	*@return	length
	*/
	int size();

	/**
	*@brief		Printout the vector
	*@return	void
	*/
	void print() const;

private:
	int capacity;	/// capacity variable
	Type *list;		/// list pointer
	int length;		/// length variable
};

//implementation
template <class Type>
Vector<Type>::Vector()
{
	length = 0;
	capacity = 200;
	list = new Type[capacity];
}

template <class Type>
Vector<Type>::~Vector()
{
	delete[] list;
}

template <class Type>
void Vector<Type>::resize(int newSize)
{

	Type *newList = new Type[capacity];
	Type *newListP = newList;
	Type *oldListP = list;

	while (oldListP != (list + length))
	{
		*(newListP) = *(oldListP);
		newListP++;
		oldListP++;
	}

	capacity = newSize;
	delete[] list;
	list = newList;
}

template <class Type>
void Vector<Type>::push_back(const Type& i)
{
	if ((capacity / 2) == length)
	{
		Vector::resize(capacity*1.5);
	}
	list[length] = i;
	length++;
}

template <class Type>
Type& Vector<Type>::at(int i)
{
	if ((i >= 0) && (i < length))
	{
		return list[i];
	}
	return list[0];
}

template <class Type>
int Vector<Type>::size()
{
	return length;
}

template <class Type>
void Vector<Type>::print() const
{
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
		cout << endl;
	}
}

#endif //VECTOR_H