#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std:: string;

void StrToInt(string str, int *mass, unsigned size)
{
  for(unsigned i = 0; i < size; ++i)
     {
       char buf = str[i];
       mass[((size - 1) - i)] = buf - '0';
     }
}
string sum (string Number_A, string Number_B)
{
     unsigned size_A = Number_A.length();
     unsigned size_B = Number_B.length();
     int *A_mass = new int[size_A];
     int *B_mass = new int[size_B];

     StrToInt(Number_A,A_mass,size_A);
     StrToInt(Number_B,B_mass,size_B);

     unsigned size_Result;

     if(size_A > size_B)
       {
         size_Result = size_A + 1;
       }
     else
       {
          size_Result = size_B + 1;
       }

     int *Result_mass = new int[size_Result]{};

     for(unsigned i = 0; i < (size_Result - 1) ; ++i)
        {
          Result_mass[i] += A_mass[i] + B_mass[i];
          Result_mass[i+1] += (Result_mass[i] / 10);
          Result_mass[i] %= 10;
        }

     if(Result_mass[size_Result - 1] == 0)
       {
         size_Result--;
       }

     string Result;
     for(unsigned i = 0; i < size_Result; ++i)
        {
           Result += static_cast<char>('0' + Result_mass[((size_Result - 1) - i)]);
        }

     delete[] A_mass;
     delete[] B_mass;
     delete[] Result_mass;

  return Result;
}
string multiply (string Number_A, string Number_B)
{
     unsigned size_A = Number_A.length();
     unsigned size_B = Number_B.length();
     int *A_mass = new int[size_A];
     int *B_mass = new int[size_B];

     StrToInt(Number_A,A_mass,size_A);
     StrToInt(Number_B,B_mass,size_B);

     unsigned size_Result = size_A + size_B + 1;
     int *Result_mass = new int[size_Result]{};

     for (unsigned i = 0; i < size_A; ++i)
        {
          for (unsigned j = 0; j < size_B; ++j)
             {
               Result_mass[i + j] += A_mass[i] * B_mass[j];
             }
        }
     for (unsigned i = 0; i < size_Result - 1; ++i)
        {
          Result_mass[i + 1] +=  Result_mass[i] / 10;
          Result_mass[i] %= 10;
        }
     while (Result_mass[size_Result - 1] == 0)
        {
          size_Result-- ;
        }
     string Result;
     for(unsigned i = 0; i < size_Result; ++i)
        {
           Result += static_cast<char>('0' + Result_mass[((size_Result - 1) - i)]);
        }

     delete[] A_mass;
     delete[] B_mass;
     delete[] Result_mass;
  return Result;
}
bool InputCheck(string Number)
{
    for(unsigned i = 0; i < Number.length(); ++i)
       {
         if(!((Number[i] >= '0') && (Number[i] <= '9')))
            {
               return false;
            }
       }
    return true;
}

int main()
{
   Input:
   cout<< "Enter your expression 'a + b' or 'a * b' \n" << ">";
   string Number_A, Number_B;
   char operation;
   cin>> Number_A;
   cin>>operation;
   cin>> Number_B;
   if( !((InputCheck(Number_A)) && (InputCheck(Number_B))) )
     {
             cout<< "Wrong arguments! ";
             goto Input;
     }

   if(operation == '+')
      {
        cout<< "Result> " << sum(Number_A, Number_B);
      }
   else if(operation == '*')
     {
       cout<< "Result>" << multiply(Number_A, Number_B);
     }
   else
     {
       cout<< "Wrong Operation! ";
       goto Input;
     }

    return 0;
}
