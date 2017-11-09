#include <iostream>
#include <stdio.h>

using namespace std;

int main ()
{
  char op;
  const int ALL = (1<<14) - 1;
  int And = ALL;
  int Or  = 0;
  int Xor = 0;
  int ops, num, ori = ALL;
  scanf("%d\n",&ops);
  while(ops--)
  {
    scanf("%c %d\n",&op,&num);
    switch(op)
    {
      case '&' : 
        And &= num;
        Or  &= num;
        Xor &= num;
        //cout << "A:" << And << " O:" << Or << " X:" << Xor << endl;
        break;
      case '|' : 
        Or  |= num;
        And |= num;
        Xor &= ~num;
        //cout << "A:" << And << " O:" << Or << " X:" << Xor << endl;
        break;
      case '^' : 
        Xor = Xor ^ num;
        //cout << "A:" << And << " O:" << Or << " X:" << Xor << endl;
        break;
    }
  }
  int K = (And != ALL);
  K += (Or != 0);
  K += (Xor != 0);
  printf("%d\n",K);
  if(And != ALL) printf("& %d\n",And);
  if(Or  != 0)   printf("| %d\n",Or);
  if(Xor != 0)   printf("^ %d\n",Xor);
  return 0;
}

