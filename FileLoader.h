#ifndef FILELOAD_H_
#define FILELOAD_H_

#include "FileLoader.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

 /**
   * File loader header class
   * 
   * Loads in all functions possible as long as already has not been defined
   */
class FileLoader{

/**
   * Constructors and destructors
   * 
   * Parameterized constructor takes in a file and file type
   * @param string file name
   * @param char file type
   * 
   * Others are default unparameterized
   */
public:
	FileLoader();
	FileLoader(std:: string fileName,  char type);
	~FileLoader();
};
#endif
