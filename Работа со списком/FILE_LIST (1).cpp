#include <iostream>
#include <filesystem>
#include <io.h>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s, char delim) {
    vector<string>elems;
    string current; //текущий кусок строки
    size_t index = 0; //текущий индекс
    while (index < s.size()) {
        if (s[index] != delim) {
            current += s[index];
        }
        else {
            if (!current.empty()) elems.push_back(current);
            current = "";
        }
        index++;
    }
    if (!current.empty())
        elems.push_back(current);

    return elems;
}



void showDir(string path) {
    string fpath = path + "\\*.*";
    _finddata_t* fileinfo = new _finddata_t();
    long done = _findfirst(fpath.c_str(), fileinfo);
    int MayWeWork = done;
    while (MayWeWork != -1) {
        if (strcmp(fileinfo->name, ".") && strcmp(fileinfo->name, ".."))
            cout << fileinfo->name << (fileinfo->attrib & _A_SUBDIR ? "Folder" : "File") << '\n';
    }
    MayWeWork = _findnext(done, fileinfo);
}
    _findclose(done);
    delete fileinfo;
    cout << '\n';
}

int main()
{
    //текущий путь(начиная с пути исполняемого файла)
    string path = filesystem::current_path().string();
    string action;//команда
    showDir(path);
    bool flag = true;//флаг продолжения цикла
    do {
        getline(cin, action);
        if (action == "root") {
            path = filesystem::path(path).root_path().string();
            showDir(path);
        }
        else if (action == "exit") {
            flag = false;

        }
        else if (action.substr(0, 2) == "cd") {//если команда cd
            auto params = split(action, ' ');
            if (params.size() == 1) {//если cd без параметров
                showDir(path);
            }
            else if (params[1] == ".") {//хотим посмотреть текущую папку
                showDir(path);
            }
            else if (params[1] == "..") {//в родительскую папку
                path = filesystem::path(path).parent_path().string();
                showDir(path);
            }
            else if (filesystem::path(params[1]).has_root_path()) {
                path = params[1];
                showDir(path);
            }
            else {
                path += "\\" + params[1];
                showDir(path);
            }
        }
    } while (flag);
}