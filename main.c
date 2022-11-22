#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "banner.h"
#include "menu.h"
#include "pilihanPlayer.h"

int main()
{
    menu( &pilihanMenu );
    cekMenu();
    return 0;
}