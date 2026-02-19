#include <stdio.h>
#include <string.h>
#include "checks.h"
#include "style.h"

// Checks declaration 
// Each entry: { "Visible name", función_check } 
check_t checks[] = { { "Available Memory", check_memory }, 
    // Add more checks here: 
    // { "CPU Usage", check_cpu }, 
    // { "Disk Space", check_disk }, 
    // { "Network Status", check_network }
    { NULL, NULL } // Array ended 
};

void run_all_checks(void) {
    char msg[256];

    for (int i = 0; checks[i].name != NULL; i++) {
        
        memset(msg, 0, sizeof(msg));
        
        check_status st = checks[i].func(msg, sizeof(msg));
        
        // First, print status...
        print_status_label(st);
        printf(" %s\n", checks[i].name);

        // Print each msg line
        if(msg[0] != '\0') {
            char *line = strtok(msg, "\n");
            while(line) {
                print_kv("", line); // empty key → perfect alignment
                line = strtok(NULL, "\n");
            }
        }  
        printf("\n");
    }
}