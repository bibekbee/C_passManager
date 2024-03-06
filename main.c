#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "library1.h"
#include "library2.h"
#include "library3.h"

void menuGenerate(int* menu1);
int confirmMenu1(int* menu2);

int main()
{
    int z;
    Tejori();
    loopset:
    z = Startup();
    if(z == 1){
        goto loopset;
    }
}

int Startup(){
     int menuNum, z, k;
     do{
      system("cls");
      menuGenerate(&menuNum);
      k = confirmMenu1(&menuNum);
      if(menuNum == 2 || !isdigit(menuNum)){
        break;
      }
     }while(menuNum != 0 && menuNum != 1);
        if(k != 1){
            z = entryPoint(&menuNum);
        }else{
            z = k;
        }
     return z;
}

void menuGenerate(int* menu1){
    printf("----------------E0 -> Enter 0---------------------\n");
    printf("                E0 to Signup \n");
    printf("                E1 to Login \n");
    printf("                E2 to Exit\n");
    scanf("%d", menu1);
}

int confirmMenu1(int* menu2){
    FILE* ptr;
    char c;
    int position;
    ptr = fopen("program.txt", "r");
    switch(*menu2){
    case 0:
            printf("You can Signup Now!\n");
            printf("If want to jump back, type: 'Out'\n\n");
    break;
    case 1:
    if(ptr == NULL){
        printf("You Will have to Sign up first!");
        fclose(ptr);
        getch();
        return 1;
    }else{
        system("cls");
        printf("You can Login Now!!\n");
        printf("If want to jump back, type: 'Out'\n\n");
    }
    break;
    case 2:
    system("cls");
    printf("Okay!");
    break;
    default:
    system("cls");
    printf("You have entered a wrong number!!\nTry again!\n");
  }
  return 0;
}

void Tejori(){
    printf("*******************************************************************\n");
    printf("-------_______---______ ------ _----___----____-----_____----\n");
    printf("------|__   __|-|  ____|------| |-/  _  \\-|  __ \\--|_   _|----\n");
    printf("---------| |----| |___--------| |-| | | |-| |__) |---| |------\n");
    printf("---------| |----|  ___|--_----| |-| | | |-|  __  /---| |------\n");
    printf("---------| |----| |____-| |___| |-| |_| |-| |  \\ \\---| |------\n");
    printf("---------|_|----|______| \\_____/--\\_____/-|_|   \\_\\|_____|-----\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n");
    printf("*******************************************************************\n\n");

    printf("**********************WELCOME TO TEJORI************************\n");
    printf("       Tejori a simple yet very use full application solution \n");
    printf("    It is designed as a light weight password management system.  \n");
    printf("           Using simple encryption mechanism we have developed \n");
    printf("     an application that can safeguard your valuable information\n\n");
    printf("\n");
    printf("             NOTE: Sign up password needs to contain    \n");
    printf("                at least 1 digit, 1 special symbol    \n");
    printf("               and needs to be at least 8 char long     \n");
    //printf("***************DEVELOPED BY BIBEK BHATTATAI****************\n\n");
    printf("******************************************************************\n\n");
    //printf("******************************************************************\n\n");
    getch();
}


