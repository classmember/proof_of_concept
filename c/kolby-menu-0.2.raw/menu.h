/**
 * Simple C Menu Example
 * @author: Kolby H.
 * @license: MIT
 *
 * Structs:
 *     menu
 * 
 * Functions:
 *     Menu()
 *     run()
 *     release()
 *     __get_input__()
 *     __display_menu__()
 */

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* menu type */
typedef struct {
    char *header;
    char *prompt;
    int (*run)();
    void (*release)();
    int  selection;
    int  options_count;
    char **options;
} menu;

int __get_input__();
void __display_menu__(menu *m);
int run(menu m);
void release(menu m);

/**
 * Menu()
 *
 * @returns pointer to initialized menu 
 *
 * @param menu_name is the header of the menu
 * @param argc is the number of menu options
 * @param argv is an array of strings for menu option text
 */
menu Menu(char* menu_name, int argc, char* argv[]);

#endif // MENU_H
