#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std ::endl;

struct Output
{
    bool Error{false};
    int Value = int();
};

class LinkedList
{
private:
    struct Node
      {
        int Data =int();
        Node *NextNode;
      }*Head;
    unsigned Elements{0};

    bool CheckValue(const string &data)
      {
        if(data.empty())
          {
            return false;
          }
        for(unsigned i = 0; i < data.length(); ++i )
          {
            if(!((data[i] >= '0') && (data[i] <= '9') && (data[0] != '-')))
              {
                return false;
              }
          }
        return true;
      }

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

    bool push(const string &input)
      {
        if( !(CheckValue(input)))
          {
             return false;
          }        
        Node *NewNode = new Node;
        int data = stoi(input);
        NewNode->Data = data;
        NewNode->NextNode = Head;
        Head = NewNode;
        Elements++;
        return true;
      }

    bool pop()
      {
        if(Head != nullptr)
          {
            Node *tmp = Head->NextNode;
            delete Head;
            Head = tmp;
            Elements--;
            return true;
          }
        return false;
      }

    Output top()
      {
        Output Result;
        Node *node = Head;
        if(node != nullptr)
          {
            Result.Value = node->Data;
            node = node->NextNode;
          }
        else
          {
            Result.Error = true;
          }
        return Result;
      }

    void PrintAll()
      {
        if(Head != nullptr)
          {
            Node *tmp = Head;
            cout<< endl;
            while(tmp != nullptr)
              {
                cout<< tmp->Data << endl;
                tmp = tmp->NextNode;
              }
            cout<< endl;
          }
       else
         {
           cout<< endl << "Empty" << endl;
         }
      }

    bool insert(const string &input, unsigned Upos)
      {
        Node *TmpHead = Head;        

        if((Upos > Elements) || !(CheckValue(input)))
          {
            return false;
          }

        int data = stoi(input);
        unsigned pos{0};

        while (pos < Upos)
          {
            TmpHead = TmpHead->NextNode;
            pos++;
          }

        Node *tmp = new Node;
        tmp->Data = data;

        Upos < Elements ? tmp->NextNode = TmpHead->NextNode:
                          tmp->NextNode = nullptr;

        TmpHead->NextNode = tmp;
        return true;
      }
    
    Output get (unsigned Upos)
      {
        Output Result;
        if(Upos > Elements)
          {
            Result.Error = true;
            return Result;
          }
        if(Head != nullptr)
          {
            Node *tmp = Head;
            for(unsigned i = 0; i < Upos; ++i )
              {
                tmp = tmp->NextNode;
              }
           Result.Value = tmp->Data;
          }
        else
         {
           Result.Error = true;
         }
       return Result;
      }
    bool remove(unsigned Upos)
      {

        if((Upos > Elements) && (Head == nullptr))
          {
            return false;
          }

        if(Upos == 0 )
          {
            return pop();
          }

        Node *TmpHead = Head;
        unsigned pos{0};
        while (pos < (Upos - 1))
          {
            TmpHead = TmpHead->NextNode;
            pos++;
          }

        Node *tmp = new Node;
        tmp = TmpHead->NextNode;
        TmpHead->NextNode = tmp->NextNode;
        delete  tmp;
        return true;
      }
};

bool CheckInput()
{
    string ErrInput;
    getline(cin,ErrInput);
    if(ErrInput.empty())
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
    cout<< " Commands : 'push x' 'pop' 'top' 'insert x pos' 'get x' 'remove x' 'PrintAll' 'quit'";
    cout<< endl;
    LinkedList List;

    for(;;)
      {
        cout<< ">";
        string command;
        cin>>command;
        if(command == "push")
          {
            string data;
            cin>> data;
            if( !( List.push(data)))
              {
                cout<< "Error";
              }
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
            if(CheckInput() || !(List.top().Error))
              {
                cout<< List.top().Value << endl;
              }
          }
        else if(command == "PrintAll")
          {
            if(CheckInput())
              {
                List.PrintAll();
              }
          }
        else if(command == "insert")
          {
            string data;
            unsigned pos;
            cin>> data >> pos;
            if( !( List.insert(data,pos)))
              {
                cout<< "Error" << endl;
              }
          }
        else if(command == "get")
          {
            unsigned pos;
            cin>> pos;
            if(!CheckInput() || List.get(pos).Error)
              {
                cout<< "Error" << endl;
              }
            else
              {  
                cout << List.get(pos).Value << endl;
              }    
          }
        else if(command == "remove")
          {
            unsigned pos;
            cin>> pos;
            if( !( List.remove(pos)))
              {
                cout<< "Error" << endl;
              }
          }
        else if(command == "quit")
          {
            if(CheckInput())
              {
                cout<<endl;
                return 0;
              }
          }
        else
          {
            cout<< "Wrong command" << endl;
          }
      }
}
