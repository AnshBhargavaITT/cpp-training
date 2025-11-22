#include <iostream>

enum tags {
    stop,  
    start  
};

#define MACRO start
#define start 1

int main() {
    #if MACRO
    {
        std::cout << "hello\n";
    }
    #endif

    std::cout << "Hello World\n";

    return 0;
}
