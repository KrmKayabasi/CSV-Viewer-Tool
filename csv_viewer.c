#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Detecting the separator character
char* detect_delimiter(const char* filename) {

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file <%s>", filename);
        return ","; 
    }

    char line[1024];
    if (!fgets(line, sizeof(line), file)) {
        fclose(file);
        return ","; 
    }
    fclose(file);

    int comma = 0, semicolon = 0, tab = 0, pipe = 0;

    for (int i = 0; i< strlen(line); i++) {
        if (line[i] == ',') comma++;
        else if (line[i] == ';') semicolon++;
        else if (line[i] == '\t') tab++;
        else if (line[i] == '|') pipe++;
    }

    if (comma >= semicolon && comma >= tab && comma >= pipe && comma > 0) return ",";
    if (semicolon >= comma && semicolon >= tab && semicolon >= pipe && semicolon > 0) return ";";
    if (tab >= comma && tab >= semicolon && tab >= pipe && tab > 0) return "\t";
    if (pipe >= comma && pipe >= semicolon && pipe >= tab && pipe > 0) return "|";

    return ","; 
}

//Trim function for the values have extra space both start and end.
void trim(char *s) {
    char *start = s;

    while (*start == ' ') start++;

    char *end = start + strlen(start) - 1;
    
    while (end > start && *end == ' ') end--;

    *(end + 1) = '\0';

    memmove(s, start, strlen(start) + 1);
}

// strdup usage for non POSIX Machines
char* _strdup(const char* s) {
    if (s == NULL) return NULL;

    size_t len = strlen(s);
    char* new_str = malloc(len + 1);  
    if (new_str == NULL) return NULL;

    strcpy(new_str, s);
    return new_str;
}

//For parsing a line of string to array
int parse_string(char* string,char* separator,char*** parsed_array){

    int count = 0;
    char* str_copy = _strdup(string);
    char* str_copy2 = _strdup(string);
    char* TOKEN = strtok(str_copy, separator);
    
    while(TOKEN != NULL){
        TOKEN = strtok(NULL, separator);
        count++;
    }
    
    *parsed_array = malloc(count * sizeof(char*));
    count = 0;
    TOKEN = strtok(str_copy2, separator);

    while(TOKEN != NULL){
        trim(TOKEN);
        (*parsed_array)[count] = malloc(strlen(TOKEN) + 1);
        strcpy((*parsed_array)[count],TOKEN);
        TOKEN = strtok(NULL, separator);
        count++;
    }
   
    free(str_copy2);
    free(str_copy);
    return count;
}

//Getting the biggest lenght for each column set them to array column_width
int get_column_width(char* csv_file_name,char*separator, int** column_width){
    FILE* CSV_FILE = fopen(csv_file_name,"r");
    
    
    char line[600];
    char** parsed_array = NULL;
    fgets(line,sizeof(line),CSV_FILE);
    int x = parse_string(line,separator,&parsed_array);

    *column_width = calloc(x,sizeof(int));
    do{
        
        line[strcspn(line, "\n")] = '\0';
        int x = parse_string(line,separator,&parsed_array);
        
        for(int i = 0; i < x;i++){
            if((*column_width)[i] < (int)strlen(parsed_array[i])){
                (*column_width)[i] = (int)strlen(parsed_array[i]);
            }
        }
        for(int i = 0; i < x;i++){
            free(parsed_array[i]);
        }
        free(parsed_array);

    }
    while (fgets(line,600,CSV_FILE));
    int sum = 0;
    fclose(CSV_FILE);
    for(int i = 0; i < x;i++){
     
        (*column_width)[i] += 2;
        sum += (*column_width)[i];
    }

    return sum;
}

//Function for drawing line
void draw_line(int count){
    for(int j = 0; j < count;j++){
        printf("-");
    }
    printf("\n");
    return;
}

//Function for printing out the table
void tabulate(char* csv_file_name,char* separator,int** column_width){
    int len = get_column_width(csv_file_name,separator,column_width) + 2;
    FILE* CSV_FILE = fopen(csv_file_name,"r");
    
    char line[600];
    int line_count = 0;
    char** parsed_array = NULL;
    fgets(line,sizeof(line),CSV_FILE);
    int x = parse_string(line,separator,&parsed_array);

    do{
        
        line[strcspn(line, "\n")] = '\0';
        int x = parse_string(line,separator,&parsed_array);
        for(int i = 0; i < x;i++){
            
            printf("%-*s",(int) (*column_width)[i],parsed_array[i]);
        }
        line_count++;
        printf("\n");
        if(line_count == 1){
            draw_line(len);
        }  
    }
    while (fgets(line,600,CSV_FILE));
    draw_line(len);
    
    fclose(CSV_FILE);
    for (int i = 0; i < x; i++)
    {
        free(parsed_array[i]);
    }
    free(parsed_array);
    free(*column_width);
    
    return;
}

int main(int argc, char* argv[]){
    
    if(argc != 2){
        printf(
    "\n[ERROR] Wrong Usage!\n[ERROR] Proper Usage: ./Q2 <csv_file_name>\n");
        return -1;
    }

    int* column_width = NULL;
    tabulate(argv[1],detect_delimiter(argv[1]),&column_width);
    return 0;
}