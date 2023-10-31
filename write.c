#include <stdio.h>

int main() {
    char filename [] = "write.txt";
    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        perror("");
        return 1;
    }

    int number, num_lines = 1;
    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "matar\nali\nsaif");
    }

    fclose(file);
    return 0;
}