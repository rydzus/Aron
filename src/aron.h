#include <stdio.h>

#include <allegro.h>
#include "player.h"

#ifdef PSP
#include <pspkernel.h>
#include <pspdebug.h>
#endif

#define SCREEN_WIDTH 478
#define SCREEN_HEIGTH 272

#define MAX_WIDTH 476
#define MAX_HEIGTH 252
#define MIN_WIDTH 0
#define MIN_HEIGTH 0

#define MIN_SPEED 10
#define MAX_SPEED 25

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

void screenshot();
void clear_key();
int menu();
void rysuj_obramowanie(BITMAP *sc, Player *p1, Player *p2);
void odliczanie();
int humanvshuman(Player *p1, Player *p2);
int humanvspsp(Player *p1, Player *p2);
int podsumowanie(int gracz, Player *p1, Player *p2);
void ai_run(Player *ai, BITMAP *sc);
int pause_game();

#ifdef PSP
SceUID thid;

int screenshotpsp(SceSize args, void* argp);
#endif

void p1_speed_func();
void p2_speed_func();
void speed_func();

int minspeed;
