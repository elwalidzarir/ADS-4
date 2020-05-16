#include <cassert>

template<typename T>
class TPQueue
{
  // Сюда помещается описание структуры "Очередь с приоритетами"
    struct ITEM
    {
        T data;
        ITEM* next;
    };
public:
    TPQueue() :head(nullptr), tail(nullptr) {}
    ~TPQueue();
    void push(const T&);
    T pop();
    void print() const;
private:
    TPQueue::ITEM* create(const T&);
    ITEM* head;
    ITEM* u;
    ITEM* tail;
};
template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& data)
{
    ITEM* item = new ITEM;
    item->data = data;
    item->next = nullptr;
    return item;
}
template<typename T>
TPQueue<T>::~TPQueue()
{
    while (head)
        pop();
}
template<typename T>
void TPQueue<T>::push(const T& inf)
{
    if (head == nullptr)
    {
        head = create(inf);
        u = head;
        tail = head;
    }
    else if (tail->data.prior >= inf.prior)
    {

        if (tail->data.prior == inf.prior && tail->data.ch == inf.ch)
        {

            tail->data = inf;

        }
        else
        {
            if (tail->data.prior >= inf.prior && tail->data.ch != inf.ch)
            {
                tail->next = create(inf);
                tail = tail->next;
            }
        }
    }
    else
    {

        if (tail->data.prior < inf.prior)
        {
            if (inf.prior > head->data.prior)
            {
                ITEM* tmp = NULL;
                tmp = create(inf);
                tmp->next = head;
                head = tmp;
            }
            else

                if (inf.prior == head->data.prior)

                    if (inf.ch == head->data.ch)
                        head->data = inf;
                    else
                    {
                        ITEM* u = nullptr;
                        u = create(inf);
                        u->next = head->next;
                        head->next = u;

                    }

                else
                {
                    if (inf.prior < head->data.prior)
                    {
                        ITEM* u = nullptr;
                        u = create(inf);
                        u->next = head->next;
                        head->next = u;
                    }
                }





        }
    }
}

template<typename T>
T TPQueue<T>::pop()
{
    if (head)
    {
        ITEM* temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        return data;
    }

}
template<typename T>
void TPQueue<T>::print() const	
{
    {
        ITEM* temp = head;	   
        while (temp)	 
        {
            {
                std::cout << temp->data << " ";	        
                temp = temp->next;	       
            }
        }
        std::cout << std::endl;	    std::cout << std::endl;
    }
}

struct SYM
{
	char ch;
	int  prior;
}; 
    char ch;
    int prior;
    SYM* next;
};  
