#include <iostream>
#include <stdio.h>
#include <direct.h>
#include "pch.h"

using namespace std;

//переименование файла
void RenameDirectory() {
	string oldName, newName; //старое и новое имя файла
	cout << "Enter old name:";
	cin >> oldName;
	cout << "Enter new name:";
	cin >> newName;
	if (rename(oldName.c_str(), newName.c_str()) != 0)
		cout << "Error!\n Couldn't rename directory. Check old and mew filename...\n";
	else
		cout << "Ok...\n";
}
//удаление файла
void RemoveDirectory() {
	string Name;
	cout << "Enter name:";
	cin >> Name;
	if (_rmdir(Name.c_str()) != 0) {
		cout << "Error!\n Couldn't remove directory. \n";
	}
	else {
		cout << "Ok...\n";
	}
}
//вывести список файлов по маске
void CreateDir() {
	string Name;
	cout << "Enter name:";
	cin >> Name;
	if (_mkdir(Name.c_str()) != 0) {
		cout << "Error!\n Couldn't creat directory. Check filename...\n";
	}
	else {
		cout << "Ok...\n";
	}
}
	
int main() {
	cout << "Enter operation number\n";
	char op;
	do {
		cout << "\n1 - Rename\n"
			<< "2 - Remove\n"
			<< "3 - View file list\n"
			<< "0 - exit\n";
		cin >> op;
		switch (op) {
		case '1':
			RenameDirectory();
			break;
		case '2':
			RemoveDirectory();
			break;
		case '3':
			CreateDir();
		}
	} while (op != '0');	
	return 0;
}

