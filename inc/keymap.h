/*
 * keymap.h
 *
 *  Created on: 2 Nov 2024
 *      Author: jole
 */

#ifndef KEYMAP_H_
#define KEYMAP_H_

enum KEYMAP{
	TAB			= 9,
	NUM_ENTER	= 10,
	KB_ENTER	= 13,
	ESC			= 27,
	BK_SP		= 127,
	// These needs to be user defined, since they return regular characters
	UP_ARROW	= 1000,
	DOWN_ARROW,
	RIGHT_ARROW,
	LEFT_ARROW,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	HOME,
	INSERT,
	DELETE,
	END,
	PAGE_UP,
	PAGE_DOWN
};

#endif /* KEYMAP_H_ */
