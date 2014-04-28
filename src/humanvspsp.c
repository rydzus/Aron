#include "aron.h"
#include "timer.h"


int humanvspsp(Player *p1, Player *p2)
{
	BITMAP* buffer_field_game = create_bitmap(MAX_WIDTH, MAX_HEIGTH);
	BITMAP* buffer_border_and_info = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGTH);
	int koniec = -1;

	reset_player(p1, 136, 230, 2);
	reset_player(p2, 136, 245, 3);

	clear_to_color(buffer_field_game, makecol(0, 0, 0));
	rysuj_obramowanie(buffer_border_and_info, p1, p2);
	blit(buffer_border_and_info, screen, 0, 0, 0, 0, buffer_border_and_info->w, buffer_border_and_info->h);
	clear_keybuf();

	odliczanie();

	blit(buffer_border_and_info, screen, 0, 0, 0, 0, buffer_border_and_info->w, buffer_border_and_info->h);

	clear_key();

	blit(buffer_field_game, buffer_border_and_info, 0, 0, 1, 1, buffer_field_game->w, buffer_field_game->h);
	blit(buffer_border_and_info, screen, 0, 0, 0, 0, buffer_border_and_info->w, buffer_border_and_info->h);

	p1_speed = 0;
	p2_speed = 0;
	speed = 25;
	install_int_ex(p1_speed_func, MSEC_TO_TIMER(speed));
	install_int_ex(p2_speed_func, MSEC_TO_TIMER(speed));
	install_int_ex(speed_func, SECS_TO_TIMER(1));

	while(TRUE)
	{
		ai_run(p2, buffer_field_game);
		if((p1->x == p2->x) && (p1->y == p2->y))
		{
			koniec = 0;
			break;
		}


		switch(p1->direction)
		{
			case UP:
				if(getpixel(buffer_field_game, p1->y, p1->x-1) != makecol(0, 0, 0))
				{
					koniec = 1;
				}
			break;
			case DOWN:
				if(getpixel(buffer_field_game, p1->y, p1->x+1) != makecol(0, 0, 0))
				{
					koniec = 1;
				}
			break;
			case LEFT:
				if(getpixel(buffer_field_game, p1->y-1, p1->x) != makecol(0, 0, 0))
				{
					koniec = 1;
				}
			break;
			case RIGHT:
				if(getpixel(buffer_field_game, p1->y+1, p1->x) != makecol(0, 0, 0))
				{
					koniec = 1;
				}
			break;
		}

		switch(p2->direction)
		{
			case UP:
				if(getpixel(buffer_field_game, p2->y, p2->x-1) != makecol(0, 0, 0))
				{
					if(koniec == 1)
					{
						koniec = 0;
						break;
					}
					else
					{
						koniec = 2;
					}
				}
			break;
			case DOWN:
				if(getpixel(buffer_field_game, p2->y, p2->x+1) != makecol(0, 0, 0))
				{
					if(koniec == 1)
					{
						koniec = 0;
						break;
					}
					else
					{
						koniec = 2;
					}
				}
			break;
			case LEFT:
				if(getpixel(buffer_field_game, p2->y-1, p2->x) != makecol(0, 0, 0))
				{
					if(koniec == 1)
					{
						koniec = 0;
						break;
					}
					else
					{
						koniec = 2;
					}
				}
			break;
			case RIGHT:
				if(getpixel(buffer_field_game, p2->y+1, p2->x) != makecol(0, 0, 0))
				{
					if(koniec == 1)
					{
						koniec = 0;
						break;
					}
					else
					{
						koniec = 2;
					}
				}
			break;
		}

		putpixel(buffer_field_game, p1->y, p1->x, makecol(255, 255, 255));
		putpixel(buffer_field_game, p2->y, p2->x, makecol(86, 160, 222));

		if(p1->x < MIN_HEIGTH || p1->x > MAX_HEIGTH-1 || p1->y < MIN_WIDTH || p1->y > MAX_WIDTH-1)
		{
			koniec = 1;
		}

		if(p2->x < MIN_HEIGTH || p2->x > MAX_HEIGTH-1 || p2->y < MIN_WIDTH || p2->y > MAX_WIDTH-1)
		{
			if(koniec == 1)
			{
				koniec = 0;
				break;
			}
			else
			{
				koniec = 2;
			}
		}

		blit(buffer_field_game, screen, 0, 0, 1, 1, buffer_field_game->w, buffer_field_game->h);

		if(koniec != -1)
			break;


		if(key[KEY_ESC])
			break;

		if(key[KEY_ENTER])
		{
			pause_game(0, p1, p2);
			odliczanie();
		}

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

#if PSP
		if(key[KEY_UP])
#else
		if(key[KEY_W])
#endif
		{
			if(p1->direction != DOWN)
				p1->direction = UP;
		}
#if PSP
		else if(key[KEY_DOWN])
#else
		else if(key[KEY_S])
#endif
		{
			if(p1->direction != UP)
				p1->direction = DOWN;
		}
#if PSP
		else if(key[KEY_LEFT])
#else
		else if(key[KEY_A])
#endif
		{
			if(p1->direction != RIGHT)
				p1->direction = LEFT;
		}
#if PSP
		else if(key[KEY_RIGHT])
#else
		else if(key[KEY_D])
#endif
		{
			if(p1->direction != LEFT)
				p1->direction = RIGHT;
		}
		clear_keybuf();
		keypressed();


		while(p1_speed > 0)
		{
			switch(p1->direction)
			{
				case UP:
					p1->x--;
				break;
				case DOWN:
					p1->x++;
				break;
				case LEFT:
					p1->y--;
				break;
				case RIGHT:
					p1->y++;
				break;
			}
			p1_speed--;
		}

		while(p2_speed > 0)
		{
			switch(p2->direction)
			{
				case UP:
					p2->x--;
				break;
				case DOWN:
					p2->x++;
				break;
				case LEFT:
					p2->y--;
				break;
				case RIGHT:
					p2->y++;
				break;
			}
			p2_speed--;
		}

	}

	remove_int(p1_speed_func);
	remove_int(p2_speed_func);
	remove_int(speed_func);

	destroy_bitmap(buffer_field_game);
	destroy_bitmap(buffer_border_and_info);

	return koniec;
}
