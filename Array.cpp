// Array.cpp -- realization of Array's methods
#include "Array.h"

//---------------------------------------------------------------------------------------------//
//---------------------Consturctors, destructor and assignment operator-----------------------//
//-------------------------------------------------------------------------------------------//
// Default constructor - initialization an object
Array::Array()
{
	m_size = m_step = m_current_index = 0;
	m_pointer = nullptr;
}
// Constructor of copy - using deep copy for dynamic memory allocation
Array::Array(const Array& object)
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
Array& Array::operator=(const Array& object)
{
	if (this == &object)							// if self-assignment
		return *this;
	m_size = object.getSize();
	m_current_index = object.getElemSize() - 1;
	if (m_current_index == 0)						// if Array empty
		m_pointer = nullptr;
	else
		for (int i = 0; i < object.getElemSize(); i++)
			m_pointer[i] = object.m_pointer[i];
	return *this;
}
// Destructor - free heap memory
Array::~Array()
{
	if (m_pointer == nullptr);
	else
		delete[] m_pointer;
}
//--------------------------------------------------------------------------------------------//
//----------------------------Set some member value------------------------------------------//
//------------------------------------------------------------------------------------------//
// Expand size of Array
bool Array::expandArray(int size)
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
bool Array::setValue(Item value)
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
	for (int i = 0; i < getElemSize(); i++)
		m_pointer[i] = temp[i];
	delete[] temp;				// free memory after using temporary-variable
	return true;
}
// add default array to Array 
bool Array::setArray(Item* pArr, int size)
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
		for (int i = getElemSize(), j = 0; i < getElemSize() + m_step, j < size; i++, j++)
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
Item Array::operator[](int index) const
{
	if (index <= m_current_index && index >= 0)
		return m_pointer[index];
	return m_pointer[0];
}
//--------------------------------------------------------------------------------------------//
//----------------------------Comparative Operators------------------------------------------//
//------------------------------------------------------------------------------------------//
bool Array::operator==(const Array& object) const
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
bool Array::operator!=(const Array& object) const
{
	return !(this->operator==(object));
}
//--------------------------------------------------------------------------------------------//
//----------------------------Output functions-----------------------------------------------//
//------------------------------------------------------------------------------------------//
void Array::showElements() const
{
	for (int i = 0; i < getElemSize(); i++)
		std::cout << m_pointer[i] << " ";
}
// Overloadaed operator << for more convinient output
std::ostream& operator<<(std::ostream& os, const Array& object)
{
	object.showElements();
	return os;
}