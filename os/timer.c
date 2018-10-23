#include <stdio.h>
#include <time.h>

#include <ncurses.h>

inline void subtract_time (struct timespec * __restrict later, struct timespec * __restrict former)
{
	clock_gettime(CLOCK_MONOTONIC, later);
	later->tv_sec -= former->tv_sec;
	if (later->tv_nsec < former->tv_nsec)
	{
		later->tv_sec--;
		later->tv_nsec = 1000000000 + later->tv_nsec - former->tv_nsec;
	}
	else
	{
		later->tv_nsec -= former->tv_nsec;
	}
}

int main (int argc, char *argv[])
{
	int ch;
	unsigned int countdown;
	struct timespec start;
	struct timespec now;

	clock_gettime(CLOCK_MONOTONIC, &start);
	if (2 == argc)
	{
		sscanf (argv[1], "%u", &countdown);
		start.tv_sec += countdown * 60;
	}
	else if (1 != argc)
	{
		printf ("Usage: %s <minute_countdown>\n", argv[0]);
		return 1;
	}

	initscr();
	cbreak();
	noecho();
	nodelay (stdscr, TRUE);

	struct timespec delay;
	delay.tv_sec = 0;
	delay.tv_nsec = 1000000;

	int paused = 0;
	struct timespec prev = start;
	for (;;)
	{
		if (0 == paused)
		{
			subtract_time (&now, &start);
			if (now.tv_sec != prev.tv_sec)
			{
				mvprintw (1, 2, "%+04d:%+03d", now.tv_sec / 60 , now.tv_sec % 60);
				refresh();
				prev = now;
			}
		}
		else
		{
			subtract_time (&start, &now);
		}

		if (ERR != (ch = getch()))
		{
			if (27 == ch)
			{
				break;
			}
			else
			{
				if (0 == paused)
				{
					attron (A_STANDOUT);
					paused = 1;
				}
				else
				{
					attroff (A_STANDOUT);
					paused = 0;
				}
				mvprintw (1, 2, "%+04d:%+03d", now.tv_sec / 60 , now.tv_sec % 60);
				refresh();
			}
		}
		clock_nanosleep (CLOCK_MONOTONIC, 0, &delay, NULL);
	}

	endwin();
	return 0;
}
