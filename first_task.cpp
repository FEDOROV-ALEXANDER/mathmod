#include <iostream>
using namespace std;

//класс, в котором задается узел, то есть элемент двусвязного списка
class Node
{
public:
    int value;
    Node* prev;
    Node* next;
    Node(int number, Node* prev = nullptr, Node* next = nullptr)
    {
        this->value = number;
        this->prev = prev;
        if (prev != nullptr) 
        {
            prev->next = this;
            
        }
        this->next = next;
        if (next != nullptr)
        {
            next->prev = this;
        }

    }
    void change_value(int number)
    {
        this->value = number;
        cout << "value " << this->value << "now this"<<endl;
    }
};

class LinkedList
{ 
public:
    Node* head;
    Node* tail;
    int length;

    LinkedList();
    Node* getNodeIndex(int index);
    int getNodeValue(int value);
    void deleteNodeIndex(int number);
    void append(int number);
    void prepend(int number);
    void insert(int value, int index);

};

ostream& operator << (ostream& stream, const Node& node)
{
    stream << "the node " << " has a value = " << node.value << " prev = " << node.prev << " next = " << node.next << endl;
    return stream;
}
  

class Iterator
{
    
protected:
    const LinkedList* list;
    Node* currentNode;
    int currentNumber;
   
public:
    Iterator(const LinkedList& list)
    {
        this->list = &list;
        
        currentNumber = 0;
    }

    virtual bool hasNext() const = 0;

    virtual void next() = 0;

    Node* getNode()
    {
        return currentNode;
    }

    int value() const
    {
        return currentNode->value;
    }

    int number() const
    {
        return currentNumber;
    }
};

class StraightIterator: public Iterator
{
public:
    StraightIterator(const LinkedList& list): Iterator(list)
    {
        currentNode = list.head;
    }

    virtual bool hasNext() const
    {
        if (currentNode == nullptr) return false;
        return currentNode->next != nullptr;
    }

    void next()
    {
        if (currentNode == nullptr or currentNode->next == nullptr) return;
        currentNode = currentNode->next;
        ++currentNumber;
    }
};

class NumberedStraightIterator :public StraightIterator
{
    int index;
public:
    NumberedStraightIterator(const LinkedList& list, int index) : StraightIterator(list)
    {
        this->index = index < 0 ? 0 : index;
    }

    bool hasNext() const
    {
        if (currentNode == nullptr) return false;
        if (currentNumber >= index) return false;
        return currentNode->next != nullptr;
    }
};

class ValueStraightIterator : public StraightIterator
{
    int needValue;
public:
    ValueStraightIterator(const LinkedList& list, int value, int length) : StraightIterator(list)
    {
        this->needValue = value;
    }
    bool hasNext() const
    {
        if (currentNode == nullptr) return false;
        //cout << currentNumber <<"valuestraight"<< endl;
        return currentNode->value != needValue;
    }

};


    

class ReversedIterator : public Iterator
{
public:
    ReversedIterator(const LinkedList& list) : Iterator(list)
    {
        currentNode = list.tail;
        currentNumber = list.length - 1;
    }
    bool hasNext() const
    {
        if (currentNode == nullptr) return false;
        return currentNode->prev != nullptr; 
    }
    void next()
    {
        if (currentNode == nullptr or currentNode->prev == nullptr) return;
        currentNode = currentNode->prev;
        --currentNumber;
    }
};


LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void LinkedList::append(int number)
{
    Node* appended = new Node(number, tail);
    tail = appended;
    if (head == nullptr) head = appended;
    ++length;
    //cout << "appended new element " << number << "length of the list is " << length << endl;
}

void LinkedList::prepend(int number)
{
    Node* prepended = new Node(number, nullptr, head);
    head = prepended;
    if (tail == nullptr) tail = prepended;
    ++length;
}

Node* LinkedList::getNodeIndex(int index)
{
    if (index < 0) return nullptr;
    if (index >= length) return nullptr;
    NumberedStraightIterator iter(*this, index);
    while (iter.hasNext())
    {
        iter.next();
    }
    return iter.getNode();
}
int LinkedList::getNodeValue(int value)
{
    ValueStraightIterator iter(*this, value, length);
    int i = 0;
    while (iter.hasNext())
    {   
        if (length <= i) break;
        iter.next();
        i++;
    }
    
    if (iter.value() != value) return -1;
    return iter.number();

}

void LinkedList :: insert(int value, int index)
{
    if (index < 0) return;
    Node* nodeAfter = getNodeIndex(index);
    Node* inserted = new Node(value, nodeAfter->prev, nodeAfter);
    length++;
}
void LinkedList :: deleteNodeIndex(int index) 
{
    if (index < 0) return;
    Node* nodeRight = getNodeIndex(index+1);
    Node* nodeLeft = getNodeIndex(index - 1);
    nodeLeft->next = nodeRight;
    nodeRight->prev = nodeLeft;
    length--;
}




ostream& operator << (ostream& stream, const Iterator& iterator)
{
    stream << iterator.value() << " element, his number is  " << iterator.number() << endl;
    return stream;
}


ostream& operator << (ostream& stream, const LinkedList& list)
{
    StraightIterator iter(list);
    //ReversedIterator iter(list);
    cout << iter;
    while (iter.hasNext() )
    {
        iter.next();
        cout << iter << endl;
    }
    return stream;
}

int main()
{
    LinkedList list;
    list.append(10);
    list.append(4);
    list.prepend(1488);
    list.prepend(98);
    list.append(69);
    list.append(420);
    list.insert(5, 2);
    cout << list;
    cout<<(list.getNodeIndex(3))->value<<endl;//поиск элемента по индексу
    cout << (list.getNodeValue(10)) << endl;
    cout << (list.getNodeValue(7)) << endl;
    //cout << list;
    StraightIterator straightIter(list);
    Iterator& iter = straightIter;
    int sum = iter.value();
    while (iter.hasNext())
    {
        iter.next();
        sum += iter.value();
    }
}