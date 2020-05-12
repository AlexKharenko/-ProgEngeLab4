#include <iostream>
#include "func.h"


int main(int argc, char* argv[])
{
    archive ARCH;
    ARCH.set_work(argc);
    if (!ARCH.get_work()) {
        return 0;
    }
    ARCH.set_name_func(argv[1]);
    ARCH.set_name_in(argv[2]);
    ARCH.set_name_out(argv[3]);
    ARCH.out_f_in_out();
}
