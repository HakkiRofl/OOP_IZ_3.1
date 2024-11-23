#include "Calls.h"


void Call::add_call(int64_t start_time, int64_t len_of_call, int64_t call_number, bool Incoming_Call)
{
    start_time %= 86400;
    call buffer;
    buffer.start_time = start_time;
    buffer.len_of_call = len_of_call;
    buffer.Incoming_Call = Incoming_Call;
    buffer.number = call_number;
    calls.push_back(buffer);

    last_call.start_time = start_time;
    last_call.len_of_call = len_of_call;
    last_call.Incoming_Call = Incoming_Call;
    last_call.number = call_number;
}


void Call::print()
{
    for (call buffer : calls)
    {

        if (buffer.Incoming_Call)
        {
            printf("�������� c ������ %" PRId64 "\n", buffer.number);
        }
        else
        {
            printf("��������� c ������ %" PRId64 "\n", buffer.number);
        }
        printf("� %02i:%02i ������ ������������� %i ������\n\n", buffer.start_time / 3600, buffer.start_time % 60, buffer.len_of_call);
    }
}


void Call::print(call buffer)
{

    if (buffer.Incoming_Call)
    {
        printf("�������� c ������ %" PRId64 "\n", buffer.number);
    }
    else
    {
        printf("��������� c ������ %" PRId64 "\n", buffer.number);
    }
    printf("� %02i:%02i ������ ������������� %i ������\n\n", buffer.start_time / 3600, buffer.start_time % 60, buffer.len_of_call);
}


void Call::print_last_call()
{
    printf("��������� ������ �� ����:\n");
    if (last_call.Incoming_Call)
    {
        printf("�������� c ������ %" PRId64 "\n", last_call.number);
    }
    else
    {
        printf("��������� c ������ %" PRId64 "\n", last_call.number);
    }
    printf("� %02i:%02i ������ ������������� %i ������\n\n", last_call .start_time / 3600, last_call.start_time % 60, last_call.len_of_call);
}