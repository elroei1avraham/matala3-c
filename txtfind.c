#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30

void A(char[],char[]);
void B(char * str);
void get_task(char [],char []);
void get_target(char[], char[]);
int get_size(char *, char[]);
int getWord(char w[]);
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

int getWord(char word[]){
    char ch;
    int count = 0;
    for (int i = 0; 
        ((i  < WORD ) &&
            ((ch = getchar()) != EOF) &&
            ( ch !='\n') &&
            ( ch !='\t') &&
            (ch != ' '));
        ++i ){
        word[i] = ch;
        count++;
    }
    word[count] = '\0';
    return count;
}

void A(char line[],char target[]){
    char *curr_char;
    curr_char = strstr(line, target);
    if(curr_char){
        printf("%s",line);
    }
}

void B(char * target){
    char word[WORD];

    while(getWord(word)) {

        int diff = 1;
        int len_word = strlen(word); 
        int len_target =strlen(target);
        int enter=1;
        if(abs(len_word - len_target) > diff)
        {
            enter=0;
        }
        int index_word = 0;
        int index_target = 0;

        while((index_word < len_word) && (index_target < len_target)) {
            if (word[index_word] != target[index_target]) {
                index_word++;
                diff--;
            } else {
                index_word++;
                index_target++;
            }
        }
        if ((diff < 0) || ( (len_word - index_word) > diff))
        {
            enter=0;
        }

        if(enter)
        {
            printf("%s\n",word);
        }
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
            B(target);
        }
        line_number++;
    }
    return 0;
}