/* Модуль обработки строки!
Преобразует строку к удобному для подсчета виду

A	acos 	арккосинус	+ +
B	asin 	арксинус	+ +
D	atan 	арктангенс	+ +
E	atan2 	арктангенс с двумя параметрами	- -
F	ceil 	округление до ближайшего большего целого числа	+ +
C	cos 	косинус	+ +
J	ch 	гиперболический косинус	+ +
H	exp 	вычисление экспоненты	+ +
I	abs 	абсолютная величина (числа с плавающей точкой)	+ +
K	floor 	округление до ближайшего меньшего целого числа	+ +
L	fmod 	вычисление остатка от деления нацело для чисел с плавающей точкой
M	ctg  котангенс + +
N	actg аркккотангенс + +
G	ln 	натуральный логарифм	+ +
O	log 	логарифм по основанию 10	+ +
P	cth гиперболический котангенс ++
R	pow(x,y) 	результат возведения x в степень y, xy
S	sin 	синус	+ +
T	sh 	гиперболический синус	+  +
Y	sqrt 	квадратный корень	+ +
V	tan 	тангенс	+ +
W	th 	гиперболический тангенс	+ +
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "text_analiz.h"

char* ficha(char* st2)
{
    char *st3;
    int i=0,j=0,k=0;
	st3=new char[101];
        int len=strlen(st2);
        while(i<len)
    {
            st3[i+k]=st2[i];
	    if (st2[i]=='(')
			if (st2[i+1]=='-')
			{
				st3[i+1+k]='0';
				k++;
				j=i+13;
				  while(j<len)
				  {
					  st3[j+k]=st2[j];
					  j++;
				  }
			}
			i++;
    }
    st2=st3;
  return st2;
}

///Процедура бреобразует строку к нижнему регистру
char* registr(char* st1)
{
    int i=0;
        int len=strlen(st1);
        while(i<len)
    {
                if(st1[i]>='A'&& st1[i]<='Z') st1[i]=st1[i]+32;
        i++;
    }
  return st1;
}

void *ssin(int i,char *input)
{
    if (input[i]=='s'  )
        {
            if (input[i+1]=='i' )
            {
                if (input[i+2]=='n')
                {
                    input[i]='S';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}

void *ccos(int i,char *input)
{
    if (input[i]=='c'  )
        {
            if (input[i+1]=='o' )
            {
                if (input[i+2]=='s')
                {
                    input[i]='C';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}

void *aacos(int i,char *input)
{
     if (input[i]=='a')
        {
	if (input[i+1]=='c'  )
        {
            if (input[i+2]=='o' )
            {
                if (input[i+3]=='s' )
                {
                    input[i]='A';
                    input[i+1]=' ';
                    input[i+2]=' ';
		    input[i+3]=' ';
                }
            }
        }
	}
      return input;
}

void *aasin(int i,char *input)
{
     if (input[i]=='a'  )
        {
	if (input[i+1]=='s'  )
        {
            if (input[i+2]=='i' )
            {
                if (input[i+3]=='n' )
                {
                    input[i]='B';
                    input[i+1]=' ';
                    input[i+2]=' ';
		    input[i+3]=' ';
                }
            }
        }
	}
      return input;
}

void *aatan(int i,char *input)
{
     if (input[i]=='a')
        {
	if (input[i+1]=='t' )
        {
            if (input[i+2]=='a' )
            {
                if (input[i+3]=='n')
                {
                    input[i]='D';
                    input[i+1]=' ';
                    input[i+2]=' ';
		    input[i+3]=' ';
                }
            }
        }
	}
      return input;
}

void *cceil(int i,char *input)
{
     if (input[i]=='c'  )
        {
	if (input[i+1]=='e' )
        {
            if (input[i+2]=='i')
            {
                if (input[i+3]=='l')
                {
                    input[i]='F';
                    input[i+1]=' ';
                    input[i+2]=' ';
		    input[i+3]=' ';
                }
            }
        }
	}
      return input;
}

void *cch(int i,char *input)
{
     if (input[i]=='c'  )
        {
                if (input[i+1]=='h')
                {
                    input[i]='J';
                    input[i+1]=' ';
                }
	}
      return input;
}

void *eexp(int i,char *input)
{
    if (input[i]=='e'  )
        {
            if (input[i+1]=='x' )
            {
                if (input[i+2]=='p')
                {
                    input[i]='H';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}

void *aabs(int i,char *input)
{
    if (input[i]=='a'  )
        {
            if (input[i+1]=='b' )
            {
                if (input[i+2]=='s')
                {
                    input[i]='I';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}


void *ffloor(int i,char *input)
{
     if (input[i]=='f'  )
        {
	if (input[i+1]=='l' )
        {
            if (input[i+2]=='o')
            {
                if (input[i+3]=='o')
		{
			if (input[i+4]=='r')
			{
				input[i]='K';
				input[i+1]=' ';
				input[i+2]=' ';
				input[i+3]=' ';
				input[i+4]=' ';
			}
		}
	    }
	}
	}

      return input;
}

void *lln(int i,char *input)
{
    if (input[i]=='l'  )
        {
            if (input[i+1]=='n' )
            {
                    input[i]='G';
                    input[i+1]=' ';
            }
        }
      return input;
}

void *llog(int i,char *input)
{
    if (input[i]=='l'  )
        {
            if (input[i+1]=='o' )
            {
                if (input[i+2]=='g')
                {
                    input[i]='O';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}

void *ssh(int i,char *input)
{
     if (input[i]=='s'  )
        {
                if (input[i+1]=='h')
                {
                    input[i]='T';
                    input[i+1]=' ';
                }
	}
      return input;
}

void *ssqrt(int i,char *input)
{
     if (input[i]=='s'  )
        {
	if (input[i+1]=='q' )
        {
            if (input[i+2]=='r')
            {
                if (input[i+3]=='t')
                {
                    input[i]='Y';
                    input[i+1]=' ';
                    input[i+2]=' ';
		    input[i+3]=' ';
                }
            }
        }
	}
      return input;
}


void *ttan(int i,char *input)
{
    if (input[i]=='t'  )
        {
            if (input[i+1]=='a' )
            {
                if (input[i+2]=='n')
                {
                    input[i]='V';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}

void *tth(int i,char *input)
{
     if (input[i]=='t'  )
        {
                if (input[i+1]=='h')
                {
                    input[i]='W';
                    input[i+1]=' ';
                }
	}
      return input;
}

void *cctg(int i,char *input)
{
    if (input[i]=='c'  )
        {
            if (input[i+1]=='t' )
            {
                if (input[i+2]=='g')
                {
                    input[i]='M';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}


void *aactg(int i,char *input)
{
     if (input[i]=='a'  )
        {
	if (input[i+1]=='c' )
        {
            if (input[i+2]=='t')
            {
                if (input[i+3]=='g')
                {
                    input[i]='N';
                    input[i+1]=' ';
                    input[i+2]=' ';
		    input[i+3]=' ';
                }
            }
        }
	}
      return input;
}

void *ccth(int i,char *input)
{
    if (input[i]=='c'  )
        {
            if (input[i+1]=='t' )
            {
                if (input[i+2]=='h')
                {
                    input[i]='P';
                    input[i+1]=' ';
                    input[i+2]=' ';
                }
            }
        }
      return input;
}


 


char *proobraz(char* input)
{
input = registr(input);

input=  ficha(input);
for (int i=0;i<strlen(input);i++)
    {
       ssin(i,input);
       ccos(i,input);
       aasin(i,input);
       aacos(i,input);
       aatan(i,input);
       cceil(i,input);
       cch(i,input);
       eexp(i,input);
       aabs(i,input);
       ffloor(i,input);
       lln(i,input);
       llog(i,input);
       ssh(i,input);
       ssqrt(i,input);
       ttan(i,input);
       tth(i,input);
       cctg(i,input);
	aactg(i,input);
	ccth(i,input);
    }
    return input;
}

char *len(char* input1,char* value)
{
	 int i=0;
      int length=strlen(value);
          char *st3;
          int jj=0,k=0;
              st3=new char[101];
              int len=strlen(value);
              while(jj<len)
          {
                  st3[jj+k]=value[jj];
                  if (value[jj]=='(')
                              if (value[jj+1]=='-')
                              {
                                  length++;
                              }
                             jj++;
          }
          value=st3;
      for(i=0;i<=length;i++)
      {
      }
      input1[i-1] = '\0';   
      return input1;
}
