// Array.h -- definition Array-class
#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>								// input-output array


// TODO:  write your Array class  here 
// we will use generics idea - template class
template <class T>
class Array 
{
public:
	// Constructors and destructor
	Array();										// constructor by default
	~Array();										// destructor
	Array(const Array& object);						// constructor of copy

	// Array Methods
	void showElements() const;						// out in console


	int getSize() const { return m_size; }			
	int getElemSize() const { return m_current_index; }

	void expandArray(int size);						// expand size of Array
	bool setValue(T val);							// add new element to Array
	void setArray(T* pArr, int size);				// add default array to Array

	// Overloaded operators

	Array operator+(const Array& object) const;		// will return new object Array
	void operator+(T value);						// add some constant to all elements
	void operator-(T value);						// sub some constant to all elements
	bool operator==(const Array& object) const;
	bool operator!=(const Array& object) const;
	void operator++();
	Array operator+=(T value) const;				
	T operator[](int index) const;

	// Friends functions
	friend std::ostream& operator<<(const std::ostream& os, const Array& object);
	friend void operator+(T value, Array& object);
private:
	int m_size;
	int m_current_index;
	int m_step;										
	T* m_pointer;
};

#endif // !ARRAY_H_