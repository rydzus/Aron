#include <allegro.h>
#include <string.h>
#include <unistd.h>

#ifdef PSP
#include <pspthreadman.h>
#endif

void screenshot()
{
	chdir("zrzuty_ekranu");
	time_t now;
	struct tm *ts;
	char buf[80];

	now = time(NULL);

	ts = localtime(&now);
	strftime(buf, sizeof(buf), "aron_%H-%M-%S_%d-%m-%Y", ts);
	save_bitmap(strcat(buf, ".bmp"), screen, default_palette);
	chdir("..");
}

#ifdef PSP
int screenshotpsp(SceSize args, void* argp)
{
	screenshot();

	return sceKernelExitDeleteThread(0);
}
#endif
