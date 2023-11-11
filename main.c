#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

enum
{
    ASCII_A_LITTLE = 97,
    ASCII_SPACE = 32,
    ASCII_0 = 48,
    ASCII_1 = 49,
    MAX_NUMB_LEN = + 1
};

void print_numb(char *numb, size_t size, int flag) {
    if (flag) {
        printf("18446744073709551616\n");
        return;
    }

}

int
main(int argc, char **argv)
{
    char tmp_symb;
    int symb_index = 0, flag = 0;
    char tmp_numb[MAX_NUMB_LEN] = {0};
    while ((tmp_symb = (char) getchar()) != EOF) {
        if (tmp_symb == ASCII_SPACE) {
            print_numb(tmp_numb, strlen(tmp_numb), flag);
            memset(tmp_numb, 0, sizeof(tmp_numb));
            symb_index = 0, flag = 0;
        } else {
            if (symb_index == MAX_NUMB_LEN) {
                flag = 1;
                continue;
            } else {
                tmp_numb[symb_index++] = tmp_symb;
            }
        }
    }
    return 0;
}