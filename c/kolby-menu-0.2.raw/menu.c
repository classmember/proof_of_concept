/**
 * Simple C Menu Example
 * @author: Kolby H.
 * @license: MIT
 *
 * Example Usage:
 *     $ ./menu "first option" second third
 *     Please select one of the following options:
 *         1) first option
 *         2) second
 *         3) third
 *     > 2
 *     You chose 2.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


int __get_input__() {
	/* returns a number received from stdin input. */
    int input = 0;
    char input_line[256];
    fgets(input_line, sizeof(input_line), stdin);
    sscanf(input_line, "%d", &input);
    return input;
}

void __display_menu__(menu *m) {
	/* display's menu header and options*/
    printf("%s:\n", m->header);
    for(int count=1; count<m->options_count; count++) {
        printf("    %d) %s\n", count, m->options[count]);
    }
}

int run(menu m) {
	/* main loop of menu */
    int running_menu = 1;
    while(running_menu) {
        /* display menu and get user input */
        __display_menu__(&m);
        printf("%s", m.prompt);
        m.selection = __get_input__();

        /* validate selection */
        if(m.selection < 1 || m.selection >= m.options_count) {
            printf("Invalid Entry: Selection out of range.\n");
        } else {
            running_menu = 0;
        }
    }
    return m.selection;
}

void release(menu m) {
    /* free memory from menu options */
	for (int i = 0; i < m.options_count; i++) {
        free(m.options[i]);
        m.options[i] = NULL;
    }
    free(m.options);
}

/**
 * Menu()
 *
 * @returns pointer to initialized menu 
 *
 * @param menu_name is the header of the menu
 * @param argc is the number of menu options
 * @param argv is an array of strings for menu option text
 */
menu Menu(char* menu_name, int argc, char* argv[]) {

    // Create memory pool to store menu options
    long unsigned int mem_pool = 0;
	for (int i = 0; i < argc; i++) {
        mem_pool += (sizeof(argv[i] + 1));
    }
    char **options = calloc(mem_pool, 1);

    // Copy menu options into memory pool
	for (int i = 0; i < argc; i++) {
        options[i] = (char*) calloc(sizeof((argv[i])), sizeof(char));
        strcpy(options[i], argv[i]);
        if(options[i] == NULL) {
            printf("ERROR: not enough memory to store command line argmunts.");
            exit(0);
        } 
    }

    // Create the menu object
    menu the_menu = {
        menu_name,
        "> ",
        &run,
        &release,
        0,
        argc,
        options};

    // return pointer to menu
    return the_menu;
}
