#pragma once
#include <cstdint>


class Call
{
protected:
    int64_t start_time = 0; // ’раним в секундах
    int64_t len_of_call = 0;
    int64_t number = 0;
    bool Incoming_Call = 0; // ¬ход€щий звонок!?
    static Call* last_call;
    void* add_call(int64_t start_time, int64_t len_of_call, bool Incoming_Call, int64_t number);
public:
    void print();
    void print_last_call();
};

