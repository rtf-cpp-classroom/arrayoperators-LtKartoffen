// Array.h -- definition Array-class
#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>		// input-output array


// TODO:  write your Array class  here 
// we will use generic idea - template class
template <class T>
class Array {
public:

private:
	int m_size;
	int m_current_index;
	int m_step;
	T* m_pointer;


};

#endif // !ARRAY_H_