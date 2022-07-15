#include <iostream>
#include <fstream>
#include "Print.h"

static std::string FilePath;
static std::string FilePath2;

bool FileExists(std::string File)
{
	std::ifstream myfile;
	myfile.open(FilePath);
	if (!myfile)
		return false;
	else
		return true;
}

void InstallPackages() {
	system("cls");
	Write("Installing Packages (Uncompyle6)", Success);
	system("pip install uncompyle6 >nul 2>&1");

	Write("Installing Packages (PyInstaller)", Success);
	system("pip install pyinstaller >nul 2>&1");

	Write("Installing Packages (Colorama)", Success);
	system("pip install colorama >nul 2>&1");

	Write("Installing Packages (Requests)", Success);
	system("pip install requests >nul 2>&1");
}

int main()
{
	std::cout << ShowCursor(false) << std::endl;
	system("cls");
	SetConsoleTitle(TEXT("PyDecompiler ~ By Vestige#0001"));

	Write("Input the Exe", Info);
	Write("", Input);
	std::getline(std::cin, FilePath);

	bool Exists = FileExists(FilePath);
	if (Exists) {
		InstallPackages();

		system("cls");
		system(("py Utils\\Unpacker.py " + FilePath + " >nul 2>&1").c_str());

		Write("Input the .pyc File", Info);
		Write("", Input);
		std::getline(std::cin, FilePath2);

		system("cls");
		system(("Utils\\Decompiler.exe " + FilePath2).c_str());

		Sleep(-1);
	}
	else { main(); }
}