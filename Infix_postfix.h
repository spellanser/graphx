/*
 * Модуль перевода выражения строки из инфиксной в постфиксную запись
 * Авраменко Евгений АК5-31
 *
 * input- входная строка
 * output -выходная строка
 */
 
#ifndef INFIX_POSTFIX_H
#define INFIX_POSTFIX_H

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '^' || c == '%' || c == '=' )
#define is_function(c) (c >= 'A' && c <= 'Z' )
#define is_ident(c) ((c >= '0' && c <= '9') || c=='x' || c=='y' || c == '.' )
 // Операторы
// Приоритет Оператор Ассоциативность
// 1 ! правая
// 2 * / % левая
// 3 + - левая
// 4 = левая
int op_preced(const char c);

bool op_left_assoc(const char c);

unsigned int op_arg_count(const char c);

///Функция переводящяя строку с постфиксную запись!
char* shunting_yard(const char *input, char *output);

#endif

