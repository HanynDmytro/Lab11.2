#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintTXT(char* fname) // виведення файлу на екран
{
    ifstream fin(fname); // відкрили файл для зчитування
    string s; // прочитаний рядок
    while (getline(fin, s)) // поки можна прочитати рядок
    {
        cout << s << endl; // виводимо його на екран
    }
    cout << endl;
}



void removeFromFile(char* fname1, char* fname2) {
    fstream f1(fname1);
    fstream f2(fname2);
    string s;
    string result;

    int openParenthesesCount = 0; // Лічильник відкритих дужок
    int parenthesesBalance = 0;  // Баланс дужок (відкриті - закриті)
    while (f1 >> s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') parenthesesBalance++;   // Збільшуємо для відкритої дужки
            if (s[i] == ')') parenthesesBalance--;   // Зменшуємо для закритої дужки
        }

        // Якщо баланс дужок не нульовий, рядок некоректний, нічого не змінюємо
        if (parenthesesBalance != 0) {
            result = s;
        }
        else {
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '(') {
                    // Якщо зустріли відкриту дужку, збільшуємо лічильник
                    openParenthesesCount++;
                }
                else if (s[i] == ')') {
                    // Якщо зустріли закриту дужку, зменшуємо лічильник
                    if (openParenthesesCount > 0) {
                        openParenthesesCount--;
                    }
                }
                else if (openParenthesesCount == 0) {
                    // Додаємо символ до результату, якщо він не між дужками
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