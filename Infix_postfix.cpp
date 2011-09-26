/*
 * Модуль перевода выражения строки из инфиксной в постфиксную запись
 * Авраменко Евгений АК5-31
 *
 * input- входная строка
 * output -выходная строка
 */
 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Infix_postfix.h"

int op_preced(const char c)
{
    switch(c)
    {
        case '!':

        return 4;

        case '*':
        case '/':
        case '%':
	case '^':
        return 3;

        case '+':
        case '-':
        return 2;

        case '=':
        return 1;
    }
    return 0;
}

bool op_left_assoc(const char c)
{
    switch(c)
    {
        // лево-ассоциативные операторы
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
        case '=':
        return true;
        // право-ассоциативные операторы
        case '!':
        case '^':
        return false;
    }
    return false;
}

unsigned int op_arg_count(const char c)
{
    switch(c)
    {
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
        case '=':
        return 2;
        case '!':
		case '^':
        return 1;

        default:
        return c - 'A';
    }
        return 0;
}

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '^' || c == '%' || c == '=' )
#define is_function(c) (c >= 'A' && c <= 'Z' )
#define is_ident(c) ((c >= '0' && c <= '9') || c=='x' || c=='y' || c == '.' )

char* shunting_yard(const char *input, char *output)
{
    const char *strpos = input, *strend = input + strlen(input);
    char c, stack[32], sc, *outpos = output,prob=' ';
    unsigned int sl = 0;
    while(strpos < strend)
    {
        c = *strpos;
        if(c != ' ')
        {
            // Если токен является числом (идентификатором), то добавить его в очередь вывода.
            if(is_ident(c))
            {		do
					{
					*outpos = c;
					++outpos;
					++strpos;
					c = *strpos;
					}
					while( is_ident(c) );



				*outpos = prob;
				++outpos;
				--strpos;
            }
            // Если токен - функция, то положить его в стек.
            else if(is_function(c))
            {
                stack[sl] = c;
                ++sl;
            }
            //Если токен - разделитель аргументов функции (запятая):
            else if(c == ',')
            {
                bool pe = false;
                while(sl > 0)
                {
                    sc = stack[sl - 1];
                    if(sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        // Пока на вершине не левая круглая скобка,
                        // перекладывать операторы из стека в очередь вывода.
                        *outpos = sc; ++outpos;
                        sl--;
                    }
                }
                // Если не была достигнута левая круглая скобка, либо разделитель не в том месте
                // либо была пропущена скобка
                if(!pe)
                {
                    //printf("Error: какая то хрень с функцией");
                    output = "Error";
                    return output;
                }
            }
            // Если токен оператор op1, то:
            else if(is_operator(c))
            {
                while(sl > 0)
                {
                    sc = stack[sl - 1];
                    // Пока на вершине стека присутствует токен оператор op2,
                    // а также оператор op1 лево-ассоциативный и его приоритет меньше или такой же чем у оператора op2,
                    // или оператор op1 право-ассоциативный и его приоритет меньше чем у оператора op2
                    if (is_operator(sc) &&
                        ((op_left_assoc(c) && (op_preced(c) <= op_preced(sc))) ||
                           (!op_left_assoc(c) && (op_preced(c) < op_preced(sc)))))
                    {
                        // Переложить оператор op2 из стека в очередь вывода.
                        *outpos = sc; ++outpos;
                        sl--;
                    }
                    else
                    {
                        break;
                    }
                }
                // положить в стек оператор op1
                stack[sl] = c;
                ++sl;
            }
            // Если токен - левая круглая скобка, то положить его в стек.
            else if(c == '(')
            {
                stack[sl] = c;
                ++sl;
            }
            // Если токен - правая круглая скобка:
            else if(c == ')')
            {
                bool pe = false;
                // До появления на вершине стека токена "левая круглая скобка"
                // перекладывать операторы из стека в очередь вывода.
                while(sl > 0)
                {
                    sc = stack[sl - 1];
                    if(sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        *outpos = sc; ++outpos;
                        sl--;
                    }
                }
                // Если стек кончится до нахождения токена левая круглая скобка, то была пропущена скобка.
                if(!pe)
                {
                   // printf("Error: нарушен баланс скобок");
                    output = "Error";
                    return output;
                }
                // выкидываем токен "левая круглая скобка" из стека (не добавляем в очередь вывода).
                sl--;
                // Если на вершине стека токен - функция, положить его в стек.
                if(sl > 0)
                {
                    sc = stack[sl - 1];
                    if(is_function(sc))
                    {
                        *outpos = sc; ++outpos;
                        sl--;
                    }
                }
            }
            else
            {
               // printf("Неизвестный символ", c);
                output="Error";
                return output; // Unknown token
            }
        }
        ++strpos;
    }
    // Когда не осталось токенов на входе:
    // Если в стеке остались токены:
    while(sl > 0)
    {
        sc = stack[sl - 1];
        if(sc == '(' || sc == ')')
        {
           // printf("Error: нарушен баланс скобок");
            output="Error";
            return output;
        }
        *outpos = sc; ++outpos;
        --sl;
    }

    *outpos = 0; // Добавляем завершающий ноль к строке
    return output;
}
