#define _CRT_SECURE_NO_WARNINGS
#define OS13HANDEL void*
#include <Windows.h>
#include <iostream>
#include "../OS13_HTCOM/Element.h"
#include "../OS13_HTCOM/HashTable.h"
#include "../OS13_HTCOMLIB/OS13.h"
using namespace std;


int main(int argc, char** argv)
{
	try
	{
		setlocale(LC_ALL, "Russian");
		cout << argv[1] << " " << argv[2] << " " << argv[3] << endl;
		/*cout << "filename: ";
		char filename[100];
		cin >> filename;*/
		OS13HANDEL h1 = OS13::Init();
		//HashTable::HTHANDLE* HT = OS13::HashTableLib::Open(h1, argv[1]);
		//HashTable::HTHANDLE* HT = OS13::HashTableLib::Open(h1, "D:\\1\\Lab_14\\OS13_CREATE\\10");
		HashTable::HTHANDLE* HT = OS13::HashTableLib::Open(h1, argv[1], argv[2], argv[3]);
		//HashTable::HTHANDLE* HT = OS13::HashTableLib::Open(h1,"D:\\1\\Lab_14\\Debug\\HashTable.ht","HTUser01","12345");
		if (HT == NULL) throw "Invalid handle";

		std::cout << "--- HT-Storage Started ---" << std::endl;
		std::cout << "filename: " << HT->FileName << std::endl;
		std::cout << "snapshotinterval: " << HT->Data.SecSnapshotInterval << std::endl;
		std::cout << "capacity: " << HT->Data.Capacity << std::endl;
		std::cout << "maxkeylength: " << HT->Data.MaxKeyLength << std::endl;
		std::cout << "maxdatalength: " << HT->Data.MaxPayloadLength << std::endl;
		std::cout << "UserGroup: " << HT->Data.HTUsersGroup << std::endl;

		std::cout << std::endl << "Press any key to close HT: ";
		char a;
		std::cin >> a;
		if (!OS13::HashTableLib::Snap(h1,HT)) throw "Error snap";
		if (!OS13::HashTableLib::Close(h1,HT)) throw "Error close";
		OS13::Dispose(h1);
	}
	catch (const char* error) { std::cout << "-- Error: " << error << std::endl; }
}