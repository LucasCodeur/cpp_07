/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 08:44:39 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/15 18:36:58 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include <cstdlib>
#include <new>

#define MAX_VAL 750

static void t_new_pointer_a_and_display_value(void);
static void t_create_int_array_and_print(void);
static void t_create_string_array_and_print(void);
static void t_create_char_array_and_print(void);
static void t_create_char_array_and_copy(void);
static void t_create_char_array_and_operator_equal(void);
static void t_create_int_array_and_operator_equal(void);
static void t_out_of_range(void);
static void t_empty_array(void);
static int t_exo(void);
static void t_fail_new(void);
static void t_const_array(void);

int main(int, char**)
{
    t_new_pointer_a_and_display_value();
    t_create_int_array_and_print();
    t_create_string_array_and_print();
    t_create_char_array_and_print();
    t_create_char_array_and_copy();
    t_create_char_array_and_operator_equal();
    t_create_int_array_and_operator_equal();
    t_out_of_range();
    t_empty_array();
    t_exo();
    t_const_array();
    t_fail_new();
    return 0;
}

static void t_const_array(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test : t_const_array" << std::endl;
    Array<int> test(10);
    std::cout << "ORIGINAL ARRAY" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
    {
        test.array[i] = i;
    }
    const Array<int> test2(test);
    for (unsigned int i = 0; i < test2.size(); i++)
    {
        std::cout << test2[0] << std::endl;
    }
}

static void t_fail_new(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test : t_fail_new" << std::endl;
    try
    {
        Array<int> test(-1);
    }
    catch (std::bad_alloc &e)
    {
		std::cout << "Error: " << e.what() << std::endl;
        return;
    }
}

static void t_empty_array(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test : t_empty_array" << std::endl;
    Array<int> test;
}

static void t_out_of_range(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test : t_out_of_range" << std::endl;
    Array<int> test(10);
    std::cout << "ORIGINAL ARRAY" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
    {
        test.array[i] = i;
    }
    for (unsigned int i = 0; i < 12; i++)
    {
        try 
        {
            std::cout << test[i] << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            break ;
        }
    }
}

static void t_create_int_array_and_operator_equal(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test :t_test_create_int_array_and_operator_equal" << std::endl;
    Array<int> test(10);
    std::cout << "ORIGINAL ARRAY" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
    {
        test.array[i] = i;
    }
    for (unsigned int i = 0; i < 10; i++)
    {
         std::cout << test.array[i] << std::endl;
    }
    Array<int> copy_test(2);
    copy_test.array[0] = 42;
    copy_test.array[1] = 47;
    std::cout << "COPY ARRAY before operator equal" << std::endl;
    for (unsigned int i = 0; i < copy_test.size(); i++)
    {
         std::cout << copy_test.array[i] << std::endl;
    }
    copy_test = test;
    std::cout << "COPY ARRAY" << std::endl;
    for (unsigned int i = 0; i < copy_test.size(); i++)
    {
         std::cout << copy_test.array[i] << std::endl;
    }
}

static void t_create_char_array_and_operator_equal(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test :t_test_create_char_array_and_operator_equal" << std::endl;
    Array<char> test(10);
    std::cout << "ORIGINAL ARRAY" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
    {
        test.array[i] = 'a' + i;
    }
    for (unsigned int i = 0; i < 10; i++)
    {
         std::cout << test.array[i] << std::endl;
    }
    Array<char> copy_test;
    copy_test = test;
    std::cout << "COPY ARRAY" << std::endl;
    for (unsigned int i = 0; i < copy_test.size(); i++)
    {
         std::cout << copy_test.array[i] << std::endl;
    }
}

static void t_create_char_array_and_copy(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test :t_test_create_char_array_and_copy" << std::endl;
    Array<char> test(10);
    std::cout << "ORIGINAL ARRAY" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
    {
        test.array[i] = 'a' + i;
    }
    for (unsigned int i = 0; i < 10; i++)
    {
         std::cout << test.array[i] << std::endl;
    }
    Array<char> copy_test(test);
    std::cout << "COPY ARRAY" << std::endl;
    for (unsigned int i = 0; i < copy_test.size(); i++)
    {
         std::cout << copy_test.array[i] << std::endl;
    }
}

static void t_create_char_array_and_print(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test :t_test_create_char_array_and_print" << std::endl;
    Array<char> test(10);
    for (int i = 0; i < 10; i++)
    {
        test.array[i] = 'a' + i;
    }
    for (int i = 0; i < 10; i++)
    {
         std::cout << test.array[i] << std::endl;
    }
}

static void t_create_string_array_and_print(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test :t_test_create_string_array_and_print" << std::endl;
    Array<std::string> test(10);
    for (int i = 0; i < 10; i++)
    {
         std::cout << test.array[i] << std::endl;
    }
}

static void t_create_int_array_and_print(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test : t_test_create_array_do_copy" << std::endl;
    Array<int> test(10);
    for (int i = 0; i < 10; i++)
    {
         std::cout << test.array[i] << std::endl;
    }
}

static void t_new_pointer_a_and_display_value(void)
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Test : t_new_pointer_a_and_display_value" << std::endl;
    int * a = new int();
    std::cout << "Value of a: " << *a << std::endl;
    delete a;
}

static int t_exo(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return (0);
}
