#include "aron.h"

#include <stdlib.h>
#include <time.h>

void step(Player *ai, BITMAP *sc)
{
	//printf("step\n");
	int x, y;
	int licznikl = 0;
	int licznikp = 0;
	int licznikg = 0;
	int licznikd = 0;

	switch(ai->direction)
	{
		case UP:
			//printf("gora\n");
			for(y=ai->y-1; y>=ai->y-10; y--)
			{
				for(x=ai->x-1; x>=ai->x-10; x--)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikl++;
				}
			}

			for(y=ai->y+1; y<=ai->y+10; y++)
			{
				for(x=ai->x-1; x>=ai->x-10; x--)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikp++;
				}
			}

			if(licznikl > licznikp)
			{
				if((getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0)) && (y-1 >= 0))
					ai->direction = LEFT;
				else
					ai->direction = RIGHT;
			}
			else if(licznikl < licznikp)
			{
				if(getpixel(sc, ai->y+1, ai->x) == makecol(0, 0, 0) && (y+1 <= MAX_WIDTH))
					ai->direction = RIGHT;
				else
					ai->direction = LEFT;
			}
			else
			{
				if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0) && (y-1 >= 0))
					ai->direction = LEFT;
				else
					ai->direction = RIGHT;
			}
		break;
		case DOWN:
			//printf("dol\n");
			for(y=ai->y-1; y>=ai->y-10; y--)
			{
				for(x=ai->x+1; x<=ai->x+10; x++)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikl++;
				}
			}

			for(y=ai->y+1; y<=ai->y+10; y++)
			{
				for(x=ai->x+1; x<=ai->x+10; x++)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikp++;
				}
			}

			if(licznikl > licznikp)
			{
				if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0) && (y-1 >= 0))
					ai->direction = LEFT;
				else
					ai->direction = RIGHT;
			}
			else if(licznikl < licznikp)
			{
				if(getpixel(sc, ai->y+1, ai->x) == makecol(0, 0, 0) && (y+1 <= MAX_WIDTH))
					ai->direction = RIGHT;
				else
					ai->direction = LEFT;
			}
			else
			{
				if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0) && (y-1 >= 0))
					ai->direction = LEFT;
				else
					ai->direction = RIGHT;
			}
		break;
		case LEFT:
			//printf("lewo\n");
			for(y=ai->y-1; y>=ai->y-10; y--)
			{
				for(x=ai->x-1; x>=ai->x-10; x--)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikg++;
				}
			}

			for(y=ai->y-1; y>=ai->y-10; y--)
			{
				for(x=ai->x+1; x<=ai->x+10; x++)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikd++;
				}
			}

			if(licznikg > licznikd)
			{
				if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0) && (x-1 >= 0))
					ai->direction = UP;
				else
					ai->direction = DOWN;
			}
			else if(licznikg < licznikd)
			{
				if(getpixel(sc, ai->y, ai->x+1) == makecol(0, 0, 0) && (x+1 <= MAX_HEIGTH))
					ai->direction = DOWN;
				else
					ai->direction = UP;
			}
			else
			{
				if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0) && (x-1 >= 0))
					ai->direction = UP;
				else
					ai->direction = DOWN;
			}
		break;
		case RIGHT:
			//printf("prawo\n");
			for(y=ai->y+1; y<=ai->y+10; y++)
			{
				for(x=ai->x-1; x>=ai->x-10; x--)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikg++;
				}
			}

			for(y=ai->y+1; y<=ai->y+10; y++)
			{
				for(x=ai->x+1; x<=ai->x+10; x++)
				{
					if(!((x < 0) || (x > MAX_HEIGTH) || (y < 0) || (y > MAX_WIDTH)))
						if(getpixel(sc, y, x) == makecol(0, 0, 0))
							licznikd++;
				}
			}

			if(licznikg > licznikd)
			{
				if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0) && (x-1 >= 0))
					ai->direction = UP;
				else
					ai->direction = DOWN;
			}
			else if(licznikg < licznikd)
			{
				if(getpixel(sc, ai->y, ai->x+1) == makecol(0, 0, 0) && (x+1 <= MAX_HEIGTH))
					ai->direction = DOWN;
				else
					ai->direction = UP;
			}
			else
			{
				if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0) && (x-1 >= 0))
					ai->direction = UP;
				else
					ai->direction = DOWN;
			}
	}
	//printf("\n");
}

