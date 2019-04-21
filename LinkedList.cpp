#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int Data;
    Node *NextNode;
};

class LinkedList
{
private:
    Node *Head;
public:
    LinkedList()
    {
        Head = nullptr;
    }
    ~LinkedList()
    {
        while(Head != nullptr)
        {
            Node *tmp = Head->NextNode;
            delete Head;
            Head = tmp;
        }
    }

    void push(int data)
    {
        Node *tmp = new Node;
        tmp->Data = data;
        tmp->NextNode = Head;
        Head = tmp;
    }

    void pop()
    {
        if(Head != nullptr)
         {
           Node *tmp = Head->NextNode;
           delete Head;
           Head = tmp;
         }
        else
         {
           cout<< endl << "Empty" << endl;
         }
    }

    void top()
    {
        Node *tmp = Head;
        if(tmp != nullptr)
        {
            cout<< endl << tmp->Data << endl;
            tmp = tmp->NextNode;
        }
        else
        {
          cout<< endl << "Empty" << endl;
        }
    }

    void PrintAll()
    {
        Node *tmp = Head;
       if(tmp != nullptr)
        {
          while(tmp != nullptr)
            {
              cout<< endl << tmp->Data << endl;
              tmp = tmp->NextNode;
            }
        }
       else
       {
         cout<< endl << "Empty" << endl;
       }
    }
};

bool CheckInput()
{
    string ErrInput;
    getline(cin,ErrInput);
    if(ErrInput.length() == 0)
     {
      return true;
     }
    else
    {
      cout<<"Wrong command"<<endl;
      return false;
    }
}

int main()
{
    cout<< " Commands : 'push x' 'pop' 'top' 'PrintAll' 'quit'";
    cout<< endl;
    LinkedList List;

    for(;;)
    {
        cout<< endl << ">";
        string command;
        cin>>command;
        if(command == "push")
          {
            string data;
            cin>>data;
            bool IsNegative = false;
            for(unsigned i = 0; i < data.length(); ++i )
              {
                if(!((data[i] >= '0') && (data[i] <= '9')))
                {
                    if( data[0] == '-')
                     {
                        IsNegative = true;
                     }
                    else
                    {
                        cout<< "Wrong number";
                        break;
                    }
                }
              }
            int a = stoi(data);

            List.push(a);
          }
        else if(command == "pop")
          {
            if(CheckInput())
             {
               List.pop();
             }
          }
        else if(command == "top")
          {
            if(CheckInput())
             {
               List.top();
             }
          }
        else if(command == "PrintAll")
          {
            if(CheckInput())
             {
               List.PrintAll();
             }
          }
        else if(command == "quit")
          {
            if(CheckInput())
             {
               return 0;
             }
          }
        else
          {
            cout<< "Wrong command" << endl;
          }
    }
}
