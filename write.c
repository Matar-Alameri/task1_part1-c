#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;
void print_line(int line_number, char date[11], char time[6], int steps)
{
    
    printf("%s/%s/%d\n", date, time, steps);
}


int main() {
    char date[11];
	char time[6];
	int steps;
    
    //printf("%s/","%s/","%d/", a.date, a.time, a.steps);
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    int i = 1;
    char *sp;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL){

        if (i<=3){
            sp = strtok(line, ",");
            strcpy(date, sp);
            sp = strtok (NULL, ",");
            strcpy (time, sp);
            sp = strtok (NULL, ",");
            steps = atoi(sp);
            
            
            print_line(i, date, time, steps);
        }
        i++;
    }
    fclose(file);
    return 0;
}