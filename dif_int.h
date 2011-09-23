/*
 * Модуль обработки строки!
 * Авраменко Евгений АК5-31
 *
 * Производит вычисления
 */
 
#ifndef DIF_INT_H
#define DIF_INT_H

//#include "dif_int.cpp"
//#include "postfix_result_and_stroka_postfix.h"

///Производная в точке
float dif_in_point(char *input,float x,float y);

///Интегрирование методом трапеций
float int_trap(char *input,float a,float b,float n);

///Интегрирование методом прямоугольников(средних)
float int_pram(char *input,float a, float b, int n);

///Интегрирование методом Симпсона
float int_sims(char *input,float a,float b);

#endif
