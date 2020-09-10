// TestCppApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FileManager.h"

using namespace std;

int main()
{
	try
	{
		string file;
		cout << "Enter the fullpath of the image to filter:" << endl;
		getline(cin, file);

		if (_access(file.c_str(), 0) == 0) {
			FileManager FiMg(file);
			FiMg.ApplySobel();
			FiMg.ShowDstImage();
			waitKey(0);
		}
		else
			cout << "File [" + file +"] doesn't exist!" << endl;

		return EXIT_SUCCESS;
	}
	catch (const std::exception&)
	{
		throw;
	}	
}

