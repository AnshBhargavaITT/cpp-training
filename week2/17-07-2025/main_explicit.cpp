#include <iostream>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./libadd.so", RTLD_LAZY);
    if (!handle) {
        std::cout << "Failed to load library\n";
        return 1;
    }

    int (*add)(int, int) = (int (*)(int, int))dlsym(handle, "add");
    if (!add) {
        std::cout << "Failed to get symbol\n";
        dlclose(handle);
        return 1;
    }

    std::cout << "Result: " << add(3, 4) << std::endl;

    dlclose(handle);
    return 0;
}
