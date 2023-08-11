#include <iostream>

int main()
{
    std::cout << "building...\n";
    mkdir("C:/gib");
    mkdir("C:/gib/boxes");
    std::cout << "done";
    return 0;
}
