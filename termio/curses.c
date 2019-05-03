#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>
#include <signal.h>

#define MESSAGE	"hello, world!"

static WINDOW *w;
static int last_keycode = -1;

void update_bottom() {
	int wx, wy;
	char keymsg[128];
	getmaxyx(w, wy, wx);
	move(wy-1, 1);
	attron(COLOR_PAIR(2) | A_BOLD);
	if(last_keycode > 0) {
		snprintf(keymsg, sizeof(keymsg), "%c %d 0x%x %20s",
			isprint(last_keycode) ? last_keycode : '-',
			last_keycode, last_keycode, "");
	}
	printw("(%d,%d) Last keycode: %s", wx, wy,
		last_keycode > 0 ? keymsg : "N/A");
}

void update_message() {
	int wx, wy;
	getmaxyx(w, wy, wx);
	move(wy>>1, (wx-strlen(MESSAGE))>>1);
	attron(COLOR_PAIR(1) | A_BOLD);
	printw("%s", MESSAGE);
}

void update_all() {
	clear();
	update_message();
	update_bottom();
	refresh();
}

void handler(int s) {
	endwin();
	refresh();
	update_all();
}

int main() {
	int ch;

	if((w = initscr()) == NULL) {
		fprintf(stderr, "initscr failed.\n");
		return -1;
	}

	cbreak();
	noecho();
	nonl();
	intrflush(w, FALSE);
	keypad(w, TRUE);
	curs_set(0);	// hide cursor

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);

	signal(SIGWINCH, handler);

	update_all();

	while((ch = getch()) != 'q') {
		last_keycode = ch;
		update_bottom();
		refresh();
	}
	
	endwin();

	return 0;
}

