#include "pch.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "SimpleSerial.h"
#include <sstream>

using namespace System;


SimpleSerial Serial("\\\\.\\COM6", CBR_115200); // Inicjalizacja obiektu SimpleSerial z ustawieniami portu szeregowego


// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::Form1());
  return 0;
}

