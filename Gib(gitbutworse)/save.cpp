#include "save.h"

void Save(std::string path, std::string boxName)
{
    std::string iFileContent;
    std::ifstream initialFile;
    initialFile.open(path, std::ios::in);
    if(initialFile.is_open()){
        std::stringstream buffer;
        buffer << initialFile.rdbuf();
        iFileContent = buffer.str();
    }
    initialFile.close();

    std::string boxPath = "C:/gib/boxes/"+boxName;
    std::ofstream savedFile;
    savedFile.open(boxPath+"save.txt", std::ios::out);
    if(savedFile.is_open()){
        savedFile << iFileContent;
    }
    savedFile.close();
}
