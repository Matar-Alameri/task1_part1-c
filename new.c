#include <stdio.h>

void print_line(int line_number, char line[])
{
    printf("%s", line);
}

int main()
{
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    int i = 1;
    // Number of lines per chunk
    if ( file != NULL )
    {
        char line[1000]; /* or other suitable maximum line size */
        while (fgets(line, sizeof line, file) != NULL) /* read a line */
        {
            if(i<=3)
            {
                print_line(i, line);
            }
            i++;
        }
        fclose(file);
    }
    return 0;
}