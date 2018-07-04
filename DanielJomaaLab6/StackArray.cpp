
#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
{

	top = -1;
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
	top = -1;
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];	

	//loops until the new top reaches the top of the other array
	while (top != other.top)
	{		
		push(other.dataItems[top]);
		top++;
	}
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
	//loops until the new top reaches the top of the other array
	top = -1;
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];


	while (top != other.top)
	{
		push(other.dataItems[top]);
		top++;
	}
	//return and reference to this object
	return this;
}

template <typename DataType>
StackArray<DataType>::~StackArray()
{
	//delete the pointer to the array
	delete [] dataItems;
	top = -1; // reset the top to -1 now that it is empty

}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	//cannt add new if stack is full STACK OVERFLOW
	if (top >= maxSize -1)
		throw logic_error("The Stack is Full");
	//sets the top of the stack equal to the new data item
	top++;
	dataItems[top] = newDataItem;
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
	//cannot remove if stack is empty STACK UNDERFLOw
	if (top == -1)
		throw logic_error("Empty Stack");

	DataType t = 0;
	t = dataItems[top];
	top--;
	return t;
}

template <typename DataType>
void StackArray<DataType>::clear()
{
	//set the top back down to -1 does not clear the memory
	top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	if (top >= maxSize -1)
		return true;
	else
		return false;

}

template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
	if (isEmpty()) {
		cout << "Empty stack." << endl;
	}
	else {
		int j;
		cout << "Top = " << top << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j <= top; j++)
		{
			if (j == top)
			{
				cout << '[' << dataItems[j] << ']' << "\t"; // Identify top
			}
			else
			{
				cout << dataItems[j] << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}