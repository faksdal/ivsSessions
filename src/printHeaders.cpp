/*
 * printHeaders.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <iostream>
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Printing the headers to screen
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::printHeaders(void)
{
	print(1, d_bound.s_header1_row, d_colors.str_headerColor + str_header1);
	print(1, d_bound.s_header2_row, d_colors.str_headerColor + str_header2);
}
