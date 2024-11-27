#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <sstream>
#include <string>
#include "../pr11.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        void CreateTestFile(const char* fname, const string& content) {
            ofstream fout(fname);
            fout << content;
            fout.close();
        }

        TEST_METHOD(TestPrintTXT)
        {
            // ��������� ��������� �����
            const char* fname = "t1_test.txt";
            string fileContent = "Hello, world!\nThis is a test file.\n";
            CreateTestFile(fname, fileContent);

            // ��������������� ������ � stringstream
            stringstream testOutput = PrintTXT(const_cast<char*>(fname));

            // ���������� ���������
            string expectedOutput = "Hello, world!\nThis is a test file.\n\n";

            // �������� ����������
            Assert::AreEqual(expectedOutput, testOutput.str());
        }
    };
}
