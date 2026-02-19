#include <stdio.h>
#include "style.h"

void print_status_label(check_status st) {
    const char *color;
    const char *label;

    switch (st) {
        case CHECK_OK:
            color = COLOR_GREEN;
            label = "OK";
            break;
        case CHECK_WARN:
            color = COLOR_YELLOW;
            label = "WARN";
            break;
        default:
            color = COLOR_RED;
            label = "FAIL";
            break;
    }

    printf("[%s%s%s]", color, label, COLOR_RESET);
}

void print_section_title(const char *title) {
    printf("%s%s%s\n", COLOR_CYAN, title, COLOR_RESET);
}

void print_kv(const char *key, const char *value) {
    printf("%-20s %s\n", key, value);
}