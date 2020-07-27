/*
Helper functions specific to alttab.

Copyright 2017-2020 Alexander Kulak.
This file is part of alttab program.

alttab is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

alttab is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with alttab.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "alttab.h"
extern Globals g;
//extern Display* dpy;
//extern int scr;
//extern Window root;

// PUBLIC

//
// diagnostic message
//
void msg(int lvl, const char *format, ...)
{
    if (g.debug > lvl) {
        if (lvl == -1) {
            fprintf(stderr, MSGPREFIX);
        }
        va_list ap;
        va_start(ap, format);
        vfprintf(stderr, format, ap);
        va_end(ap);
    }
}

//
// fatal exit with explanation
//
void die(const char *format, ...)
{
    va_list ap;
    fprintf(stderr, MSGPREFIX);
    va_start(ap, format);
    vfprintf(stderr, format, ap);
    va_end(ap);
    exit(1);
}
