#include <iostream>
#include <string>

using namespace std;

class carClass
{
private:
    string mark;
    int amount;
    float price;
    carClass *next, *prev;
public:
    carClass();
    carClass(string m, int a, float p);
    carClass* getNext();
    void setNext(carClass* obj);
    carClass* getPrev();
    void setPrev(carClass* obj);
    void view();
};

carClass::carClass()
{
    mark = "string";
    amount = 0;
    price = 0;
}

carClass::carClass(string m, int a, float p)
{
    mark = m;
    amount = a;
    price = p;
}

carClass* carClass::getNext()
{
    return next;
}

void carClass::setNext(carClass* obj)
{
    next = obj;
}

carClass* carClass::getPrev()
{
    return prev;
}

void carClass::setPrev(carClass* obj)
{
    prev = obj;
}

void carClass::view()
{
    cout << "Mark: " << mark << endl;
    cout << "Amount: " << amount << endl;
    cout << "Price: " << price << endl << endl;
}

class listClass
{
private:
    carClass *temp, *head, *tail;
public:
    listClass();
    ~listClass();
    void add();
    void addFirst();
    void delFirst();
    void addLast();
    void addSpecial();
    void view();
};

listClass::listClass()
{
    temp = NULL;
    head = NULL;
    tail = NULL;
}

listClass::~listClass()
{
    delete temp;
    while(head != NULL)
    {
        tail = head->getNext();
        delete head;
        head = tail;
    }
}

void listClass::add()
{
    string m;
    int a;
    float p;
    char answer;

    do {
        cout << "Input information about car." << endl;
        cout << "Mark: ";
        cin >> m;
        cout << "Amount: ";
        cin >> a;
        cout << "Price: ";
        cin >> p;

        temp = new carClass(m, a, p);
        temp->setNext(NULL);
        if (head != NULL)
        {
            temp->setPrev(tail);
            tail->setNext(temp);
            tail = temp;
        }
        else
        {
            temp->setPrev(NULL);
            head = tail = temp;
        }

        cout << endl << "Input information about another car? (Y/N): ";
        cin >> answer;
        cout << endl;
    } while (toupper(answer) != 'N');
}

void listClass::delFirst()
{
    if (head != NULL)
    {
        temp = head->getNext();
        temp->setNext(NULL);
        delete head;
        head = temp;
    }
    else
        cout << "List is empty." << endl << endl;
}

void listClass::addSpecial()
{
    string m;
    int a, i = 0, pos;
    float p;
    carClass *curr;

    cout << "Input information about car." << endl;
    cout << "Mark: ";
    cin >> m;
    cout << "Amount: ";
    cin >> a;
    cout << "Price: ";
    cin >> p;
    temp = new carClass(m, a, p);
    cout << endl << "Input position to add: ";
    cin >> pos;
    //Без проверок
    curr = head;
    while (i != (pos-1))
    {
        curr = curr->getNext();
        i++;
    }
    temp->setNext(curr);
    temp->setPrev(curr->getPrev());
    curr->getPrev()->setNext(temp);
    curr->setPrev(temp);
}

void listClass::view()
{
    temp = head;
    cout << "Information about cars." << endl;
    while (temp != NULL)
    {
        temp->view();
        temp = temp->getNext();
    }
}

int main()
{
    listClass List;
    List.add();
    List.addSpecial();
    List.view();
}
