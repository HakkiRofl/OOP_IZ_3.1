#include "Calls.h"


Friend::Friend(const char* name, const char* surname, int64_t number, bool Best_Friend, bool Emergency_Contact)
{
    add_contact(name, surname, number, Best_Friend, Emergency_Contact);
}

void Friend::add_contact(const char* name, const char* surname, int64_t number, bool Best_Friend, bool Emergency_Contact)
{
    Phone_Book::add_contact(name, surname, number);
    this->Best_Friend = Best_Friend;
    this->Emergency_Contact = Emergency_Contact;
}


void Friend::add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call)
{
    Call::add_call(start_time, len_of_call, get_number(), Incoming_Call);
}


void Friend::print()
{
    if (Best_Friend)
    {
        printf("������ ���� ");
    }
    if (Emergency_Contact)
    {
        printf("( ���������� ������� )");
    }
    printf("\n���: %s �������: %s\n����� �������� (%s) : %" PRId64 "\n\n", Phone_Book::get_name(), get_surname(), get_type_phone(), get_number());
}


void Friend::print_call()
{
    Call::print();
}


void Friend::print_last_call()
{
    printf("��������� ������ �� ������� ������:\n");
    if (calls.size())
        Call::print(calls.front());
    else
        printf("���������� ������ ���!\n");
}