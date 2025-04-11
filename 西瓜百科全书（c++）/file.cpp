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
        // ���Զ�ȡһ�����ݣ������ȡ�ɹ���˵���ļ���Ϊ��
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
    // ���ڴ洢����·���Ļ�����
    char desktopPath[MAX_PATH];
    // ��ȡ����·��
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
        // ƴ���������ļ�·��
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

// �������ļ���ȡ���ݲ�����ĺ���
tuple<int, int, string> File::readDataFromDesktop(const string& fileName) {
	int r1,r2;
    string u;
    char desktopPath[MAX_PATH];
    // ��ȡ����·��
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
        // ƴ���������ļ�·��
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
// ��ǰ�������ϴ����ļ��ĺ���
void File::createFileOnDesktop(const string& fileName) {
    // ���ڴ洢����·���Ļ�����
    char desktopPath[MAX_PATH];
    // ��ȡ����·��
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath))) {
       // ƴ���������ļ�·��
       string filePath = desktopPath;
       filePath += "\\";
       filePath += fileName;
       ofstream file;
       file.open(filePath);
       if (file) {
          // �ļ������ɹ����ر��ļ���
          file.close();
       } 
    }
}
