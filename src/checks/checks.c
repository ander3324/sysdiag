#include <stdio.h>
#include <string.h>
#include "checks.h"
#include "colors.h"

extern check_t checks[];

void run_all_checks(void) {
    char msg[256];

    for (int i = 0; checks[i].name != NULL; i++) {
        
        memset(msg, 0, sizeof(msg));
        
        check_status st = checks[i].func(msg, sizeof(msg));
        
        printf("[%s] %s\n", 
            st == CHECK_OK ? ("OK") :
            st == CHECK_WARN ? "WARN" : "FAIL", 
            checks[i].name);

        if(msg[0] != '\0')
            printf("%s", msg);  //already include line breaks
    }
}