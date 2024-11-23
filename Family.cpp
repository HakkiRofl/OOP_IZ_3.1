#include "Calls.h"


Family::Family(const char* name, const char* surname, int64_t number, relatives relative)
{
    add_contact(name, surname, number, relative);
}

void Family::add_contact(const char* name, const char* surname, int64_t number, relatives relative)
{
    Phone_Book::add_contact(name, surname, number);
    this->relative = relative;
}


void Family::add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call)
{
    Call::add_call(start_time, len_of_call, get_number(), Incoming_Call);
}


void Family::print()
{
    char whois[64];
    switch (relative)
    {
    case Empty:
        strcpy_s(whois, "Empty");
        break;
    case Mother:
        strcpy_s(whois, "Mother");
        break;
    case Father:
        strcpy_s(whois, "Father");
        break;
    case Grandfather:
        strcpy_s(whois, "Grandfather");
        break;
    case Grandmother:
        strcpy_s(whois, "Grandmother");
        break;
    case Brother:
        strcpy_s(whois, "Brother");
        break;
    case Sister:
        strcpy_s(whois, "Sister");
        break;
    case Other:
        strcpy_s(whois, "Other");
        break;
    }
    printf("Имя: %s Фамилия: %s\nНомер телефона (%s) : %" PRId64 "\nРодственные связи: %s\n\n", Phone_Book::get_name(), get_surname(), get_type_phone(), get_number(), whois);
}



void Family::print_call()
{
    Call::print();
}


relatives Family::get_relative()
{
    return relative;
}


void Family::print_last_call()
{
    printf("ПОСЛЕДНИЙ ЗВОНОК из раздела СЕМЬЯ:\n");
    if (calls.size())
        Call::print(calls.front());
    else
        printf("Последнего звонка нет!\n");
}   