/** 
 * Autor gry: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * Gra na licencji GPL v3
 */

#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

#include <allegro.h>

#include "aron.h"


void init_allegro();
void deinit_allegro();


int main(int argc, char *argv[])
{
	init_allegro();
	int aktywny;

	Player *p1, *p2;
	p1 = (Player*)malloc(sizeof(Player));
	p2 = (Player*)malloc(sizeof(Player));

	do
	{
		aktywny = menu();

		switch(aktywny)
		{
			case 1:
				clear_keybuf();

				init_player(p1);
				init_player(p2);

				while(podsumowanie(humanvspsp(p1, p2), p1, p2) != 2);

				key[KEY_ENTER] = 0;
				key[KEY_SPACE] = 0;
			break;
			case 2:
				clear_keybuf();

				init_player(p1);
				init_player(p2);

				while(podsumowanie(humanvshuman(p1, p2), p1, p2) != 2);

				key[KEY_ENTER] = 0;
				key[KEY_SPACE] = 0;
			break;
		}
	}
	while(aktywny != 3);

	free(p1);
	free(p2);

	deinit_allegro();

	return 0;
}
END_OF_MAIN()


void init_allegro()
{
	if(allegro_init() != 0)
	{
		printf("Blad instalizacji allegro");
		readkey();
	}

	if(install_keyboard() != 0)
	{
		printf("Blad instalizacji klawiatury");
		readkey();
	}

	if(install_timer() != 0)
	{
		printf("Blad instalizacji zegara");
		readkey();
	}

	set_color_depth(32);
#ifdef PSP
	if(set_gfx_mode(GFX_AUTODETECT, SCREEN_WIDTH, SCREEN_HEIGTH, 0, 0) != 0)
#else
	if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGTH, 0, 0) != 0)
#endif
	{
	 	printf("Blad instalizacji grafiki");
		readkey();
	}

	DIR* cat = opendir("zrzuty_ekranu");
	if(cat == NULL)
		mkdir("zrzuty_ekranu", 0777);
	else
		closedir(cat);
}

void deinit_allegro()
{
	allegro_exit();
}

/* TODO
- dodanie mozliwosci grania przez internet PSP VS PSP, PSP VS PC
- poprawienie bledow (jezeli takie znajda sie)
X dodanie ai
- dodanie mozliwosci grania przez adhoc
- zwiekszyc liczbe graczy do 4 (w opcji przez internet/adhoc)
- poprawienie/zoptymalizowanie kodu
- poprawienie/wymiana grafiki
- dodanie dzwiekow/muzyki

- przyspieszenie "kreski" jezeli bedzie blisko "murku"
- dodanie wyboru koloru kresek
- ranking (lokaly/globalny)
- czat

Funkcje w/w nie oznaczaja, ze beda na 100% zaimplementowane w grze.
 */
