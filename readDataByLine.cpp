/**
���ж�ȡ���ݣ����ڲ������������ݵĶ�ȡ������getline()���ж�ȡ�ַ�����������stringstream�ָ��ַ���
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// ���ո񻮷��ַ���
void readDataBySpace()
{
    int N;
    cin >> N;
    string lineString;
    int value;
    vector<vector<int>> data;
    while (!cin.eof())
    {
        vector<int> line;
        getline(cin, lineString);
        stringstream inStream(lineString);
        while (inStream >> value)
        {
            line.push_back(value);      
        }
        data.push_back(line);
    }

    /*for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }*/
}

// �����Ż����ַ���
void readDataByComma()
{
    string lineString;
    int value;
    vector<vector<int>> data;
    while (!cin.eof())
    {
        vector<int> line;
        getline(cin, lineString);
        stringstream inStream(lineString);
        string token;
        //���ַ�����','�ֳ�һϵ���Ӵ�
        while (getline(inStream, token, ','))   
        {
            value = stoi(token);
            line.push_back(value);     
        }
        data.push_back(line);
    }
}

//���ж�ȡ�ļ�����
int readFile(string filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cout << "fail to open the file" << endl;
        return -1;
    }

    int value;
    string lineString;
    vector<vector<int>> data;
    while (!infile.eof())
    {
        vector<int> line;
        getline(infile, lineString);
        istringstream inString(lineString);
        while (inString >> value)
            line.push_back(value);

        data.push_back(line);
    }

    /*for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }*/
}

/**************************************************************************/
//����ȡ��һ���ַ�����Ҫ��ֿ���ת��Ϊ������
void splitData(vector<int>& lineData, const string& lineString, char tag)
{
    int length = lineString.length();
    int start = 0;
    for (int i = 0; i < length; i++)
    {
        if (lineString[i] == tag)
        {
            string sub = lineString.substr(start, i - start);
            lineData.push_back(stoi(sub));
            start = i + 1;
        }
        else if (i == length - 1)
        {
            string sub = lineString.substr(start, i - start + 1); //���һ���ַ�û�б�㣬�赥������
            lineData.push_back(stoi(sub));
        }
    }
}

//���ж�ȡ����
void readData(vector<vector<int>>& group, int N)
{
    string lineString;
    for (int i = 0; i < N; i++)
    {
        vector<int> lineData;
        getline(cin, lineString);
        cout << lineString << endl;
        splitData(lineData, lineString, ' ');
        group.push_back(lineData);
    }
}

void readDataSelf()
{
    int N = 1;
    cin >> N;
    getchar(); //��ȡ�س���������������뻺������Ӱ��������ݵĶ�ȡ
    vector<vector<int>> group;
    readData(group, N);
}

/*************************************************************************/
int main()
{
    //readDataBySpace();
    readDataByComma();
    //readFile("data.txt");
    system("pause");
    return 0;
}