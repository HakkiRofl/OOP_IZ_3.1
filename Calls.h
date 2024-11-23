#pragma once
#include <cstdint>
#include <iostream>
#include <list>
#include <inttypes.h>

struct call // Один звонок
{
    int64_t start_time = 0; // Храним в секундах
    int64_t len_of_call = 0;
    int64_t number = 0;
    bool Incoming_Call = 0; // Входящий звонок!?
};


class Call // Массив звонков с методами (Базовый абстрактный класс)
{
protected:
    std::list<call> calls;
    static call last_call;
    void add_call(int64_t start_time, int64_t len_of_call, int64_t call_number, bool Incoming_Call);
    void print();
    void print(call buffer);
    Call* get_call() { return this; }
public:
    void virtual print_last_call();
};


class Phone_Book // Базовый абстратный класс контактов
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
public:
    char* get_name() { return name; }
    char* get_surname() { return surname; }
    char* get_type_phone() { return type_phone; }
    int64_t get_number() { return number; }
};


class Job : public Phone_Book, public Call
{
private:
    char workplace[64] = "Empty";
public:
    Job() {};
    Job(const char* name, const char* surname, int64_t number, const char* workplace);  
    ~Job() {};
    void add_contact(const char* name, const char* surname, int64_t number, const char* workplace);
    void add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call);
    void print();
    void print_call();
    char* get_workplace() { return workplace; };
    void print_last_call() override;
};



enum relatives { Empty, Mother, Father, Grandfather, Grandmother, Brother, Sister, Other };

class Family : public Phone_Book, public Call
{
private:
    relatives relative;
public:
    Family() {};
    Family(const char* name, const char* surname, int64_t number, relatives relative);
    ~Family() {};
    void add_contact(const char* name, const char* surname, int64_t number,  relatives relative);
    void add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call);   
    void print();
    void print_call();
    relatives get_relative();
    void print_last_call() override;
};


class Friend : public Phone_Book, public Call
{
private:
    bool Best_Friend = 0;
    bool Emergency_Contact = 0;
public:
    Friend() {};
    Friend(const char* name, const char* surname, int64_t number, bool Best_Friend, bool Emergency_Contact);
    ~Friend() {};
    void add_contact(const char* name, const char* surname, int64_t number, bool Best_Friend, bool Emergency_Contact);
    void add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call);
    void print();
    void print_call();
    bool get_Best_Friends() { return Best_Friend; }
    bool get_Emergency_Contact() { return Emergency_Contact; }
    void print_last_call() override;
};


class Hidden : public Phone_Book, public Call
{
private:
    bool is_private = 0;
public:
    Hidden() {};
    Hidden(const char* name, const char* surname, int64_t number, bool is_private);
    ~Hidden() {};
    void add_contact(const char* name, const char* surname, int64_t number, bool is_private);
    void add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call);
    void print();
    void print_call();
    void print_hidden_call();
    void print_private_contact();
    void print_last_call() override;
};
