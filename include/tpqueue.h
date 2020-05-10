#include <cassert>
 
template<typename T>
class TPQueue
{
   private:
    T* arr;          // массив с данными
    int size;        // максимальное количество элементов в очереди (размер массива)
    int begin,       // начало очереди
        end;         // конец очереди
    int count;       // счетчик элементов
public:
    TPQueue(int = 100);          // конструктор по умолчанию
    ~TPQueue();                 // деструктор

    void push(const T&); // добавить элемент в очередь
    T pop();              // удалить элемент из очереди
    T get() const;        // прочитать первый элемент
    bool isEmpty() const;      // пустая ли очередь?
    bool isFull() const;       // заполнен ли массив?
};


struct SYM
{
	char ch;
	int  prior;
};
