#ifndef LIBRARY1_H_INCLUDED
#define LIBRARY1_H_INCLUDED
#define SIZE 100
#endif // LIBRARY1_H_INCLUDED


int secondMenu(char* getUser){
    int Eselect, z;
    loopset:
    printf("----------------E0 -> Enter 0---------------------\n");
    printf("                E0 to Add Credentials \n");
    printf("                E1 to Update Credentials \n");
    printf("                E2 to Search\n");
    printf("                E3 to Exit\n");
    scanf("%d", &Eselect);

    z = Caller(&Eselect, getUser);
    if (z == 1){
        goto loopset;
    }
    return z;
}

int Caller(int* take, char* getUser1){
    char c;
    int z;
    switch(*take){
        case  0:
        system("cls");
        z = addCred(*take, getUser1);
        break;
        case 1:
        system("cls");
        z = addCred(*take, getUser1);
        break;
        case  2:
        system("cls");
        z = addCred(*take, getUser1);
        break;
        case  3:
        system("cls");
        z = Exit();
        break;
        default:
        system("cls");
        printf("You have entered a wrong number!\nPlease try again.\n\n");
        return 1;
    };
    system("cls");
    return z;
};

int  addCred(int input, char* getUser2){
    int selector, z;
    char c;
    printf("------Select Accordingly:------- \n");
    printf("       0 - Socails\n       1 - Websites\n       2 - Ggmail\n       3 - Others\n       4 - Back\n");
    scanf("%d", &selector);
        if(selector == 4){
               fflush(stdin);
               return 1;
        }
    printf("\n");
        switch(input){
        case 0:
           z = InputADD(selector, getUser2);
         break;
        case 1:
           z = UpdateCred(selector, getUser2);
         break;
        case 2:
           z = Finder(selector, getUser2);
         break;
        default:
         printf("Error");
         fflush(stdin);
         c = getchar();
         z = 1;
        }
    return z;

};
int InputADD(int fileSelector, char* getUser3) {
    char c;
    FILE *ptr;
    char platform[SIZE], user[SIZE], pass[SIZE], word[SIZE], word1[SIZE], word2[SIZE], path[100];
    int found;
    printf("At any point you can type: 'Out' to Exit\n\n");

    /*Flusing the buffer*/fflush(stdin);
    printf("Enter the Platform Name: ");
    scanf("%s", &platform);
        if(out(&platform)){
                return 1;
            }
    /*Flusing the buffer*/ fflush(stdin);
    printf("Enter the UserName: ");
    scanf("%s", &user);
        if(out(&user)){
                return 1;
            }
    /*Flusing the buffer*/ fflush(stdin);
    printf("Enter your password: ");
    //scanf("%s", &pass);
    astric(&pass);
        if(out(&pass)){
                return 1;
            }
            encript(&pass);
    printf("\n");
    found = 0;
    strcpy(path, getUser3);

        switch(fileSelector){
            case 0:
            strcat(path, "\\Social_Crd.txt");
            ptr = fopen(path,"a+");
            break;
            case 1:
            strcat(path,"\\Web_Crd.txt");
            ptr = fopen(path,"a+");
            break;
            case 2:
            strcat(path,"\\Gmail_Crd.txt");
            ptr = fopen(path,"a+");
            break;
            default:
            strcat(path,"\\Other_Crd.txt");
            ptr = fopen(path,"a+");
        }

        if(ptr == NULL)
          {
          printf("Error!");
          exit(1);
          }

        while (fscanf(ptr, "%[^,], %[^,], %s\n", word, word1, word2) == 3) {
        if (!(strcmp(word, platform)) && !(strcmp(word1, user)) && !(strcmp(word2, pass))) {
            found = 1;
            break;
           }
        }
    if(found == 0){
     fprintf(ptr,"%s,",platform);
     fprintf(ptr,"%s,",user);
     fprintf(ptr,"%s\n",pass);
    }else{
     system("cls");
     printf("You have already entered this Credentials\n");
     printf("Hit Enter and you will be sent back. \n");
     fflush(stdin);
     c = getchar();
     return 1;
    }
    fclose(ptr);
    printf("Enter to Exit");
    fflush(stdin);
    c = getchar();
    return 1;
}



int Finder(int fileSelector, char* getUser3){
    char c;
    FILE *ptr;
    char platform[SIZE], user[SIZE], pass[SIZE], word[SIZE], word1[SIZE], word2[SIZE], path[100];
    int found,position;
    found = 0;
    strcpy(path, getUser3);
        switch(fileSelector){
            case 0:
            strcat(path,"\\Social_Crd.txt");
            ptr = fopen(path,"r");
            break;
            case 1:
            strcat(path,"\\Web_Crd.txt");
            ptr = fopen(path,"r");
            break;
            case 2:
            strcat(path,"\\Gmail_Crd.txt");
            ptr = fopen(path,"r");
            break;
            default:
            strcat(path,"\\Other_Crd.txt");
            ptr = fopen(path,"r");
        };

        if(ptr == NULL)
          {
          printf("You will have to Add credentials first!");
                fclose(ptr);
                getch();
                return 1;
          }

         loopback:
         printf("E0: Search all \n");
         printf("E1: Search based on Platform Name \n");
         printf("E2: Search based on Platform and UserName\n");
         scanf("%d", &found);

         switch(found){
            case 0:
            break;
            case 1:
                printf("Enter the platform Name: ");
                scanf("%s", &platform);
            break;
            case 2:
                printf("Enter the platform Name: ");
                scanf("%s", &platform);
                printf("Enter User Name: ");
                scanf("%s", &user);
            break;
            default:
                printf("Wrong Entry\nEnter to Exit");
                fflush(stdin);
                c = getchar;
                goto loopback;
         }

          fseek(ptr,0,SEEK_END);
          position = ftell(ptr);
          if(position < 1){
                printf("\nThere are not credentials to see");
                getch();
                return 1;
          }else{
                printf("Here is the list of your credentials\n\n");
                 fseek(ptr,0,SEEK_SET);
          }

          while (fscanf(ptr, "%[^,], %[^,], %s\n", word, word1, word2) == 3) {
            dencript(&word2);
            if(found == 0){
               printf("--------------  [Platform]: %s  [User]: %s  [Password]: %s  --------------\n\n", word, word1, word2);
            }else if(found == 1){
              if(!strcmp(word, platform)){
                printf("--------------  [Platform]: %s  [User]: %s  [Password]: %s  --------------\n\n", word, word1, word2);
              }
            }else if(found == 2){
              if(!strcmp(word, platform) && !strcmp(word1, user)){
                printf("--------------  [Platform]: %s  [User]: %s  [Password]: %s  --------------\n\n", word, word1, word2);
              }
            }

          }

         fclose(ptr);

         fflush(stdin);
         printf("Enter to exit");
         c = getchar();
         fseek(ptr,0,SEEK_SET);
    return 1;
};

int Exit(){
    return 2;
};

 int out(char* inter){
   if(!strcmp(inter, "out") || !strcmp(inter, "Out")){
        return 1;
    }
    return 0;
 }


 void encript(char* all){
    int i;
    for(i = 0; i < 100; i++){
        if(all[i] == '\0'){
            break;
        }
        all[i] = (int)all[i] + 7;
        all[i] = (char)all[i];
    }
}


void dencript(char* all){
    int i;
    for(i = 0; i < 100; i++){
        if(all[i] == '\0'){
            break;
        }
        all[i] = (int)all[i] - 7;
        all[i] = (char)all[i];
    }
}
