/*
 * fileexists.h
 *
 *  Created on: May 21, 2024
 *      Author: leijon
 */
#pragma once

#include <string>

#include <unistd.h>
#include <sys/stat.h>

bool fileexists(const std::string& name);

bool fileexists(const std::string& name)
{
	struct stat buffer;
	return(stat(name.c_str(), &buffer) == 0);
}
