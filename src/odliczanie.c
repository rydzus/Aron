#include "aron.h"

void odliczanie()
{
	BITMAP* bufor = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGTH);

	blit(screen, bufor, 0, 0, 0, 0, screen->w, screen->h);

	int licznik = 3;

	while(licznik != 0)
	{
		textprintf_centre_ex(screen, font, SCREEN_W/2, 136,
		   makecol(173, 216, 230), makecol(0, 0, 0), "%d", licznik);
		rest(300);
		licznik--;
	}

	blit(bufor, screen, 0, 0, 0, 0, bufor->w, bufor->h);
	destroy_bitmap(bufor);
}
