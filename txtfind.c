#include<stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

void A(char[],char[]);
void B(char[], char[]);
void get_task(char [],char []);
void get_target(char[], char[]);
int get_size(char *, char[]);
int compare_words(char[], char []);
int get_line_size(char*);

void get_target(char curr_line[], char *target){
    if(curr_line==NULL){
        printf("the file is empty");
    }
    int index =0;
    while(curr_line[index]!=' '){
        target[index] = curr_line[index];
        index++;
    }
     target[index] ='\0';
}

void get_task(char curr_line[], char task[]){
    if(curr_line==NULL){
        printf("the file is empty");
    }
    int index =0;
    while(curr_line[index]!=' '){
        index++;
    }
    index++;
    task[0] = curr_line[index];
    task[1] = '\0';
}

int get_size(char *ptr, char word[]){
    if(ptr==NULL){
        return 0;
    }   
    int counter =0;
    int index = 0;
    while (ptr[index-1]!=' ' &&ptr[index-1]!='\n' && ptr[index-1]!='\t' ){
        index--;
    }
    while(ptr[index]!=' ' &&ptr[index]!='\n' && ptr[index]!='\t'){
        word[counter] = ptr[index]; 
        counter++;
        index++;
    }
    word[counter+1] = '\0';
    return counter;
}

int compare_words(char target[], char word[]){
    int ans = 2;
    int tar_index = 0;
    int word_index = 0;
    while(word_index<strlen(word) && tar_index<strlen(target)){
        if(word[word_index]==target[tar_index]){
            word_index++;
            tar_index++;
        }
        else{
            word_index++;
            ans--;
        }
    }
    return ans;
}

int get_line_size(char *line){
    int counter =0;
    while(line[counter]!='\n'){
        counter++;
    }
    return counter;
}

void A(char line[],char target[]){
    char *curr_char;
    curr_char = strstr(line, target);
    if(curr_char){
        printf("%s",line);
    }
}

void B(char line[], char target[]){
    int size;
    char *curr_char;
    char word[WORD];     
    curr_char = strchr(line, target[0]);
    while(curr_char!=NULL){
        size = get_size(curr_char, word);
        if(size == strlen(target)+1){ 
            if(compare_words(target,word)){
                printf("%s\n", word);
            }
        }
        else if(size == strlen(target)){            
            if(!strcmp(target,word)){
                printf("%s\n", word);
            }         
        }
        curr_char = strchr(curr_char+1, target[0]);
    }
}

int main(){
    char curr_line[LINE];
    char target[WORD];
    char task[WORD];
    char a[] = "a";
    char b[] = "b";
    int line_number = 0;

    while(fgets(curr_line,LINE,stdin)!=NULL){
        if(line_number==0){
            get_target(curr_line,target);
            get_task(curr_line,task);       
        }

        if(!(strcmp(task,a))&&(line_number!=0)){
            A(curr_line, target);
        }

        if(!(strcmp(task,b))&&(line_number!=0)){
            B(curr_line, target);
        }
        line_number++;
    }
    return 0;
}