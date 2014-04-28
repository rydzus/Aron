#include "player.h"

void init_player(Player *player)
{
	player->wins = 0;
	player->speed = 30;
}

void reset_player(Player *player, int x, int y, int direction)
{
	player->isalive = 1;
	player->x = x;
	player->y = y;
	player->direction = direction;
}



