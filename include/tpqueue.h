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
private:
    int next(int end);
    int prev(int end);
};
// Определение следующего и предыдущего
template<typename T>
int TPQueue<T>::prev(int be)
{
    if (--be < 0)
        be += size + 1;
    return be;
}
template<typename T>
int TPQueue<T>::next(int be)
{
    if (++be > size)
        be -= size + 1;
    return be;
}

// конструктор по умолчанию
template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0)
{
    // дополнительный элемент поможет нам различать конец и начало очереди
    arr = new T[size + 1];
}

// деструктор класса Queue
template<typename T>
TPQueue<T>::~TPQueue()
{
    delete[] arr;
}

// функция добавления элемента в очередь
template<typename T>
void TPQueue<T>::push(const T& item)
{
    // проверяем, ести ли свободное место в очереди
    assert(count < size);

    if (isEmpty()) // Первый элемент
    {
        arr[end] = item;
    }
    else
    {
        int tmp = prev(end);  // Индекс последнего
                              // Приориет нового меньше последнего (или такой же)
        if (arr[tmp].prior >= item.prior)
        {
            arr[end] = item;
        }
        else
        {
            // Ищем место для вставки, сдвигаем меньших
            do
            {
                arr[next(tmp)] = arr[tmp];
                tmp = prev(tmp);
            } while (arr[tmp].prior < item.prior && next(tmp) != begin);
            arr[next(tmp)] = item;
        }
    }
    // меняем последний и проверка кругового заполнения очереди
    end = next(end);
    count++;
}

// функция удаления элемента из очереди
template<typename T>
T TPQueue<T>::pop()
{
    // проверяем, есть ли в очереди элементы
    assert(count > 0);

    T item = arr[begin];
    begin = next(begin);
    count--;

    return item;
}

// функция чтения элемента на первой позиции
template<typename T>
T TPQueue<T>::get() const
{
    // проверяем, есть ли в очереди элементы
    assert(count > 0);
    return arr[begin];
}

// функция проверки очереди на пустоту
template<typename T>
bool TPQueue<T>::isEmpty() const
{
    return count == 0;
}

// функция проверки очереди на заполненность
template<typename T>
bool TPQueue<T>::isFull() const
{
    return count == size;
}

struct SYM
{
    char ch;
    int prior;
};
