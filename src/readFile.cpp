/*
 * readFile.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <iostream>
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// If opening the file results in an error, this function writes an error
// message to stderr and exits the program.
//
// Upon successfull opening, ivsSessions::readfile reads the entire content of
// inputfile into memory. It is stored in str_inputBuffer for later processing.
//
// ivsSessions::readfile closes the filestream upon completion
//
// It has no return value
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::readFile(void)
{
	char	c;

	// open input file, position the fp at the end
	fs_inputFileStream.open(str_inputFileName, std::ios::ate);

	//	if file is not open, flag an error and exit
	if(!fs_inputFileStream.is_open()){
		errorMessage("readfile() ", "Error opening inputfile " + str_inputFileName);

	}
	else{
		// get filesize and store it in object variable
		//std::cout << "fileoperations(): inputFile.tellg(): " << fo_inputFileStream.tellg() << std::endl;
		sp_inputFileSize = fs_inputFileStream.tellg();
		// After getting the filesize, set file pointer at beginning of file
		fs_inputFileStream.seekg(0, std::ios::beg);
	}

	// seek to start of input file
	fs_inputFileStream.seekg(0, std::ios::beg);
	if(fs_inputFileStream.tellg() != 0){
		errorMessage("readfile() ", "Error searching inputfile " + str_inputFileName);
	}

	// read the whole file to memory
	while(fs_inputFileStream.get(c).good()){
		str_inputBuffer.append(1, c);
	}

	// close the file stream as we are done reading!
	if(fs_inputFileStream.is_open())
		fs_inputFileStream.close();

	// Return to caller
	return;
}
