#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintTXT(char* fname) // ��������� ����� �� �����
{
    ifstream fin(fname); // ������� ���� ��� ����������
    string s; // ���������� �����
    while (getline(fin, s)) // ���� ����� ��������� �����
    {
        cout << s << endl; // �������� ���� �� �����
    }
    cout << endl;
}



void removeFromFile(char* fname1, char* fname2) {
    fstream f1(fname1);
    fstream f2(fname2);
    string s;
    string result;

    int openParenthesesCount = 0; // ˳������� �������� �����
    int parenthesesBalance = 0;  // ������ ����� (������ - ������)
    while (f1 >> s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') parenthesesBalance++;   // �������� ��� ������� �����
            if (s[i] == ')') parenthesesBalance--;   // �������� ��� ������� �����
        }

        // ���� ������ ����� �� ��������, ����� �����������, ����� �� �������
        if (parenthesesBalance != 0) {
            result = s;
        }
        else {
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '(') {
                    // ���� ������� ������� �����, �������� ��������
                    openParenthesesCount++;
                }
                else if (s[i] == ')') {
                    // ���� ������� ������� �����, �������� ��������
                    if (openParenthesesCount > 0) {
                        openParenthesesCount--;
                    }
                }
                else if (openParenthesesCount == 0) {
                    // ������ ������ �� ����������, ���� �� �� �� �������
                    result += s[i];
                }
            }
        }
        f2 << result << endl;
        result = "";
    }

}

int main() {
	char fname1[7] = "t1.txt";
    char fname2[7] = "t2.txt";

    PrintTXT(fname1);

    removeFromFile(fname1, fname2);

    PrintTXT(fname2);

	return 0;
}