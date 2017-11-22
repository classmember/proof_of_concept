/* getenv example: getting path */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* getenv */

int main ()
{
    // get $PATH
    char* pPath;
    pPath = getenv ("PATH");
    if (pPath!=NULL)
        printf ("$PATH: %s\n",pPath);

    // get $HOME
    char* pHome;
    pHome = getenv ("HOME");
    if (pPath!=NULL)
        printf ("$HOME: %s\n",pHome);

    return 0;
}
