//На основі контейнера list побудувати впорядковані стеки цілих чисел 
//та символьних рядків.Виконати операції занесення елемента у стек, 
//значення з вершини стеку, виведення усіх значень стеку на екран.


#include <cassert> // для assert
#include <iostream>
#include <string>
#include <iomanip> // для setw
using namespace std;
template <typename T>
class Stack
{
private:
	T* stackPtr;                      // вказівник на стек
	const int size;                   // максимальна кількість елементів в стеку
	int top;                          // номер елемента стеку
public:
	Stack(int = 10);                  // за замовчуванням роозмір стеку
	Stack(const Stack<T>&);          // конструктор копіювання
	~Stack();                         // деструктор

	inline void push(const T&);     // розміщення елемента у вершину стеку
	void pop();                   // видалення елемента стеку із вершини
	inline void printStack();         // вивід стеку
	inline const T& Peek(int) const;
	inline int getStackSize() const;  // отримання розміру стеку
	inline T* getPtr() const;         // отримання вказівника на стек
	inline int getTop() const;        // отримання номера елемента у стеку
	
};
// конструктор 
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize)
{
	stackPtr = new T[size]; // виділення пам'яті під стек
	top = 0;
}

// конструктор копіювання
template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :
	size(otherStack.getStackSize())
{
	stackPtr = new T[size]; // виділення пам'яті під новий стек
	top = otherStack.getTop();
	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

template <typename T>
Stack<T>::~Stack()   //деструктор
{
	delete[] stackPtr; // видалення стеку
}

// додавання елемента в стек
template <typename T>
inline void Stack<T>::push(const T & value)
{
	assert(top < size);
	stackPtr[top++] = value;
}

// видалення елемента із стеку
template <typename T>
void Stack<T>::pop()
{
	assert(top > 0);
	stackPtr[--top];
}

// повернення н-го елемента від вершини стеку
template <class T>
inline const T& Stack<T>::Peek(int nom) const
{
	assert(nom <= top);
	return stackPtr[top - nom];
}

// вивід стеку
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// повертає розмір стеку
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// повертає вказівник на стек для конструктора копіювання
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
	cout << "Кількість елементів = ";
	cin >> k;
	cout << "Заносимо елементи(числа) в стек:\n";   //заповнення стеку
	Stack<int> stackInteger(k);
	int ct1 = 0;
	int ch1;
	while (ct1++ < k)
	{
		cin >> ch1;
		stackInteger.push(ch1); // розміщення елемента в стеку
	}
	cout << endl;
	stackInteger.printStack();
	cout << "\nВидаляємо елемент iз стеку:\n";
	stackInteger.pop();
	stackInteger.printStack(); 
	Stack<int> newStack1(stackInteger);
	cout << "Спрацював конструктор копiювання\n";
	newStack1.printStack();

	cout << "Кількість елементів = ";
	cin >> k;
	cout << "Заносимо елементи(слова) в стек:\n";   //заповнення стеку
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
	cout << "\nВидаляємо елемент iз стеку:\n";
	stackString.pop();
	stackString.printStack();
	Stack<string> newStack2(stackString);
	cout << "Спрацював конструктор копiювання\n";
	newStack2.printStack();

	

	system("Pause");
}