﻿#include <iostream>
#include "func.h"


int main(int argc, char* argv[])
{
    archive ARCH;
    ARCH.set_work(argc);
    if (!ARCH.get_work()) {
        return 0;
    }
    ARCH.set_name_func(argv[1]);
    if (ARCH.get_name_func() == "--compress") {
        ARCH.set_name_in(argv[3]);
        ARCH.set_name_out(argv[2]);
		ARCH.init_dict();
		ARCH.read_data();
        ARCH.com_out();
		ARCH.compress();
    }
    else if(ARCH.get_name_func() == "--decompress"){
		ARCH.set_name_in(argv[2]);
		ARCH.init_dict();
		ARCH.read_data_2();
		ARCH.decom_out();
		ARCH.decompress();
    }
   
}
