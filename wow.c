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
    char recordcount; 
    recordcount = fgetc(file); //extracts characters from the file and stores it in character recordcount
    while (recordcount != EOF ) { // while loop will stop when we reach end of file
        if (recordcount == '\n'){ // implying that it will count for encountering a new line
        
            count = count + 1;
        }
            recordcount = fgetc(file); //takes the next character from file until we reach end of file
    }

    fclose(file);
    printf("number of records in file: %d\n", count);

}// I based this idea on https://www.sanfoundry.com/c-program-number-lines-text-file/


void print_record(int record_number, char date[11], char time[6], int steps)
{
    
    printf("%s/%s/%d\n", date, time, steps); // void function to have the format printed in date/time/steps
}
void requestedrecords(){
    char date[11];
	char time[6];
	int steps;
    
    //printf("%s/","%s/","%d/", a.date, a.time, a.steps);
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    int i = 1; // i will be our number of records
    char *sp; // string pointer
    int buffer_size = 100;
    char record[buffer_size];
    while (fgets(record, buffer_size, file) != NULL){

        if (i<=3){ // so it stops at third record
            sp = strtok(record, ","); // this code will start at the begining of the line and stop at the comma(delimiter) and assigning it to the string pointer 
            strcpy(date, sp); // assign the string in the string pointer to the variable which is date
            sp = strtok (NULL, ","); // wrote NULL so it begins from where I left off and that means it will begin from after the first comma until the second comma(delimiter) 
            strcpy (time, sp); // assign the string in the string pointer to variable time
            sp = strtok (NULL, ",");
            steps = atoi(sp); // converting string in string pointer to integer and assigning it to variable steps
            
            
            print_record(i, date, time, steps); //it will print until third record
        }
        i++;
    }
    fclose(file);
  
} // I based this idea on https://www.youtube.com/watch?v=BZFD-eEkhtw and https://arshovon.com/snippets/read-file-by-n-lines/


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
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    int i = 1; // i will be our number of records
    char *sp; // string pointer
    int buffer_size = 100;
    char record[buffer_size];
    while (fgets(record, buffer_size, file) != NULL){
        if (i<=3){
            printf(i,tokeniseRecord(date, time, steps));
        }
    }
    return 0;


}
