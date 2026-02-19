#include <stdio.h>
#include <string.h>
#include "checks.h"

check_status check_memory(char *msg, size_t msg_size) {
    
    FILE *f = fopen("/proc/meminfo", "r");
    
    if(!f) {
        snprintf(msg, msg_size, "Could not read /proc/meminfo...");
        return CHECK_FAIL;
    }

    char key[64];
    long value;
    long mem_total_kb = 0;
    long mem_available_kb = 0;
   
    while (fscanf(f, "%63s %ld kB", key, &value) == 2)
    {
        if(strcmp(key, "MemTotal:") == 0) {
            mem_total_kb = value;
        }
        else if(strcmp(key, "MemAvailable:") == 0) {
            mem_available_kb = value;
        }

        if(mem_total_kb && mem_available_kb)
            break;
    }
    
    fclose(f);

    double mem_total_mb = mem_total_kb / 1024.0;
    double mem_total_gb = mem_total_kb / (1024.0 * 1024.0);
    double mem_available_mb = mem_available_kb / 1024.0;
    double mem_available_gb = mem_available_kb / (1024.0 * 1024.0);

    snprintf(msg, msg_size, 
        "\tTotal Memory: %.2f GiB | %.2f MiB | %ld KiB\n"
        "\tAvailable Memory: %.2f GiB | %.2f MiB | %ld KiB\n", 
        mem_total_gb, mem_total_mb, mem_total_kb,
        mem_available_gb, mem_available_mb, mem_available_kb
    );
    
    if(mem_available_kb < 200000) 
        return CHECK_WARN;

    return CHECK_OK;
}

check_t checks[] = {
    {"Available Memory", check_memory},
    {NULL, NULL}
};