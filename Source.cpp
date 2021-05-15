//�� ����� ���������� list ���������� ����������� ����� ����� ����� 
//�� ���������� �����.�������� �������� ��������� �������� � ����, 
//�������� � ������� �����, ��������� ��� ������� ����� �� �����.


#include <cassert> // ��� assert
#include <iostream>
#include <string>
#include <iomanip> // ��� setw
using namespace std;
template <typename T>
class Stack
{
private:
	T* stackPtr;                      // �������� �� ����
	const int size;                   // ����������� ������� �������� � �����
	int top;                          // ����� �������� �����
public:
	Stack(int = 10);                  // �� ������������� ������ �����
	Stack(const Stack<T>&);          // ����������� ���������
	~Stack();                         // ����������

	inline void push(const T&);     // ��������� �������� � ������� �����
	void pop();                   // ��������� �������� ����� �� �������
	inline void printStack();         // ���� �����
	inline const T& Peek(int) const;
	inline int getStackSize() const;  // ��������� ������ �����
	inline T* getPtr() const;         // ��������� ��������� �� ����
	inline int getTop() const;        // ��������� ������ �������� � �����
	
};
// ����������� 
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize)
{
	stackPtr = new T[size]; // �������� ���'�� �� ����
	top = 0;
}

// ����������� ���������
template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :
	size(otherStack.getStackSize())
{
	stackPtr = new T[size]; // �������� ���'�� �� ����� ����
	top = otherStack.getTop();
	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

template <typename T>
Stack<T>::~Stack()   //����������
{
	delete[] stackPtr; // ��������� �����
}

// ��������� �������� � ����
template <typename T>
inline void Stack<T>::push(const T & value)
{
	assert(top < size);
	stackPtr[top++] = value;
}

// ��������� �������� �� �����
template <typename T>
void Stack<T>::pop()
{
	assert(top > 0);
	stackPtr[--top];
}

// ���������� �-�� �������� �� ������� �����
template <class T>
inline const T& Stack<T>::Peek(int nom) const
{
	assert(nom <= top);
	return stackPtr[top - nom];
}

// ���� �����
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// ������� ����� �����
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// ������� �������� �� ���� ��� ������������ ���������
template <typename T>
inline T* Stack<T>::getPtr() const
{
	return stackPtr;
}

template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}
int main()
{
	setlocale(LC_ALL, "ukr");
	int k;
	cout << "ʳ������ �������� = ";
	cin >> k;
	cout << "�������� ��������(�����) � ����:\n";   //���������� �����
	Stack<int> stackInteger(k);
	int ct1 = 0;
	int ch1;
	while (ct1++ < k)
	{
		cin >> ch1;
		stackInteger.push(ch1); // ��������� �������� � �����
	}
	cout << endl;
	stackInteger.printStack();
	cout << "\n��������� ������� i� �����:\n";
	stackInteger.pop();
	stackInteger.printStack(); 
	Stack<int> newStack1(stackInteger);
	cout << "��������� ����������� ���i������\n";
	newStack1.printStack();

	cout << "ʳ������ �������� = ";
	cin >> k;
	cout << "�������� ��������(�����) � ����:\n";   //���������� �����
	Stack<string> stackString(k);
	int ct2 = 0;
	string ch2;
	while (ct2++ < k)
	{
		cin >> ch2;
		stackString.push(ch2);
	}
	cout << endl;
	stackString.printStack();
	cout << "\n��������� ������� i� �����:\n";
	stackString.pop();
	stackString.printStack();
	Stack<string> newStack2(stackString);
	cout << "��������� ����������� ���i������\n";
	newStack2.printStack();

	

	system("Pause");
}