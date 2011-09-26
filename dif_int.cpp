/*
 * Модуль обработки строки!
 * Авраменко Евгений АК5-31
 *
 * Производит вычисления
 */

#include <string.h>
#include <stdlib.h>
#include "dif_int.h"
#include "postfix_result_and_stroka_postfix.h"
#include <math.h>

float dif_in_point(char *input,float x,float y)
{
    float z,xx;
	xx = 0.0001;
	z = (polka(vixod(input),x+xx,y) - polka(vixod(input),x-xx,y)) / (2*xx) ;
	return z;
	
}

float int_trap(char *input,float a,float b,float n)//n-шаг
{
	float in_t = 0.0,r;
	for (r = a + in_t ; r< b ;r+=n)
		in_t += polka(vixod(input),r,0);
		in_t = (in_t+ 0.5*(polka(vixod(input),a,0) + polka(vixod(input),b,0)))*n;
        return in_t;
}

float int_pram(char *input,float a, float b, int n )
{
   float result, h;
   int i;
   h = (b-a)/n; //Шаг сетки
   result = 0.0;
   for(i=1; i <= n; i++)
   {
	  ///Вычисляем в средней точке и добавляем в сумму
      result += polka(vixod(input),( a + h * (i - 0.5)),0); 
   }
   result *= h;
   return result;
}


float int_sims(char *input,float a,float b)
{
	float result=0.0;
	result = (b-a)/6*(polka(vixod(input),a,0) + polka(vixod(input),b,0) + 4*polka(vixod(input),(a+b)/2,0));
	return result;
}
