// test2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

int main()
{
    char buffer[] = "5";
    char answer;
	answer = 'a' + (buffer[0] - 'A');
    cout << answer;

}

