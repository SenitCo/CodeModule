/**
按行读取数据，用于不定长输入数据的读取，借助getline()逐行读取字符串，再利用stringstream分割字符串
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// 按空格划分字符串
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

// 按逗号划分字符串
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
        //将字符串按','分成一系列子串
        while (getline(inStream, token, ','))   
        {
            value = stoi(token);
            line.push_back(value);     
        }
        data.push_back(line);
    }
}

//按行读取文件内容
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
//将读取的一行字符串按要求分开并转换为整型数
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
            string sub = lineString.substr(start, i - start + 1); //最后一个字符没有标点，需单独处理
            lineData.push_back(stoi(sub));
        }
    }
}

//按行读取数据
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
    getchar(); //读取回车符，否则会在输入缓存区中影响后面数据的读取
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