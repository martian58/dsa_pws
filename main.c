#include<stdio.h>
#include<string.h>
#include <stdlib.h> 
#include<stdbool.h>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "./include/common.h"
#include "./pw1/pw1.h"


void pw1_start();

//PWs menu
void pws_menu(){
    clear_screen();
    show_main_menu();
    printf("\n\n");    
    bool option_is_set = false;
    int option;
    while (!option_is_set) { 
        option=get_int_input();
        if (option == 1) { 
            option_is_set = true; 
            clear_screen();
            pw1_start();    
        }
        else if(option==7){
            system("open https://github.com/martian58/bookery");
        }
        else if(option==15){
            clear_screen();
        }
        else {
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }

}

// PW 1
void pw1_start(){
    show_pw1_menu();
    bool ex_is_set=false;
    int ex_num;
    while(!ex_is_set){
        ex_num=get_int_input();
        if(ex_num==1){
            printf("%s\n", "jajajajaj");
        }else if (ex_num==89)
        {
            pws_menu();
        }else if (ex_num==90)
        {
            exit_program();
        }else if (ex_num==99)
        {
            clear_screen();
            pw1_start();
        }
        
        
        
        else{
            printf("%sInvalid option!%s\n",RED,RESET);
        }
    }
}

//Controller function.
void controller(){
    int answer;
    bool answer_is_set=false;
    srand(time(NULL)); 
    intro();

    while(!answer_is_set){
        answer=get_int_input();
        if(answer == 2){
            exit_program();
            answer_is_set=true;
        }
        else if(answer==1){
            answer_is_set=true;
            pws_menu();
        }
        else if(answer==3){
            const char* os=get_operating_system();
            if(strcmp(os, "Windows") == 0){
                system("start https://github.com/martian58");
            }else if(strcmp(os,"Linux") == 0){
                system("open https://github.com/martian58");
            }else{
                system("xdg-open https://github.com/martian58");
            }
        }
        
        else{
            continue;
        }
    }
}
// Main function.
int main() {
    controller();
    return 0;
}
