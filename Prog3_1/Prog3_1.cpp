#include <iostream>
#include "Set.h"

using namespace Prog3_1;
const char* msgs[] = { " [0] Exit",
                       " [1] Set + Set",
                       " [2] Set + char",
                       " [3] Set * Set",
                       " [4] Set - Set",
                       " [5] Set message in set1 and set2",
                       " [6] Get message in set1 and set2\n"


};

const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int (*functions[])(Set&, Set&, Set&) = { nullptr, dialog_summ, dialog_summ_char, dialog_multiplication, dialog_subtraction, dialog_set_message, dialog_get_arr };

int main() {
    try {
        Set Set1("helLo"), Set2(" bay_BAY"), Set3;
        int rc;
        while ((rc = dialog(msgs, NMsgs))) {
            if (!functions[rc](Set1, Set2, Set3))
                break;
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}