#include <sys/stat.h>
#include <iostream>

#ifdef _WIN32
    bool inWindows = true;
#elif _WIN64
    bool inWindows = true;
#else
    bool inWindows = false;
#endif

int main()
{
    std::cout << "building...\n";
    if(inWindows){
        mkdir("C:/gib");
        mkdir("C:/gib/boxes");
    }
    else{
        mkdir("/gib");
        mkdir("/gib/boxes");
    }
    std::cout << "done";
    return 0;
}
