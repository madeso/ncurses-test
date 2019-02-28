#include <ncurses.h>

struct Screen
{
  Screen()
  {
    initscr();

    raw(); // disable linebuffer
    keypad(stdscr, TRUE); // ket f1, f2 etc...
    noecho(); // getch doesn't echo
  }

  ~Screen()
  {
    endwin();
  }
};

struct Bold
{
  Bold()
  {
    attron(A_BOLD);
  }
  ~Bold()
  {
    attroff(A_BOLD);
  }
};

int main()
{	
  Screen screen;

	printw("Type any key to see it in bold\n");
	refresh();

  const auto ch = getch();
  if(ch == KEY_F(1))
  {
    printw("f1 pressed");
  }
  else
  {
    printw("Key pressed was (%d): ", ch);
    Bold bold;
    printw("%c", ch);
  }
  refresh();

	getch();

	return 0;
}

