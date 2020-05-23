#include <cassert>
 
template<typename T>
class TPQueue
{
private:
	T* arr; 
	int size; 
	int begin, 
		end; 
	int count; 
public:
	TPQueue(int = 100); 
	~TPQueue(); 

	void push(const T&); 
	T pop(); 
	T get() const; 
	bool isEmpty() const; 
	bool isFull() const; 
};
template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
	size(sizeQueue),
	begin(0), end(0), count(0)
{
	arr = new T[size + 1];
}
template<typename T>
TPQueue<T>::~TPQueue()
{
	delete[] arr;
}
template<typename T>
void TPQueue<T>::push(const T& item)
{
	assert(count < size);

	if (count == 0)
	{
		arr[end++] = item;
		count++;
	}
	else
	{
		int i = end - 1;
		bool pr = 0;
		while ((i >= begin) && (item.prior > arr[i].prior))
		{
			pr = 1;
			arr[i + 1] = arr[i];
			arr[i] = item;
			i--;
		}
		if (pr == 0)
			arr[end] = item;
		end++;
		count++;
	}
	if (end > size)
		end -= size + 1;
}
template<typename T>
T TPQueue<T>::pop()
{
	assert(count > 0);
	T item = arr[begin++];
	count--;
	if (begin > size)
		begin -= size + 1; 
	return item;
}
template<typename T>
T TPQueue<T>::get() const
{
	assert(count > 0);
	return arr[begin];
}
template<typename T>
bool TPQueue<T>::isEmpty() const
{
	return count == 0;
}
template<typename T>
bool TPQueue<T>::isFull() const
{
	return count == size;
}

struct SYM
{
	char ch;
	int  prior;
};
