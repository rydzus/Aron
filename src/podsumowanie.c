#include "aron.h"

int podsumowanie(int gracz, Player *p1, Player *p2)
{
	BITMAP* bufor = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGTH);
	int aktywny = 1;

	if(gracz == 2)
		p1->wins++;
	else if(gracz == 1)
		p2->wins++;

	while(TRUE)
	{


		if(key[KEY_ENTER])
			break;

		rysuj_obramowanie(bufor, p1, p2);

		if(gracz == 0 || gracz == -1)
			textprintf_centre_ex(bufor, font, SCREEN_W/2, 86, makecol(255, 255, 255),
			   makecol(0, 0, 0), "Remis");
		else
		{
			if(gracz == 1)
				textprintf_centre_ex(bufor, font, SCREEN_W/2, 86, makecol(255, 255, 255),
				   makecol(0, 0, 0), "2 gracz wygral!");
			else
				textprintf_centre_ex(bufor, font, SCREEN_W/2, 86, makecol(255, 255, 255),
				   makecol(0, 0, 0), "1 gracz wygral!");
		}

		if(aktywny == 1)
			textprintf_centre_ex(bufor, font, SCREEN_W/2, 160, makecol(255, 0, 0),
			   makecol(0, 0, 0), "Kontynuuj rozgrywke");
		else
			textprintf_centre_ex(bufor, font, SCREEN_W/2, 160, makecol(255, 255, 255),
			   makecol(0, 0, 0), "Kontynuuj rozgrywke");

		if(aktywny == 2)
			textprintf_centre_ex(bufor, font, SCREEN_W/2, 180, makecol(255, 0, 0),
			   makecol(0, 0, 0), "Zakoncz rozgrywke");
		else
			textprintf_centre_ex(bufor, font, SCREEN_W/2, 180, makecol(255, 255, 255),
			   makecol(0, 0, 0), "Zakoncz rozgrywke");

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

		if(key[KEY_UP])
		{
			aktywny = 1;
		}
		else if(key[KEY_DOWN])
		{
			aktywny = 2;
		}
#if PSP
		clear_key();
		keypressed();
#else
		readkey();
#endif

		rest(30);
	}

	destroy_bitmap(bufor);

	return aktywny;
}
