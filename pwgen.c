#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LENGTH 8

void generate_random_password(size_t len) {

    char s[len];
    size_t i = 0;
    while (i < len) {
        char r = (rand() % 92) + '0';
        if (isalnum(r)) {
            s[i] += r < 0 ? r * -1 : r;
            i++;
        }
    }

    printf("%s\n", s);
}

void print_usage(char* program) {
    fprintf(stderr, "[ERROR] No password strength has been provided!\n");
    fprintf(stderr, "[USAGE] %s <LOW | HIGH | SECURE>\n", program);
}

int main(int argc, char** argv) {

    if (argc < 2) {
        print_usage(argv[0]);
        exit(1);
    } else {
        argv++;
    }

    srand(time(NULL));
    size_t len = LENGTH;
    char *flag = *argv;

    if (!strcmp(flag, "LOW"))    len *= 0.5;
    if (!strcmp(flag, "HIGH"))   len *= 2;
    if (!strcmp(flag, "SECURE")) len *= 4;

    generate_random_password(len);

    return 0;

}
