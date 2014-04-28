#include "aron.h"

int pause_game(int gracz, Player *p1, Player *p2)
{
	BITMAP* bufor = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGTH);
	BITMAP* bufor2 = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGTH);
	blit(screen, bufor, 0 ,0, 0, 0, screen->w, screen->h);
	blit(screen, bufor2, 0 ,0, 0, 0, screen->w, screen->h);

	while(TRUE)
	{
		clear_key();
		keypressed();

		if(key[KEY_ENTER])
			break;

		//rysuj_obramowanie(bufor, p1, p2);

		textprintf_centre_ex(bufor, font, SCREEN_W/2, 259,
		   makecol(255, 0, 0), makecol(0, 0, 0), "Wstrzymanie gry");

		blit(bufor, screen, 0 ,0, 0, 0, bufor->w, bufor->h);

#ifdef PSP
		if(key[KEY_RSHIFT])
		{
			thid = sceKernelCreateThread("Screenshotpsp", screenshotpsp,
			   0x11, 256 * 1024, PSP_THREAD_ATTR_USER, NULL);
			sceKernelStartThread(thid, 0, NULL);
		}
#else
		if(key[KEY_M])
		{
			screenshot();
		}
#endif

		rest(30);
	}

	blit(bufor2, screen, 0 ,0, 0, 0, bufor2->w, bufor2->h);
	destroy_bitmap(bufor2);
	destroy_bitmap(bufor);

	return 0;
}
