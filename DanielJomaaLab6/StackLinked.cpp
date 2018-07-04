
#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{	
	top = 0;
	//linked list does not have a max size
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	StackNode *temp, *pre, *newNode;

	push(top); // creates the top of the new stack
	temp = other.top; // this is ready to iterate over the other stack
	pre = top; //now the pre pointer is ready to iterate over the stack
	while (temp->next != NULL)
	{
		newNode = new StackNode(temp.dataItem, NULL);
		pre->next = newNode;
		pre = pre->next;
		temp = temp->next;
	}
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	StackNode *temp, *pre, *newNode;


	push(top); // creates the top of the new stack
	temp = other.top; // this is ready to iterate over the other stack
	pre = top; //now the pre pointer is ready to iterate over the stack
	while (temp->next != NULL)
	{
		newNode = new StackNode(temp.dataItem, NULL);
		pre->next = newNode;
		pre = pre->next;
		top = pre;
		temp = temp->next;
	}

	return this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	//there is no max stack size therefor no full logic error

	StackNode *newNode;
	newNode = new StackNode(newDataItem, NULL);

	if (top == 0)
	{	
		cout << "top created";
		top = newNode;
		
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	if (top == 0)
		throw logic_error("Stack empty");
	
	DataType t = 0;
	StackNode *temp;
	temp = top;
	t = top->dataItem;
	top = top->next; // this essentially removes the top node in the process
	delete temp;
	return t;
}

template <typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode *pre, *temp;
	pre = top;

	while (pre->next != NULL)
	{
		temp = pre;
		pre = pre->next;
		delete temp;
	}

	top = 0;
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	if (top == 0)
		return true;
	else
		return false;
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	//the linked list stack will never be full
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Top\t";
		for (StackNode* temp = top; temp != 0; temp = temp->next) {
			if (temp == top) {
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}

}