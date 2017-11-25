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
 */
#include "menu.h"

int main(int argc, char* argv[]) {

    menu m = Menu("Main Menu", argc, argv);  // Create menu
    int ans = m.run(m);                      // Run the menu
    printf("You chose %d.\n", ans);          // Use data from menu
    m.release(m);                            // Clean up

    return 0;
}
