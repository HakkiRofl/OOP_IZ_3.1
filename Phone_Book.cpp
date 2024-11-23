#include "Phone_Book.h"
#include <iostream>


size_t Phone_Book::len(const char* str)
{
    size_t len = 0;
    size_t i = 0;
    while (str[i] != '\0')
        {
            i++;
            len++;
        }
    return len;
}


size_t Phone_Book::len(int64_t num)
    {
        size_t len = 1;
        if (num > 1)
            for (len = 0; num > 0; len++)
                num /= 10;
        return len;
    }


void Phone_Book::add_contact(const char* name, const char* surname, int64_t number)
{
    // Проверка на длину и корректность номера

    if (len(name) > 15)
    {
        for (size_t i = 0; i < 12; i++)
        {
            this->name[i] = name[i];
        }
        this->name[12] = '.';
        this->name[13] = '.';
        this->name[14] = '.';
        this->name[15] = '\0';
    }

    else if (len(name) < 15)
    {
        for (size_t i = 0; i < 15; i++)
        {
            this->name[i] = name[i];
        }
        this->name[15] = '\0';
    }


    if (len(surname) > 31)
    {
        for (size_t i = 0; i < 28; i++)
        {
            this->surname[i] = surname[i];
        }
        this->surname[28] = '.';
        this->surname[29] = '.';
        this->surname[30] = '.';
        this->surname[31] = '\0';
    }

    else if (len(surname) < 31)
    {
        for (size_t i = 0; i < 31; i++)
        {
            this->surname[i] = surname[i];
        }
        this->surname[31] = '\0';
    }



    if (len(number) == 11)
    {
        if (number / int64_t(10e9) == 7 || number / int64_t(10e9) == 8)
        {
            this->number = number;
            char buffer[] = "Mobile";
            for (size_t i = 0; i < len(buffer); i++)
            {
                this->type_phone[i] = buffer[i];
            }
            this->type_phone[len(buffer)] = '\0';
        }
        else
            std::cout << "\nМобильный номер должен начинаться с 7 или 8! (79123456789)\n\n";
    }

    else if (len(number) == 6)
    {
        this->number = number;
        char buffer[] = "Home";
        for (size_t i = 0; i < len(buffer); i++)
        {
            this->type_phone[i] = buffer[i];
        }
        this->type_phone[len(buffer)] = '\0';
    }


    else
        std::cout << "\nНомер телефона должен содержать 6 или 11 цифр!\n\n";
}