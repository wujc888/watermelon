#include "file.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>
using namespace std;
tuple<int, int, string> d1;
bool File::checkFileOnDesktop(const string& fileName) {
    char desktopPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
       string filePath = desktopPath;
       filePath += "\\";
       filePath += fileName;
       ifstream file(filePath);
       if (file) {
          file.close();
          return true;
       }
    }
    return false;
}
bool File::isFileEmpty(const string& fileName) {
    ifstream file(fileName);
    char desktopPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
       string filePath = desktopPath;
       filePath += "\\";
       filePath += fileName;
       ifstream file(filePath);
    if (file.is_open()) {
        string line;
        // 尝试读取一行内容，如果读取成功，说明文件不为空
        if (getline(file, line)) {
            file.close();
            return false;
        }
        file.close();
        return true;
    }
}
}
void File::writeDataToDesktop(int data,int data2,string userName, const string& fileName) {
    // 用于存储桌面路径的缓冲区
    char desktopPath[MAX_PATH];
    // 获取桌面路径
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
        // 拼接完整的文件路径
        string filePath = desktopPath;
        filePath += "\\";
        filePath += fileName;
        ofstream outFile(filePath);
        if (outFile) {
            outFile << data << " ";
            outFile << data2 << endl;
            outFile << userName; 
            outFile.close();
        }
    }
}

// 从桌面文件读取数据并输出的函数
tuple<int, int, string> File::readDataFromDesktop(const string& fileName) {
	int r1,r2;
    string u;
    char desktopPath[MAX_PATH];
    // 获取桌面路径
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
        // 拼接完整的文件路径
        string filePath = desktopPath;
        filePath += "\\";
        filePath += fileName;
        ifstream inFile(filePath);
        if (inFile) 
		{
            inFile >> r1;
            inFile >> r2;
            inFile >> u;
            inFile.close();
        } 
    }
    d1=make_tuple(r1,r2,u);
    return d1;
}
// 提前在桌面上创建文件的函数
void File::createFileOnDesktop(const string& fileName) {
    // 用于存储桌面路径的缓冲区
    char desktopPath[MAX_PATH];
    // 获取桌面路径
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
       // 拼接完整的文件路径
       string filePath = desktopPath;
       filePath += "\\";
       filePath += fileName;
       ofstream file;
       file.open(filePath);
       if (file) {
          // 文件创建成功，关闭文件流
          file.close();
       } 
    }
}
