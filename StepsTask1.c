#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
void count_function(){
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        perror("couldn't open file");
        
    }
    int count = 0;
    char linecount; 
    linecount = fgetc(file); //extracts characters from the file and stores it in character linecount
    while (linecount != EOF ) {
        if (linecount == '\n'){ // implying that it will count for encountering a new line
        
            count = count + 1;
        }
            linecount = fgetc(file); //takes the next character from file until we reach end of file
    }

    fclose(file);
    printf("number of records in file: %d\n", count);

}


void print_record(int record_number, char date[11], char time[6], int steps)
{
    
    printf("%s/%s/%d\n", date, time, steps);
}
void requestedrecords(){
    char date[11];
	char time[6];
	int steps;
    
    //printf("%s/","%s/","%d/", a.date, a.time, a.steps);
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    int i = 1;
    char *sp;
    char record[100];
    while (fgets(record, sizeof(record), file) != NULL){

        if (i<=3){ // so it stops at third line
            sp = strtok(record, ",");
            strcpy(date, sp);
            sp = strtok (NULL, ",");
            strcpy (time, sp);
            sp = strtok (NULL, ",");
            steps = atoi(sp);
            
            
            print_record(i, date, time, steps);
        }
        i++;
    }
    fclose(file);
  
}


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    
    count_function();
    requestedrecords();
    return 0;


}
