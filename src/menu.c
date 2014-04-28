#include "aron.h"

int menu()
{
	BITMAP* tlo = load_bmp("grafika/tlo.bmp", default_palette);
	BITMAP* graczvspsp = load_bmp("grafika/graczvspsp.bmp", default_palette);
	BITMAP* graczy2 = load_bmp("grafika/2graczy.bmp", default_palette);
	BITMAP* wyjscie = load_bmp("grafika/wyjscie.bmp", default_palette);
	BITMAP* bufor = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGTH);

	clear_to_color(screen, makecol(0, 0, 0));
	clear_to_color(bufor, makecol(0, 0, 0));

	static int aktywny = 1;
	minspeed = 9;

	while(TRUE)
	{
		if(key[KEY_ENTER])
			break;

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
			if(aktywny-1 >= 1)
				aktywny--;
		}
		else if(key[KEY_DOWN])
		{
			if(aktywny+1 <= 3)
				aktywny++;
		}
#ifdef PSP
		else if(key[KEY_LSHIFT])
#else
		else if(key[KEY_N])
#endif
		{
			if(minspeed == 9)
			{
				minspeed = 5;
			}
			else if(minspeed == 5)
			{
				minspeed = 0;
			}
		}

		//clear_keybuf();
		blit(tlo, bufor, 0, 0, 0, 0, tlo->w, tlo->h);

		if(aktywny == 1)
			blit(graczvspsp, bufor, 0, 0, 140, 139, tlo->w, tlo->h);
		else if(aktywny == 2)
			blit(graczy2, bufor, 0, 0, 167, 184, tlo->w, tlo->h);
		else if(aktywny == 3)
			blit(wyjscie, bufor, 0, 0, 205, 232, tlo->w, tlo->h);

		if(minspeed == 5)
			textprintf_ex(bufor, font, 0, 0,
			   makecol(255, 0, 0), -1, "Tryb gry: szybki");
		else if(minspeed == 0)
			textprintf_ex(bufor, font, 0, 0,
				   makecol(255, 0, 0), -1, "Tryb gry: bardzo szybki");

		blit(bufor, screen, 0, 0, 0, 0, tlo->w, tlo->h);

#if PSP
		clear_key();
		keypressed();
#else
		readkey();
#endif
	}

	destroy_bitmap(tlo);
	destroy_bitmap(graczy2);
	destroy_bitmap(wyjscie);
	destroy_bitmap(bufor);

	return aktywny;
}
