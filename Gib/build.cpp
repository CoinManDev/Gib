#include <filesystem>
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
        std::filesystem::create_directory("C:/gib");
        std::filesystem::create_directory("C:/gib/boxes");
    }
    else{
        std::filesystem::create_directory("/gib");
        std::filesystem::create_directory("/gib/boxes");
    }
    std::cout << "done";
    return 0;
}
