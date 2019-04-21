#include <iostream>
#include <stdlib.h>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   Input:
   cout<< "Input your number \n" << ">";
   string Unumber;
   std::getline(cin, Unumber);
   if(Unumber.length() == 0)
     {
       return 0;
     }
   for(unsigned i = 0; i < Unumber.length(); ++i)
      {
        if( !((Unumber[i] >= '0') && (Unumber[i] <= '9')) )
          {
            cout<<"Your number is inncorrect \n";
            goto Input;
          }
      }

   cout<< "Input chunk size \n" << ">";
   unsigned chunkSize;
   cin>>chunkSize;
   if(chunkSize == 0)
     {
       return 0;
     }
   else if(chunkSize > Unumber.length())
     {
        return 0;
     }
   unsigned chunkNum = Unumber.length() / chunkSize;

   if( chunkNum > 0)
     {
       for(unsigned i = 0; i < chunkNum; ++i)
         {
           long buf{0}; // или лучше использовать size_t?
           for(unsigned j = 0; j < chunkSize; ++j)
             {
               buf += pow( (Unumber[j + (chunkSize*i)] - '0'), 3);
             }
            if( !(buf % 2))
              {
                for( unsigned k = 0; k < chunkSize; ++k)
                  {
                     cout<< Unumber[((chunkSize - 1) - k) + (chunkSize*i)];
                  }
              }
            else
              {
                char tmp;
                tmp = Unumber[0+(i*chunkSize)];
                 for(unsigned k = 1; k < chunkSize; ++k)
                   {
                     Unumber[(k+(i*chunkSize) - 1)] = Unumber[k+(i*chunkSize)];
                   }
                 Unumber[(chunkSize -1) + (chunkSize*i)] = tmp;

                for(unsigned k = 0; k < chunkSize; ++k)
                  {
                    cout<< Unumber[k + (chunkSize*i)];
                  }
              }
         }
     }

    return 0;
}
