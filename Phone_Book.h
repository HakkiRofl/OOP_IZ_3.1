#pragma once
#include <cstdint>


class Phone_Book
{
private:
    char name[16] = "Empty";
    char surname[32] = "Empty";
    char type_phone[8] = "Empty";
    int64_t number = 0;
protected:
    size_t len(const char* str); // Перегрузка метода определения длины для числа и строки
    size_t len(int64_t num);
    void add_contact(const char* name, const char* surname, int64_t number);
};
