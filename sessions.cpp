/*******************************************************************************
 *
 * ivs_sessions.cpp; Created by Jon Leithe
 * Date: 21/8-2024
 *
 *
 *
*******************************************************************************/
//#pragma GCC diagnostic ignored "-Wunused-variable" ivs
//#pragma GCC diagnostic ignored "-Wunused-but-set-variable" inputFileNameSet

#include <string>
#include <iostream>

#include <getopt.h>

//#include "fileexists.h"
#include "ivsSessions.h"



// main program
int main(int argc, char **argv)
{
	////////////////////////////////////////////////////////////////////////////
	// getopt()-variables
	int		c, optionIndex;

	char	*shortOptions = (char*)"i:h";
	struct option	longOptions[] = {
		{"input-file",	required_argument,	NULL,	'i'},
		{"help",		no_argument,		NULL,	'h'},
		{0, 0, 0, 0}
	};
	// end of getopt()-variables
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	//
	// filename variables
	//
	std::string	inputFileName;
	bool		inputFileNameSet;
	////////////////////////////////////////////////////////////////////////////


	// getopt() switch statement
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'i':	inputFileName		= optarg;
						inputFileNameSet	= true;
						break;

			case 'h':	{
							std::cout << "main(): Provide something useful to the user!" << std::endl;
							exit(0);
						}
			default:	{
							std::cout << "main: Switch default\n" << std::endl;
							break;
						}
				} //end of getopt() switch statement
	} // end of while-loop


	if(inputFileNameSet){
		ivsSessions *s = new ivsSessions(inputFileName);

		if(!s)
			exit(1);

		s->run();
	}

	else{
		std::cout << "No input filename given, nothing to do..." << std::endl;
	}


	//*************************************************************************

    return(0);
}

