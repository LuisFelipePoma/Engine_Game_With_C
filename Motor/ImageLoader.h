#pragma once
#include "GLTexture.h"
#include "IOManager.h"
#include "Error.h"
#include <string>

using namespace std;


class ImageLoader
{
	static GLTexture loadPNG(string filePath);
};