void ai_run(Player *ai, BITMAP *sc)
{
	static int licznik = 0;
	static int counter_edge = 0;
	int direction_old = ai->direction;
	srand(time(NULL));

	if((ai->x-1 <= 0) && (ai->direction == UP))
	{
		if(ai->y < 127)
		{
			if(getpixel(sc, ai->y+1, ai->x) == makecol(0, 0, 0))
				ai->direction = RIGHT;
		}
		else
		{
			if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0))
				ai->direction = LEFT;
		}

		if(counter_edge >= (rand()%11)+5)
		{
			step(ai, sc);
			counter_edge = 0;
		}
		else
			counter_edge++;
	}
	else if(ai->x+1 >= MAX_HEIGTH  && (ai->direction == DOWN))
	{
		if(ai->y < 127)
		{
			if(getpixel(sc, ai->y+1, ai->x) == makecol(0, 0, 0))
				ai->direction = RIGHT;
		}
		else
		{
			if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0))
				ai->direction = LEFT;
		}

		if(counter_edge >= (rand()%11)+5)
		{
			step(ai, sc);
			counter_edge = 0;
		}
		else
			counter_edge++;
	}
	else if(ai->y-1 <= 0  && (ai->direction == LEFT))
	{
		if(ai->x < 127)
		{
			if(getpixel(sc, ai->y, ai->x+1) == makecol(0, 0, 0))
				ai->direction = DOWN;
		}
		else
		{
			if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0))
				ai->direction = UP;
		}

		if(counter_edge >= (rand()%11)+5)
		{
			step(ai, sc);
			counter_edge = 0;
		}
		else
			counter_edge++;
	}
	else if(ai->y+1 >= MAX_WIDTH  && (ai->direction == RIGHT))
	{
		if(ai->x < 127)
		{
			if(getpixel(sc, ai->y, ai->x+1) == makecol(0, 0, 0))
				ai->direction = DOWN;
		}
		else
		{
			if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0))
				ai->direction = UP;
		}

		if(counter_edge >= (rand()%11)+5)
		{
			step(ai, sc);
			counter_edge = 0;
		}
		else
			counter_edge++;
	}


	if((ai->direction == direction_old) && (ai->x != 0) && (ai->x != MAX_HEIGTH)  && (ai->y != 0) && (ai->y != MAX_WIDTH))
	{
		switch(ai->direction)
		{
			case UP:
				if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0))
				{
					if(getpixel(sc, ai->y, ai->x-2) == makecol(0, 0, 0))
					{
						if(getpixel(sc, ai->y, ai->x-3) == makecol(0, 0, 0))
						{
							if(licznik >= 40+rand()%200)
							{
								switch((rand() % 2) + 2)
								{
									case LEFT:
										if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0))
											ai->direction = LEFT;
										else
											ai->direction = RIGHT;
									break;
									case RIGHT:
										if(getpixel(sc, ai->y+1, ai->x) == makecol(0, 0, 0))
											ai->direction = RIGHT;
										else
											ai->direction = LEFT;
									break;
								}
								licznik = 0;
							}
							else
								licznik++;
						}
					}
				}
				else
					step(ai, sc);
			break;
			case DOWN:
				if(getpixel(sc, ai->y, ai->x+1) == makecol(0, 0, 0))
				{
					if(getpixel(sc, ai->y, ai->x+2) == makecol(0, 0, 0))
					{
						if(getpixel(sc, ai->y, ai->x+3) == makecol(0, 0, 0))
						{
							if(licznik >= 40+rand()%200)
							{
								switch((rand() % 2) + 2)
								{
									case LEFT:
										if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0))
											ai->direction = LEFT;
										else
											ai->direction = RIGHT;
									break;
									case RIGHT:
										if(getpixel(sc, ai->y+1, ai->x) == makecol(0, 0, 0))
											ai->direction = RIGHT;
										else
											ai->direction = LEFT;
									break;
								}
								licznik = 0;
							}
							else
								licznik++;
						}
					}
				}
				else
					step(ai, sc);
			break;
			case LEFT:
				if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0))
				{
					if(getpixel(sc, ai->y-1, ai->x-2) == makecol(0, 0, 0))
					{
						if(getpixel(sc, ai->y-3, ai->x-3) == makecol(0, 0, 0))
						{
							if(licznik >= 40+rand()%200)
							{
								switch(rand() % 2 + 0)
								{
									case UP:
										if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0))
											ai->direction = UP;
										else
											ai->direction = DOWN;
									break;
									case DOWN:
										if(getpixel(sc, ai->y, ai->x+1) == makecol(0, 0, 0))
											ai->direction = DOWN;
										else
											ai->direction = UP;
									break;
								}
								licznik = 0;
							}
							else
								licznik++;
						}
					}
				}
				else
					step(ai, sc);
			break;
			case RIGHT:
				if(getpixel(sc, ai->y+1, ai->x) == makecol(0, 0, 0))
				{
					if(getpixel(sc, ai->y+2, ai->x) == makecol(0, 0, 0))
					{
						if(getpixel(sc, ai->y+3, ai->x) == makecol(0, 0, 0))
						{
							if(licznik >= 40+rand()%200)
							{
								switch(rand() % 2 + 0)
								{
									case UP:
										if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0))
											ai->direction = UP;
										else
											ai->direction = DOWN;
									break;
									case DOWN:
										if(getpixel(sc, ai->y, ai->x+1) == makecol(0, 0, 0))
											ai->direction = DOWN;
										else
											ai->direction = UP;
									break;
								}
								licznik = 0;
							}
							else
								licznik++;
						}
					}
				}
				else
					step(ai, sc);
			break;
		}
	}

	if((ai->direction == LEFT) && (direction_old == RIGHT))
	{
		if(getpixel(sc, ai->y, ai->x-1) == makecol(0, 0, 0))
			ai->direction = UP;
		else
			ai->direction = DOWN;
	}
	else if((ai->direction == UP) && (direction_old == DOWN))
	{
		if(getpixel(sc, ai->y-1, ai->x) == makecol(0, 0, 0))
			ai->direction = LEFT;
		else
			ai->direction = RIGHT;
	}
}
