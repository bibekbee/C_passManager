#ifndef LIBRARY1_H_INCLUDED
#define LIBRARY1_H_INCLUDED
#define SIZE 100
int CheckerINT = 0;
int grow = 0;
char NameHolder[100];
/* -- || This function to calls
------|| Signup or Login or exit ----- */

int entryPoint(int *entry1){
    int z;
    char c;
    switch(*entry1){
        case 0:
        z = signupFun();
        break;
        case 1:
        z = loginFun();
        break;
        case 2:
        fflush(stdin);
        printf("Bye!\n\n");
        c = getchar();
        break;
        default:
        printf("Error !!");
    }

    return z;
}

/* -- || This is :
------|| Signup function  ----- */

int signupFun(){
    char c;
    if(grow == 0){
        FILE *ptr;
        int found, position;
        char user[SIZE], pass[SIZE], Savpin[SIZE], word[SIZE], word1[SIZE];

        backup:

        printf("Enter your Username: ");
        scanf("%s", &user);
        strcpy(NameHolder,user);
        //OUT FUNCTION----------
             if(out(&user)){
                return 1;
            }
        //------------------ ||
        printf("\n");
        passFail:
        printf("Enter your password: ");
        //scanf("%s", &pass);
        astric(&pass);
        if(strong(&pass)){
            goto passFail;
        }
        encript(&pass);

        //OUT FUNCTION----------
             if(out(&pass)){
                return 1;
            }
         //------------------ ||
        printf("\n");
        found = 0;
            ptr = fopen("program.txt","a+");

            if(ptr == NULL)
              {
              printf("Error!");
              getch();
              exit(1);
              }

            while (fscanf(ptr, "%[^,],%s\n", word, word1) == 2) {
            if (strcmp(word, user) == 0) {
                found = 1;
                break;
               }
            }

        if(found==1){
          system("cls");
          printf("This user already exists!\n");
          printf("Try again!\n");
          goto backup;

        }else{
         fprintf(ptr,"%s,",user);
         fprintf(ptr,"%s\n",pass);
         grow++;
        fclose(ptr);

         if(CheckerINT == 0){
            if(checker()== 0){
                mkdir(user);
            }
        }
        }
        printf("\npress enter to Submit");
        fflush(stdin);
        c = getchar();
        return 1;
    }else{
        printf("You have to exit and restart to signup with another id");
        fflush(stdin);
        c = getchar();
        return 1;
    }
};

/* -- || This is :
------|| Loginup function  ----- */

int  loginFun(){
    FILE *ptr;
    char c;
    int founduser, foundpass, z;
    char user[100], pass[100], word[50], word1[50];
    label:
    printf("Enter your Username: ");
    scanf("%s", &user);
        /*if(!strcmp(user, "out") || !strcmp(user, "Out")){
               fflush(stdin);
               return 1;
               }*/
        if(out(&user)){
            return 1;
        }
    printf("\n");
    printf("Enter your password: ");
    //scanf("%s", &pass);
    astric(&pass);
        /*if(!strcmp(pass, "out") || !strcmp(pass, "Out")){
               fflush(stdin);
               return 1;
            }*/
            if(out(&pass)){
            return 1;
        }
    encript(&pass);
    printf("\n");
    founduser = 0; foundpass = 0;
    ptr = fopen("program.txt","r");
        if(ptr == NULL)
          {
          printf("Error!");
          exit(1);
          }

     while (fscanf(ptr, "%[^,],%s\n", word, word1) == 2) {
        if (strcmp(word, user) == 0) {
            founduser = 1;
            if (strcmp(word1, pass) == 0){
            foundpass = 1;
            break;
          }
        }
        }
    if((founduser == 1) && (foundpass == 1)){
        system("cls");
        printf("You are now loggedIn to your Dashboard!\n\n");
         z = secondMenu(&user);
         if(z == 2){
            return 1;
         }
         fflush(stdin);
    }else{
        system("cls");
        printf("Your LogIn credentials Do Not match Try again!\n");
        fflush(stdin);
        c = getchar();
        goto label;
    }
    return 1;
};

void astric(char* str1){
    int i = 0;
    char ch;
    while (1) {
        ch = getch();

        // Check for the Enter key to terminate the loop
        if (ch == '\r' || ch == '\n') {
            str1[i] = '\0';  // Null-terminate the password string
            break;
        }

        if(ch == '\b'){
             if (i > 0) {
                    printf("\b \b"); // Move cursor back, print space, move cursor back again
                    i--;
                }
        }else{
             str1[i] = ch;
             printf("*");
             i++;
        }
    }
}

int strong(char *str) {
    int len = strlen(str);
    int i, c = 0,d =0;
    if(len < 8){
        printf("\n\nYour passwords needs to be at least 8 char long\nTry again\n\n");
        getch();
        return 1;
    }

    for(i = 0; i<len; i++){
    if ((str[i] >= '!' && str[i] <= '/') ||
        (str[i] >= ':' && str[i] <= '@') ||
        (str[i] >= '[' && str[i] <= '`') ||
        (str[i] >= '{' && str[i] <= '~')) {
             c++;
    }
     if (isdigit(str[i])) {
             d = 1;
             }
    }

    if(c == 0){
         printf("\n\nNo special character found\nTry Again\n");
         getch();
         return 1;
    }else if(d == 0){
         printf("\n\nNo Digits found\nTry Again\n");
         getch();
         return 1;
    }else{
    }
        return 0;
    }



int checker(){
     int getCheck;
     char path[MAX_PATH];  //static to ensure the array's lifetime persists after the function returns
     CheckerINT = 1;
    // Get the path to the executable
    DWORD len = GetModuleFileName(NULL, path, MAX_PATH);

    if (len == 0) {
        perror("Error getting executable path");
        return NULL;
    }

    // Remove the executable name from the path
    for (int i = len - 1; i >= 0; i--) {
        if (path[i] == '\\') {
            path[i] = '\0';
            break;
        }
    }

    strcat(path, "\\");
    strcat(path,NameHolder);
    getch();
    DWORD attrib = GetFileAttributes(path);

    getCheck = (attrib != INVALID_FILE_ATTRIBUTES && (attrib & FILE_ATTRIBUTE_DIRECTORY));
    if(getCheck == 1){
        return 1;
    }else{
        return 0;
    }

 }

#endif // LIBRARY1_H_INCLUDED
