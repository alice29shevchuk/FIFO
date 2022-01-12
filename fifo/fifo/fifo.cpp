#include <iostream>
struct Node
{
    int value;
    Node* next;
    Node()
    {

    }
    Node(Node*node)
    {
        next = NULL;
        value = node->value;
    }
};
class FIFO
{
    Node* head;
    int size;
public:
    explicit FIFO()
    {
        this->head = NULL;
        this->size = 0;
    }
    int getSize()
    {
        return this->size;
    }
    void Add(int value)
    {
        if (this->head == NULL)
        {
            this->head = new Node;
            this->head->value = value;
            this->head->next = NULL;
        }
        else
        {
            Node* iter = this->head;
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            iter->next= new Node;
            iter->next->value = value;
            iter->next->next = NULL;
        }
        size++;
    }
    void Show()
    {
        Node* tmp = this->head;
        if (size != 0)
        {
            while (tmp != NULL)
            {
                std::cout << "ADRESS:\t" << tmp << "\t" << tmp->value << "\tNEXT:\t" << tmp->next << "\n";
                tmp = tmp->next;
            }
        }
        else
        {
            std::cout << "Список пуст!\n";
        }
    }
    Node* remove()
    {
        if (size > 0)
        {
            Node* iter = this->head;
            Node* fordel = new Node(iter);
            if (iter != NULL)
            {
                iter = this->head;
                this->head = this->head->next;
                delete iter;
                size--;
            }
            return fordel;
        } 
    };
};
int main()
{
    setlocale(0, "");
    FIFO fifo;
    fifo.Add(1);
    fifo.Add(2);
    fifo.Add(3);
    fifo.Add(4);
    fifo.Show();
    std::cout << "\n";
    do
    {
        Node* last = fifo.remove();
        std::cout << "NEW ADRESS:\t" << last << "\t" << last->value << "\tNEXT:\t" << last->next << "\n\n";
        //Node* last2 = fifo.remove();
        //std::cout << "NEW ADRESS:\t" << last2 << "\t" << last2->value << "\tNEXT:\t" << last2->next << "\n\n";
        //Node* last3 = fifo.remove();
        //std::cout << "NEW ADRESS:\t" << last3 << "\t" << last3->value << "\tNEXT:\t" << last3->next << "\n\n";
        //Node* last4 = fifo.remove();
        //std::cout << "NEW ADRESS:\t" << last4 << "\t" << last4->value << "\tNEXT:\t" << last4->next << "\n\n";
        //Node* last5 = fifo.remove();
        //std::cout << "NEW ADRESS:\t" << last5 << "\t" << last5->value << "\tNEXT:\t" << last5->next << "\n\n";
        //fifo.Show();
    } while (fifo.getSize() > 0);
    fifo.Show();
}