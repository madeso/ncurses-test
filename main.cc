#include <ncurses.h>

struct Screen
{
  Screen()
  {
    initscr();
  }

  ~Screen()
  {
    endwin();
  }
};

int main()
{	
  Screen screen;

	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */

	return 0;
}

