#ifndef FILE_H
#define FILE_H
#include <bits/stdc++.h>
using namespace std;
class File
{
	public:
	void createFileOnDesktop(const string& fileName);
	void writeDataToDesktop(int data,int data2, string userName, const string& fileName);
	tuple<int, int, string> readDataFromDesktop(const string& fileName);
	bool checkFileOnDesktop(const string& fileName);
	bool isFileEmpty(const string& fileName);
};

#endif
