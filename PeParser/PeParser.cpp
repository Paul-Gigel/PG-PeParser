﻿// PeParser.cpp: Definiert den Einstiegspunkt für die Anwendung.
//
#pragma once
#define _call // use standart calling convention, that is __thiscall
#include "Declarations.h"
#include <Windows.h>
using namespace std;

int main()	{
	typedef PEParserNamespace::PEParser PEParser;
	PEParser peparser;
	char fileNamee[UINT16_MAX] = "C:/NeuerOrdner(2)/depends.exe";
	cout <<
		PEParserNamespace::openFile<const char*>(fileNamee, &peparser).hFile
		<<endl;
	cout <<
		PEParserNamespace::getFileSize<>(&peparser).dwFileSize
		<< endl;
	PEParserNamespace::allocMemory<>(&peparser);
	PEParserNamespace::readFile<>(&peparser);
	PEParserNamespace::getImageHeaders<>(&peparser);
	PEParserNamespace::checkHeader<>(&peparser);
	PEParserNamespace::getSection<>(&peparser, (const unsigned char*)".data");
	std::cout << std::endl;
	PEParserNamespace::getSection<>(&peparser, (const unsigned char*)"dataas");
	std::cout << std::endl;
	if (peparser.failed) {
		std::cout << "not found\n";
	}
	PEParserNamespace::getSection<>(&peparser, (const unsigned char*)".text");
	std::cout << std::endl;
	PEParserNamespace::getSection<>(&peparser, (BYTE)0);
	std::cout << std::endl;
	PEParserNamespace::getDataDirectoryEntry<>(&peparser, (BYTE)IMAGE_DIRECTORY_ENTRY_IMPORT);
	std::cout << std::endl;
	if (peparser.failed)	{
		std::cout << "not found\n";
	}
	HINSTANCE NTDLL;
	NTDLL = PEParserNamespace::PEParserLoadNTDLL();
	std::cout << NTDLL<<"\n";
	PEParserNamespace::peb;
	std::wcout << PEParserNamespace::peb->ProcessParameters->ImagePathName.Buffer << "\n";
	//std::cout <<"SecVSize  "<<PEParserNamespace::SecVSize(peparser.pSecH) << std::endl;
	return 0;
}
//test test