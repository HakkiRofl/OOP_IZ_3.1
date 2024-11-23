#include "Calls.h"


Hidden::Hidden(const char* name, const char* surname, int64_t number, bool is_private)
{
    add_contact(name, surname, number, is_private);
}


void Hidden::add_contact(const char* name, const char* surname, int64_t number, bool is_private)
{
    Phone_Book::add_contact(name, surname, number);
    this->is_private = is_private;
}


void Hidden::add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call)
{
    Call::add_call(start_time, len_of_call, get_number(), Incoming_Call);
}


void Hidden::print()
{
    if (is_private)
    {
        printf("\n����������\n");
    }
    else
        printf("\n���: %s �������: %s\n����� �������� (%s) : %" PRId64 "\n\n", Phone_Book::get_name(), get_surname(), get_type_phone(), get_number());
}


void Hidden::print_call()
{
    
    if (is_private)
    {
        printf("\n����������\n");
    }
    else
        Call::print();
}

void Hidden::print_hidden_call()
{
    Call::print();
}


void Hidden::print_private_contact()
{
    printf("\n���: %s �������: %s\n����� �������� (%s) : %" PRId64 "\n\n", Phone_Book::get_name(), get_surname(), get_type_phone(), get_number());
}


void Hidden::print_last_call()
{
    printf("��������� ������ �� ������� �������:\n");
    if (calls.size())
        Call::print(calls.back());
    else
        printf("���������� ������ ���!\n");
}