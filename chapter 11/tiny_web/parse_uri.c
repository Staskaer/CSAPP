#include "tiny_web.h"

int parse_uri(char *uri, char *filename, char *cgiargs)
{
    char *ptr;

    if (!strstr(uri, "cgi-bin"))
    { /* Static content */                  //line:netp:parseuri:isstatic
        strcpy(cgiargs, "");                //line:netp:parseuri:clearcgi
        strcpy(filename, ".");              //line:netp:parseuri:beginconvert1
        strcat(filename, uri);              //line:netp:parseuri:endconvert1
        if (uri[strlen(uri) - 1] == '/')    //line:netp:parseuri:slashcheck
            strcat(filename, "index.html"); //line:netp:parseuri:appenddefault
        return 1;
    }
    else
    { /* Dynamic content */    //line:netp:parseuri:isdynamic
        ptr = index(uri, '?'); //line:netp:parseuri:beginextract
        if (ptr)
        {
            strcpy(cgiargs, ptr + 1);
            *ptr = '\0';
        }
        else
            strcpy(cgiargs, ""); //line:netp:parseuri:endextract
        strcpy(filename, ".");   //line:netp:parseuri:beginconvert2
        strcat(filename, uri);   //line:netp:parseuri:endconvert2
        return 0;
    }
}