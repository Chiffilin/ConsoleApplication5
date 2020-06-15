#include <iostream> 
#include <string> 
#include <fstream> 

using namespace std;

int* mas;

void fulfill(string text, int n) {
    string temp;
    for (int i = 0; i < n - 1; i++) {
        temp = text;
        temp.erase(temp.find(";"), temp.length() - temp.find(";"));
        mas[i] = stoi(temp);
        text.erase(0, text.find(";") + 1);
    }
    mas[n - 1] = stoi(text);
}

int main()
{
    ifstream ifs("input.txt");
    ifs.seekg(0, ifs.end);
    int length = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char* buffer = new char[length];
    ifs.read(buffer, length);
    ifs.close();
    string text = buffer;
    while (text.find("  ") < text.length()) {
        text.replace(text.find("  "), 2, " ");
    }
    int elem = 0;
    while (text.find(" ") < text.length()) {
        text.replace(text.find(" "), 1, ";");
        elem++;
    }
    elem++;
    mas = new int[elem];
    fulfill(text, elem);
    int i = 0, j, temp;
    while (i < elem) {
        for (j = 0; j < elem; j++) {
            if (i != j)
                if (mas[i] == mas[j]) {
                    for (int k = j; k < elem - 1; k++) {
                        mas[k] = mas[k + 1];
                    }
                    elem--;
                    i = 0;
                    break;
                }
        }
        i++;

    }
    cout << elem << endl;
    ofstream ofs("output.txt");
    for (int i = 0; i < elem; i++) {
        cout << mas[i] << " ";
        ofs << mas[i] << " ";
    }
    ofs.close();
    delete[] mas;
    return 0;
}