#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

#ifdef _WIN64
    const char* rootDir = "C:";
#elif _WIN32
    const char* rootDir = "C:";
#else
    const char* currentOS = "";
#endif

using namespace std;

const string readError = "Error: could not read the file";

void Write(string path, string whatToWrite, ofstream &pathWriter){
    pathWriter.open(path, ios::out);
    if(pathWriter.is_open()){
        pathWriter << whatToWrite;
    }
    pathWriter.close();
}

string Read(string path){
    string content;
    ifstream pathReader;
    pathReader.open(path, ios::in);
    if(pathReader.is_open()){
        stringstream contentBuffer;
        contentBuffer << pathReader.rdbuf();
        content = contentBuffer.str();
    }
    else{
        content = readError;
    }
    pathReader.close();

    return content;
}

void Save(string path, string boxPath, string saveName)
{
    string iFileContent;
    if(Read(path) != readError){
        iFileContent = Read(path);
        ofstream savedFile;
        Write(boxPath+"/"+saveName+".txt", iFileContent, savedFile);
    }
    else{
        cerr << readError;
    }
}

void Load(string initialFilePath, string boxPath, string whatToLoad){
    ofstream writer;
    Write(initialFilePath, whatToLoad, writer);
}

int main(int argc, char *argv[])
{
    const string commands[] = {
        "new",
        "save",
        "load"
    };

if(filesystem::exists(rootDir+(std::string)"/gib")){
    string command = argv[1];
    string boxDirectoryName = (string)argv[2];
    string boxDirectoryPath = rootDir+(std::string)"/gib/boxes/"+boxDirectoryName;

    if(command == commands[0]){
        string filePath = argv[3];
        filesystem::create_directory(boxDirectoryPath);
        ofstream pathSave;
        Write(boxDirectoryPath+"/pathSave.txt", filePath, pathSave);
        Save(filePath, boxDirectoryPath, "start");
    }
    else if(command == commands[1]){
        string saveName = argv[3];
        string filePathSave = boxDirectoryPath+"/pathSave.txt";
        string path;
        if(Read(filePathSave) != readError){
            path = Read(filePathSave);
            Save(path, boxDirectoryPath, saveName);
        }
        else{
            cerr << readError;
        }
    }
    else if(command == commands[2]){
        string saveToLoad = boxDirectoryPath+"/"+argv[3]+".txt";
        string load;
        string filePathSave = boxDirectoryPath+"/pathSave.txt";
        string iFilePath;
        if(Read(filePathSave) != readError){
            iFilePath = Read(filePathSave);
            load = Read(saveToLoad);
            Load(iFilePath, boxDirectoryPath, load);
        }
        else{
            cerr << readError;
        }
    }
    else{
        cerr << "Please enter a valid command";
    }
}
else{
    cerr << "Please first build gib using build.exe\n";
}
}
