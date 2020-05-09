#include <cassert>

template<typename T>
class TQueue
{
private:
    T* arr;          // массив с данными
    int size;        // максимальное количество элементов в очереди (размер массива)
    int begin,       // начало очереди
        end;         // конец очереди
    int count;       // счетчик элементов
public:
    TQueue(int = 100);          // конструктор по умолчанию
    ~TQueue();                 // деструктор

    void push(const T&); // добавить элемент в очередь
    T pop();              // удалить элемент из очереди
    T get() const;        // прочитать первый элемент
    bool isEmpty() const;      // пустая ли очередь?
    bool isFull() const;       // заполнен ли массив?
private:
    int next(int end);
    int prev(int end);
};
// Определение следующего и предыдущего
template<typename T>
int TQueue<T>::prev(int be)
{
    if (--be < 0)
        be += size + 1;
    return be;
}
template<typename T>
int TQueue<T>::next(int be)
{
    if (++be > size)
        be -= size + 1;
    return be;
}

// конструктор по умолчанию
template<typename T>
TQueue<T>::TQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0)
{
    // дополнительный элемент поможет нам различать конец и начало очереди
    arr = new T[size + 1];
}

// деструктор класса Queue
template<typename T>
TQueue<T>::~TQueue()
{
    delete[] arr;
}

// функция добавления элемента в очередь
template<typename T>
void TQueue<T>::push(const T& item)
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
            } while (arr[tmp].prior < item.prior &&
                     next(tmp) != begin);

            arr[next(tmp)] = item;
        }
    }
    // меняем последний и проверка кругового заполнения очереди
    end = next(end);
    count++;
}

// функция удаления элемента из очереди
template<typename T>
T TQueue<T>::pop()
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
T TQueue<T>::get() const
{
    // проверяем, есть ли в очереди элементы
    assert(count > 0);
    return arr[begin];
}

// функция проверки очереди на пустоту
template<typename T>
bool TQueue<T>::isEmpty() const
{
    return count == 0;
}

// функция проверки очереди на заполненность
template<typename T>
bool TQueue<T>::isFull() const
{
    return count == size;
}

struct SYM
{
    char ch;
    int prior;
};
