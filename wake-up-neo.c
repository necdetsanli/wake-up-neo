#include <ncurses.h>
#include <string.h>


int main(void)
{
    initscr();
    curs_set(0);

    char text1[] = "Wake up, Neo...";
    char text2[] = "The Matrix has you...";
    char text3[] = "Follow the white rabbit.";
    char text4[] = "Knock, knock, Neo.";

    char* t = text1;
    int len = strlen(text1);

    if (!has_colors() || start_color() != OK) {
        printf("Cannot start colors!");
        return 1;
    }

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attrset(COLOR_PAIR(1)| A_BLINK | A_BOLD);

    move(3, 3);
    while (len--) {
        addch(*t++);
        refresh();
        napms(150);
    }

    napms(5000);
    clear();
    

    len = strlen(text2);
    t = text2;

    move(3,3);
    while (len--) {
        addch(*t++);
        refresh();
        napms(200);
    }

    napms(4000);
    clear();

    len = strlen(text3);
    t = text3;

    move(3, 3);
    while (len--) {
        addch(*t++);
        refresh();
        napms(100);
    }

    napms(4000);
    clear();

    len = strlen(text4);
    t = text4;

    move(3, 3);
    attroff(A_BLINK);
    addstr(text4);
    napms(3000);


    getch();

    endwin();
    return 0;
}
