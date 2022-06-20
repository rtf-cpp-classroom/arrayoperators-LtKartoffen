// Array.h -- definition Array-class
#pragma once
//#ifndef ARRAY_H_
//#define ARRAY_H_
#include <iostream>								// input-output array

typedef int Item;									// we will work with abstract type for Array - Item
// Realization of dynamic array
class Array 
{
public:
	// Constructors and destructor
	Array();										// constructor by default
	~Array();										// destructor
	Array(const Array& object);						// constructor of copy

	// Array Methods
	void showElements() const;							// out in console

	// Get some member value
	int getSize() const { return m_size; }			
	int getElemSize() const { return m_current_index +1; }

	// Set some member value
	void setValue(Item val);							// add new element to Array
	void setArray(Item* pArr, int size);				// add default array to Array

	// Overloaded operators
	Array& operator=(const Array& object);			// very important assignment operator

	Array operator+(const Array& object) const;		// will return new object Array
	Array operator+(Item value) const;				// add some constant to all elements
	Array operator-(Item value) const;				// sub some constant to all elements

	bool operator==(const Array& object) const;		// return true if Arrays'll be equivalent
	bool operator!=(const Array& object) const;		// return false if Arrays'll be equivalent

	Array operator++(int);							// post-increment operation to all elements
	Array operator+=(Item value);
	Item operator[](int index) const;				// indexation

	// Friends functions
	friend std::ostream& operator<<(std::ostream& os, const Array& object);		// out in console
	friend Array operator+(Item value, const Array& object);
	//friend Array operator-(Item value, const Array& object);
private:
	int m_size;										// maximum size of array(variable)
	int m_current_index;							// current index to last e-ment of Array
	int m_step;										// how much increase size of Array 
	Item* m_pointer;								// pointer to type
	// Locked method for expanding size of array
	// needed for setValue 
	bool expandArray(int size);							// expand size of Array
};

//#endif // !ARRAY_H_