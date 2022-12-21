#include <stdio.h>

#include "header.h"

// Ukuran layar
HWND WINAPI GetConsoleWindowNT(void)
{
    //mendeklarasikan modul fungsi dengan tipe pointer
    typedef HWND WINAPI(*GetConsoleWindowT)(void);

    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;

    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));

    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib, TEXT("GetConsoleWindow"));

    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    
    //call the undocumented function
    return GetConsoleWindow();
}