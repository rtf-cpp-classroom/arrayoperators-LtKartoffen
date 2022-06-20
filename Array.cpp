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
	{
		m_pointer = new Item[getSize()];
		for (int i = 0; i < object.getElemSize(); i++)
			m_pointer[i] = object.m_pointer[i];
	}
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
	{
		delete[] m_pointer;
		m_pointer = nullptr;
	}
	// for debugging 
	//std::cout << "Memory after destructor deleted succesfully\n";
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
		// copy to temporary array values
		Item* temp = new Item[m_size - m_step];
		for (int i = 0; i < getElemSize(); i++)
			temp[i] = m_pointer[i];
		delete[] m_pointer;						// delete old array
		// create new array and fill the same values
		m_pointer = new Item[m_size];
		for (int i = 0; i < getElemSize(); i++)
			m_pointer[i] = temp[i];
		delete[] temp;				// free memory after using temporary-variable
		//m_current_index += m_step;
	}
	/*if (m_step == 1)
		m_current_index++;
	else
		m_current_index += m_step - 1;*/
	return true;
}
// Add new element to Array
void Array::setValue(Item value)
{
	// first we must expand our array for set some new value
	this->expandArray(1);
	if (getSize() == getElemSize());
	else m_current_index++;
	m_pointer[m_current_index] = value;
}
// add default array to Array 
void Array::setArray(Item* pArr, int size)
{
	//bool flag = this->expandArray(size);
	//if (flag)					// if correct expanding array
	//{
	//	//int i = m_current_index + 1;
	//	/*if (i == 0)
	//		for (; i < getSize(); i++)
	//			m_pointer[i] = pArr[i];
	//	else
	//		for (; i < getSize(); i++)
	//			m_pointer[i] = pArr[i-m_current_index];*/
	//	for (int i = m_current_index, j = 0; i < getSize(); i++, j++)
	//		m_pointer[i] = pArr[j];
	//	m_current_index = getSize() - 1;
	//}
	//else						// uncorrect expanding (size<0)
	//	std::cerr << "Incorrect expanding array(size of array less 0). Process determinated.\n";
	// 
	// we will use cycle and set values by elements using setValue() function
	for (int i = 0; i < size; i++)
		this->setValue(pArr[i]);
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
// Post increment operation
Array Array::operator++(int)
{
	for (int i = 0; i < getElemSize(); i++)
		m_pointer[i]++;
	return *this;
}
// Add some value to Array
Array Array::operator+(Item value) const
{
	Array temp = *this;
	for (int i = 0; i < temp.getElemSize(); i++)
		temp.m_pointer[i] += value;
	return temp;
}
// Sub some value from Array
Array Array::operator-(Item value) const
{
	return this->operator+(-value);
}
// Friend function of add some value to Array
Array operator+(Item value, const Array& object)
{
	return object.operator+(value);
}
// Self-adding operation
Array Array::operator+=(Item value)
{
	for (int i = 0; i < getElemSize(); i++)
		m_pointer[i] += value;
	return *this;
}
// Adding two Array-objects and return new Array-object
Array Array::operator+(const Array& object) const
{
	Array temp;
	temp.setArray(this->m_pointer, this->getElemSize());	// first Array
	temp.setArray(object.m_pointer, object.getElemSize());	// second Array
	return temp;
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
			if (flag == false)
				return flag;
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