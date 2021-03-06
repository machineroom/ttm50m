/*
 *	c011link.c
 *
 *	macihenroomfiddling@gmail.com
 */

#include <stdio.h>
#include <errno.h>
#include "linkio.h"
#include "linkops.h"
#include "c011.h"
#include <string.h>

typedef int LINK;

LINK
C011OpenLink(char *Name)
{
	c011_init();
    return 1;
}

int 
C011CloseLink(LINK LinkId)
{
    return SUCCEEDED;
}

int
C011ReadLink(LINK LinkId, char *Buffer, unsigned Count, int Timeout)
{
	int result;

	/* Read into buffer */
	result = c011_read_bytes( Buffer, Count, Timeout );
	if (result >= 0) {
	    return result;
	} else {
	    return ER_LINK_CANT;
	}
}

int
C011WriteLink(LINK LinkId, char *Buffer, unsigned Count, int Timeout)
{
	int result;
	result = c011_write_bytes (Buffer, Count, Timeout);
	if (result >= 0) {
	    return result;
	} else {
	    return ER_LINK_CANT;
	}
}

int
C011ResetLink(LINK LinkId)
{
    c011_reset();
    return SUCCEEDED;
}


int
C011AnalyseLink(LINK LinkId)
{
    c011_analyse ();
    return SUCCEEDED;
}


int
C011TestError(LINK LinkId)
{
    return ER_LINK_CANT;
}

int
C011TestRead(LINK LinkId)
{
    return ((c011_read_input_status() & 0x01) == 0x01);
}

int
C011TestWrite(LINK LinkId)
{
    return ((c011_read_output_status() & 0x01) == 0x01);
}



