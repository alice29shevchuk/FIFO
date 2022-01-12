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
        next = node->next;
        value = node->value;
    }
};
class FIFO
{
    Node* head;
public:
    explicit FIFO()
    {
        this->head = NULL;
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
    }
    void Show()
    {
        Node* tmp = this->head;
        while (tmp!= NULL)
        {
            std::cout <<"ADRESS:\t"<< tmp << "\t" << tmp->value << "\tNEXT:\t" << tmp->next << "\n";
            tmp = tmp->next;
        }
    }
    Node* remove()
    {
        Node* iter = this->head;
        if (iter!= NULL)
        {
            Node* fordel = new Node(iter);
            iter = iter->next;
            return fordel;
        }
        else
        {
            std::cout << "Список пуст!\n";
        }
        delete iter;
    };
};
int main()
{
    FIFO fifo;
    fifo.Add(1);
    fifo.Add(2);
    fifo.Add(3);
    fifo.Show();
    std::cout << "\n";
    Node* last = fifo.remove();
    std::cout <<"NEW ADRESS:\t"<< last << "\t" << last->value << "\tNEXT:\t"<<last->next<<"\n";
    Node* last2 = fifo.remove();
    std::cout << "NEW ADRESS:\t" << last2 << "\t" << last2->value << "\tNEXT:\t" << last2->next << "\n";
}