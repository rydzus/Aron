make clean
rm aronpc
echo "kompiluje wersje PC"
gcc -Wall -g -o aronpc src/aron.c src/player.c src/screenshot.c \
src/ai.c src/humanvshuman.c src/podsumowanie.c src/menu.c src/humanvspsp.c \
src/odliczanie.c src/rysuj_obramowanie.c src/clear_key.c src/pause_game.c \
src/timer.c \
`allegro-config --libs --cflags`

echo "kompiluje wersje PSP"
make clean
make
