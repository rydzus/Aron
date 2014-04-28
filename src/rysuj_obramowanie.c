#include "aron.h"

void rysuj_obramowanie(BITMAP *sc, Player *p1, Player *p2)
{

	clear_to_color(sc, makecol(144, 238, 144));
	rectfill(sc, 1, 1, MAX_WIDTH, MAX_HEIGTH, makecol(0, 0, 0));
	rectfill(sc, 1, 254, 476, 270, makecol(0, 0, 0));
	textprintf_ex(sc, font, 5, 259, makecol(255, 255, 255), -1, "Gracz 1");
	textprintf_ex(sc, font, 415, 259, makecol(86, 160, 222), -1, "Gracz 2");
	textprintf_ex(sc, font, MAX_WIDTH/2-10, 259, makecol(255, 255, 255), -1, "%d : %d", p1->wins, p2->wins);
}
