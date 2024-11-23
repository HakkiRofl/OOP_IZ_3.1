#pragma once
#include "Phone_Book.h"
#include "Call.h"

class Job : public Phone_Book, Call
{
private:
    static size_t count;
    char workplace[64] = "Empty";
public:

};

