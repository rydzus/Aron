TARGET = aron
OBJS = src/aron.o src/player.o src/screenshot.o src/ai.o src/humanvshuman.o \
src/podsumowanie.o src/menu.o src/humanvspsp.o src/odliczanie.o \
src/rysuj_obramowanie.o src/clear_key.o src/pause_game.o src/timer.o

INCDIR =
CFLAGS = -G0 -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Aron
PSP_EBOOT_ICON = ICON0.PNG

PSPSDK=$(shell psp-config --pspsdk-path)
PSP_PREFIX = $(shell psp-config --psp-prefix)
PSPBIN = $(PSP_PREFIX)/bin
CFLAGS += $(shell $(PSPBIN)/psp-allegro-config --cflags)
LIBS += $(shell $(PSPBIN)/psp-allegro-config --libs release)
include $(PSPSDK)/lib/build.mak
