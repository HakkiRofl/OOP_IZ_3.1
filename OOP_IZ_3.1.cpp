#include <iostream>
#include <list>
#include "Calls.h"

call Call::last_call = {0};

// Для родственных связей нужно писать без скобочек
// enum relatives { Empty, Mother, Father, Grandfather, Grandmother, Brother, Sister, Other };


int main()
{
    std::cout << "Hello World!\n";
    setlocale(LC_ALL, "RUS");

    Job A;
    A.add_contact("Alex", "Petrov", 222333, "TUSUR");
    A.print();
    A.add_call(233445, 6442, 0);
    A.add_call(333445, 6452, 1);
    A.print_call();

    Family B;
    B.add_contact("Nadya", "Petrova", 89510306927, Mother);
    B.add_call(4525, 65, 0);
    B.add_call(43525, 625, 1);
    B.print();
    B.print_call();

    Friend C;
    C.add_contact("Ilya", "Ivanov", 961684, true, true);
    C.add_call(2222, 898, 1);
    C.add_call(864563, 41, 0);
    C.print();
    C.print_call();


    Hidden D;
    D.add_contact("Ilya", "Ivanov", 961684, true);
    D.add_call(99922, 8984, 1);
    D.add_call(8666563, 1241, 0);
    D.print();
    D.print_call();
    D.print_private_contact();
    D.print_hidden_call();


    Call last;
    last.print_last_call();


    Call *last_call;
    last_call = &A;
    last_call->print_last_call();
    last_call = &B;
    last_call->print_last_call();
    last_call = &C;
    last_call->print_last_call();
    last_call = &D;
    last_call->print_last_call();
    
}