#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ arg)
{
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Naves_MyForm::MyForm());
}