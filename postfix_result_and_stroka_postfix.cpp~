/*	ПОдсчет значения функции (исходным значением является строка записанная в постфиксной записи) и функция
запоминающая строку в постфиксной записи.

char *vixod(char *input) - запоминает строку(return output;)

float polka(char *output,float x,float y) - выдает результат
output-входная строка
return res - возвращает значение функции
x,y-аргументы функици

A	acos 	арккосинус	+ +
B	asin 	арксинус	+ +
D	atan 	арктангенс	+ +
E	atan2 	арктангенс с двумя параметрами	-
F	ceil 	округление до ближайшего большего целого числа	+ +
C	cos 	косинус	+ +
J	ch 	гиперболический косинус	+ +
H	exp 	вычисление экспоненты	+ +
I	fabs 	абсолютная величина (числа с плавающей точкой)	+ +
K	floor 	округление до ближайшего меньшего целого числа	+ +
L	fmod 	вычисление остатка от деления нацело для чисел с плавающей точкой
M	ctg  котангенс + +
N	actg аркккотангенс ++
G	ln 	натуральный логарифм	+ +
O	log 	логарифм по основанию 10	+ +
P	cth арккотангенис ++
R	pow(x,y) 	результат возведения x в степень y, xy
S	sin 	синус	+ +
T	sh 	гиперболический синус	+  +
Y	sqrt 	квадратный корень	+ +
V	tan 	тангенс	+ +
W	th 	гиперболический тангенс	+ +
*/

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Infix_postfix.cpp"
#include "postfix_result_and_stroka_postfix.h"

///Функция преобразует строку в постфиксную запись и работает с ней
char *vixod(char *input)
{
char *output;
output = new char[100];
	output = shunting_yard(input, output);
return output;

}

///Функция считает результат
float polka(char *output,float x,float y)
{
int flagg=0;
char *podstring;
int j;
for (int i = 0; i < strlen(output); i++)
{
if ((output[i]=='x') || (output[i]=='y') ) { flagg=1;} }

float podchislo;
	float stack[70];
        float res;
        int m = 0;
        for (int i = 0; i < strlen(output); i++)
        {
                if (output[i] >= '0' && output[i] <= '9' || output[i] == 'x'  || output[i] == 'y' )
                {

					if (output[i] == 'x')
					{ stack[m] = x;}
					else
						if (output[i] == 'y')
						{ stack[m] = y;}
						else
					{podstring = new char[20];
						for(j=0; output[i+j] != ' ';j++)
						{
							//if (output[i+j] == '.')
							//	podstring[j]= '.';
							//else
							podstring[j] = output[i+j];
						}
						podchislo=atof(podstring);
						delete[] podstring;
						stack[m] = podchislo;
						i=i+j;
					}
                        m++;
                        continue;
                }
                switch (output[i])
                {
                        case '+':
                        {
                                res = stack[m - 2] + stack[m - 1];
								stack[m - 2] = res;
								 m--;
                                break;
                        }
                        case '-':
                        {
                                    res = stack[m - 2] - stack[m - 1];
								stack[m - 2] = res;
								 m--;
                                break;
                        }
                        case '*':
                        {
                                res = stack[m - 2] * stack[m - 1];
								stack[m - 2] = res;
								m--;
                                break;
                        }
                        case '/':
                        {
                                res = stack[m - 2] / stack[m - 1];
								stack[m - 2] = res;
								m--;
                                break;
                        }
						case 'S':
                        {
                                res = sin(stack[m - 1]) ;
								stack[m - 1] = res;


                           break;

                        }
						case 'C':
                        {
                                res = cos(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'A':
                        {
                                res = acos(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'B':
                        {
                                res = asin(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }

						case 'D':
                        {
                                res = atan(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }

						case 'F':
                        {
                                res = ceil(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'J':
                        {
                                res = cosh(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'H':
                        {
                                res = exp(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'I':
                        {
                                res = fabs(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'K':
                        {
                                res = floor(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'G':
                        {
                                res = log(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'O':
                        {
                                res = log10(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'T':
                        {
                                res = sinh(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'Y':
                        {
                                res = sqrt(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'V':
                        {
                                res = tan(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						case 'W':
                        {
                                res = tanh(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }
						 case '!':
                        {int n=stack[m - 1];
                             stack[m - 1]=1;
                                for (int jj = 1; jj <= n; ++jj)
                                {
                                    stack[m - 1]= stack[m - 1]* jj;
                                }
                            res = stack[m - 1];
								stack[m - 1] = res;

                                break;
                        }

						case '^':
                        {
                                res = pow(stack[m - 2] , stack[m - 1]);
								stack[m - 2] = res;
								 m--;
                                break;
                        }

						case 'M':
                        {
                               res = 1.0 / tan(stack[m - 1]);
								stack[m - 1] = res;
                                break;
                        }
						case 'N':
                        {
                                res =atan(1.0/stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }

						case 'P':
                        {
                                res = 1.0 / tanh(stack[m - 1]);
								stack[m - 1] = res;

                                break;
                        }

                }
        }
return res;
}
