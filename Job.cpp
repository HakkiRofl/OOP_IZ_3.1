#include "Calls.h"


Job::Job(const char* name, const char* surname, int64_t number, const char* workplace)
{
    add_contact(name, surname, number, workplace);
}


void Job::add_contact(const char* name, const char* surname, int64_t number, const char* workplace)
{
    Phone_Book::add_contact(name, surname, number);
    if (len(workplace) > 63)
    {
        for (size_t i = 0; i < 60; i++)
        {
            this->workplace[i] = workplace[i];
        }
        this->workplace[60] = '.';
        this->workplace[61] = '.';
        this->workplace[62] = '.';
        this->workplace[63] = '\0';
    }
    else if (len(workplace) < 63)
    {
        for (size_t i = 0; i < 63; i++)
        {
            this->workplace[i] = workplace[i];
        }
        this->workplace[63] = '\0';
    }
}


void Job::add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call)
{
    Call::add_call(start_time, len_of_call, get_number(), Incoming_Call);
}


void Job::print()
{
    printf("Имя: %s Фамилия: %s\nНомер телефона (%s) : %" PRId64 "\nМесто работы : % s\n\n", Phone_Book::get_name(), get_surname(), get_type_phone(), get_number(), workplace);
}


void Job::print_call()
{
    Call::print();
}


void Job::print_last_call()
{
    printf("ПОСЛЕДНИЙ ЗВОНОК из раздела РАБОТА:\n");
    if (calls.size())
        Call::print(calls.back());
    else
        printf("Последнего звонка нет!\n");
}
