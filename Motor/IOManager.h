#pragma once
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class IOManager
{
public:
	static bool readFiletoBuffer(string filePath, vector<unsigned char>& buffer);
};

