typedef struct
{
	int isalive;
	int x;
	int y;
	int direction;
	int wins;
	int speed;
} Player;

void init_player(Player *player);
void reset_player(Player *player, int x, int y, int direction);
