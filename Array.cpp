// Array.cpp -- realization of Array's methods
#include "Array.h"

//--------------------------------------------------------------------------------------------//
//---------------------Consturctors, destructor and assignment operator-----------------------//
//--------------------------------------------------------------------------------------------//
// Default constructor - initialization an object
template <class Item>
Array<Item>::Array()
{
	m_size = m_step = m_current_index = 0;
	m_pointer = nullptr;
}
// Constructor of copy - using deep copy for dynamic memory allocation
template<class Item>
Array<Item>::Array(const Array& object)
{
	m_size = object.getSize();
	m_current_index = object.getElemSize() - 1;
	if (m_current_index == 0)						// if Array empty
		m_pointer = nullptr;
	else
		for (int i = 0; i < object.getElemSize(); i++)
			m_pointer[i] = object.m_pointer[i];
}
// Assignment operator
template <class Item>
Array<Item>& Array<Item>::operator=(const Array<Item>& object)
{
	if (this == &object)							// if self-assignment
		return *this;
	m_size = object.getSize();
	m_current_index = object.getElemSize - 1;
	if (m_current_index == 0)						// if Array empty
		m_pointer = nullptr;
	else
		for (int i = 0; i < object.getElemSize(); i++)
			m_pointer[i] = object.m_pointer[i];
	return *this;
}
// Destructor - free memory
template<class Item>
Array<Item>::~Array()
{
	if (m_pointer == nullptr)
	else
		delete[] m_pointer;
}
//--------------------------------------------------------------------------------------------//
//------------------------------- Other methods-----------------------------------------------//
//--------------------------------------------------------------------------------------------//
// Expand size of Array
template <class Item>
bool Array<Item>::expandArray(int size)
{
	if (size < 0)
		return false;
	m_step = size;
	m_size += m_step;
	if (m_pointer == nullptr)
		m_pointer = new[m_size];
	else
	{
		Item* temp = new[m_size - m_step];
		// copy to temporary array values
		for (int i = 0; i <= m_current_index; i++)
			m_pointer[i] = temp[i];
		delete[] temp;
	}
	return true;
}
// 

//--------------------------------------------------------------------------------------------//
//------------------------------- Overloaded operators----------------------------------------//
//--------------------------------------------------------------------------------------------//
// Get value from Array by index
template<class Item>
Item Array<Item>::operator[](int index) const
{
	if (index <= m_current_index and index >= 0)
		return m_pointer[i];
	return m_pointer[0];
}