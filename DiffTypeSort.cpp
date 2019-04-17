#include <iostream>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

void FillRandMass (double *Arr, unsigned ArrSize)
{
    for(unsigned i = 0; i < ArrSize; ++i)
       {
          Arr[i] =(rand() % 100000) / 10000.0;
       }
}
void FillRandMass (int *Arr, unsigned ArrSize)
{
    for(unsigned i = 0; i < ArrSize; ++i)
       {
          Arr[i] =rand() % 1000;
       }
}
void BubbleSort(double *Arr, unsigned ArrSize)
{
    double buf;
    for(unsigned j = 1; j < (ArrSize-1); ++j)
       {
         for(unsigned i = 0; i < (ArrSize - j); ++i)
            {
              if(Arr[i] > Arr[i+1] )
                {
                  buf = Arr[i+1];
                  Arr[i+1] = Arr[i];
                  Arr[i] = buf;
                }
            }
       }
    for(unsigned i = 0; i < ArrSize; ++i)
       {
        cout<< Arr[i] << " ";
       }
    cout<< "\n\n";
}
void BubbleSort(int *Arr, unsigned ArrSize)
{
    int buf;
    for(unsigned j = 1; j < (ArrSize-1); ++j)
       {
         for(unsigned i = 0; i < (ArrSize - j); ++i)
            {
              if(Arr[i] > Arr[i+1] )
                {
                  buf = Arr[i+1];
                  Arr[i+1] = Arr[i];
                  Arr[i] = buf;
                }
            }
       }
    for(unsigned i = 0; i < ArrSize; ++i)
       {
        cout<< Arr[i] << " ";
       }
    cout<< "\n\n";
}
void BubbleSort(char *Arr, unsigned ArrSize)
{
    bool ErrFlag{0};
   for(unsigned i = 0; i < ArrSize; ++i)
     {
       if( ((Arr[i] >= '0') && (Arr[i] <= '9')) || ((Arr[i] >= 'A') && (Arr[i] >= 'Z')) || ((Arr[i] >= 'a') && (Arr[i] <= 'z')))
         {
           char buf;
           for(unsigned j = 1; j < (ArrSize-1); ++j)
              {
                for(unsigned i = 0; i < (ArrSize - j); ++i)
                   {
                     if(Arr[i] > Arr[i+1] )
                       {
                         buf = Arr[i+1];
                         Arr[i+1] = Arr[i];
                         Arr[i] = buf;
                       }
                   }
             }
        }
     else
        {
          cout<< "Error" << endl;
          ErrFlag = 1;
          break;
        }
    }

   if(!ErrFlag)
     {
       for(unsigned i = 0; i < ArrSize; ++i)
          {
           cout<< Arr[i] << " ";
          }
       cout<< "\n\n";
     }
}
int main()
{
    cout<< "Enter your string \n" << ">";
    char str[100];
    cin>>str;
    unsigned Str_Length = strlen(str);
    cout<< endl;

    constexpr unsigned IntMassSize = 20;
    int Int_Arr[IntMassSize];
    FillRandMass(Int_Arr,IntMassSize);
    constexpr unsigned DoubleMassSize = 20;
    double Double_Arr[DoubleMassSize];
    FillRandMass(Double_Arr,DoubleMassSize);
    cout<< "Before Sort:" << endl;
    for(unsigned i = 0; i < IntMassSize; ++i)
       {
         cout<< Int_Arr[i] << " ";
       }
    cout<< "\n\n";

    for(unsigned i = 0; i < DoubleMassSize; ++i)
       {
         cout<< Double_Arr[i] << " ";
       }
    cout<< "\n\n";
    for(unsigned i = 0; i < Str_Length; ++i)
       {
         cout<< str[i] << " ";
       }
    cout<< "\n\n";
    cout<< "Afrer Sort:\n";
    BubbleSort(Int_Arr,IntMassSize);
    BubbleSort(Double_Arr,DoubleMassSize);
    BubbleSort(str, Str_Length);


    return 0;
}
