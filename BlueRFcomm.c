#include "blueRFcomm.h"

int write(char message[10]) {
	int n_written = 0, spot = 0;

	do {
		n_written = write( USB, &message[spot], 1 );
		spot += n_written;
	} while (message[spot-1] != '\r' && n_written > 0);
}