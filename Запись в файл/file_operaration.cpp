#include <iostream>
#include <stdio.h>
#include <io.h>

using namespace std;

//переименование файла
void renameFile() {
	string oldName, newName; //старое и новое имя файла
	cout << "Enter old name:";
	cin >> oldName;
	cout << "Enter new name:";
	cin >> newName;
	if (rename(oldName.c_str(), newName.c_str()) != 0)
		cout << "Error!\n Couldn't rename file. Check old and mew filename...\n";
	else
		cout << "Ok...\n";
}
//удаление файла
void RemoveFile() {
	string Name;
	cout << "Enter name:";
	cin >> Name;
	if (remove(Name.c_str()) != 0) {
		cout << "Error!\n Couldn't remove file. Check filename...\n";
	}
	else {
	cout << "Ok...\n";
    }
}
//вывести список файлов по маске
void Dir() {
	string path; // путь к папке
	cout << "Enter full path (for example, C:\\):";
	cin >> path;
	string mask;
	cout << "Enter mask (for example, *.txt):";
	cin >> mask;
	path += "\\"+mask;
	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst(path.c_str(), fileinfo);
	int MayMeWork = done;
	size_t count = 0;
	while (MayMeWork != -1) {
		count++;
		cout << fileinfo->name << '\t'<< fileinfo->size << "b\n";
		MayMeWork = _findnext(done, fileinfo);
	}
	cout << "Infomation:was found " << count << "file(s) in folder \"" << path << "\"\n";
	_findclose(done);
	delete fileinfo;
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
			renameFile();
			break;
		case '2':
			RemoveFile();
			break;
		case '3':
			Dir();
		}
	} while (op != '0');

	return 0;
}