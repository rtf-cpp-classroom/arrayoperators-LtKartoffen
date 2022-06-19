// Array.cpp -- realization of Array's methods
#include "Array.h"

//---------------------------------------------------------------------------------------------//
//---------------------Consturctors, destructor and assignment operator-----------------------//
//-------------------------------------------------------------------------------------------//
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
// Destructor - free heap memory
template<class Item>
Array<Item>::~Array()
{
	if (m_pointer == nullptr)
	else
		delete[] m_pointer;
}
//--------------------------------------------------------------------------------------------//
//----------------------------Set some member value------------------------------------------//
//------------------------------------------------------------------------------------------//
// Expand size of Array
template <class Item>
bool Array<Item>::expandArray(int size)
{
	if (size < 0)
		return false;
	m_step = size;
	m_size += m_step;
	if (m_pointer == nullptr)
		m_pointer = new Item[m_size];
	else
	{
		Item* temp = new Item[m_size - m_step];
		// copy to temporary array values
		for (int i = 0; i <= m_current_index; i++)
			temp[i] = m_pointer[i];
		delete[] m_pointer;
		// create new array and fill the same values
		m_pointer = new Item[m_size];
		for (int i = 0; i <= m_current_index; i++)
			m_pointer[i] = temp[i];
		delete[] temp;				// free memory after using temporary-variable
	}
	return true;
}
// Add new element to Array
template<class Item>
bool Array<Item>::setValue(Item value)
{
	m_size++;
	if (m_pointer == nullptr)
	{
		m_pointer = new Item[m_size];
		m_pointer[m_current_index] = value;
		return true;
	}
	m_step = 1;
	m_current_index++;
	Item* temp = new Item[m_size - m_step];
	// copy to temporary array values
	for (int i = 0; i <= m_current_index; i++)
		temp[i] = m_pointer[i];
	delete[] m_pointer;
	// create new array and fill the same values
	m_pointer = new Item[m_size];
	for (int i = 0; i <= m_current_index; i++)
		m_pointer[i] = temp[i];
	delete[] temp;				// free memory after using temporary-variable
	return true;
}
// add default array to Array 
template <class Item>
bool Array<Item>::setArray(Item* pArr, int size)
{
	m_step = size;
	if (m_pointer == nullptr)
	{
		m_size += m_step;
		m_current_index = size - 1;
		m_pointer = new Item[m_size];
		for (int i = 0; i < getElemSize(); i++)
			m_pointer[i] = pArr[i];
	}
	else
	{
		// first, copy our values to temporary array
		Item* temp = new Item[getElemSize() + m_step];
		for (int i = 0; i < getElemSize(); i++)
			temp[i] = m_pointer[i];
		for (int i = getElemSize(), int j = 0; i < getElemSize() + m_step, j < size; i++, j++)
			temp[i] = pArr[j];
		// rewrite new values and delete old memory
		m_size = getElemSize() + m_step;
		m_current_index = getSize() - 1;
		delete[] m_pointer;
		// create new array
		m_pointer = new Item[m_size];
		for (int i = 0; i < getElemSize(); i++)
			m_pointer[i] = temp[i];
		delete[] temp;				// free temp memory
	}
	return true;
}
//----------------------------------------------------------------------------------------------//
//------------------------------- Overloaded operators-----------------------------------------//
//--------------------------------------------------------------------------------------------//
// Get value from Array by index
template<class Item>
Item Array<Item>::operator[](int index) const
{
	if (index <= m_current_index and index >= 0)
		return m_pointer[i];
	return m_pointer[0];
}
//--------------------------------------------------------------------------------------------//
//----------------------------Comparative Operators------------------------------------------//
//------------------------------------------------------------------------------------------//
template<class Item>
bool Array<Item>::operator==(const Array<Item>& object) const
{
	bool flag = (getElemSize() == object.getElemSize());
	if (flag)
	{
		for (int i = 0; i < getElemSize(); i++)
		{
			flag = (m_pointer[i] == object.m_pointer[i]);
			if (!flag)
				return !flag;
		}
	}
	return flag;
}
template <class Item>
bool Array<Item>::operator!=(const Array<Item>& object) const
{
	return !(this->operator==(object));
}
//--------------------------------------------------------------------------------------------//
//----------------------------Output functions-----------------------------------------------//
//------------------------------------------------------------------------------------------//
template <class Item>
void Array<Item>::showElements() const
{
	for (int i = 0; i < getElemSize(); i++)
		std::cout << m_pointer[i] << " ";
}
// Overloadaed operator << for more convinient output
template <class Item>
std::ostream& operator<<(const std::ostream& os, const Array<Item>& object)
{
	object.showElements();
	return os;
}

