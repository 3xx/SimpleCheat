#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    int Of_Health = 0x0;//offest
    int Ad_Health = 0x0;//Address
    int wr_Hleath = 1337;//value
    DWORD health = (DWORD)(Ad_Health + Of_Health);
    HWND hwnd = FindWindowA(NULL, "NameWindowGame");
    if (hwnd == NULL)
    {
        cout << "Cannot Find Game !";
        Sleep(300);
        exit(-1);
    }
    else
    {
        DWORD procID;
        GetWindowThreadProcessId(hwnd, &procID);
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
        if (procID == NULL)
        {
            cout << "Cannot obtain Process !";
            Sleep(300);
            exit(-1);
        }
        else
        {
            for (;;)
            {
                WriteProcessMemory(handle, (PBYTE*)health, &wr_Hleath, sizeof(wr_Hleath), 0);
                Sleep(1000);
            }
        }

    }


}
