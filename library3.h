#ifndef LIBRARY1_H_INCLUDED
#define LIBRARY1_H_INCLUDED
#define SIZE 100
#endif // LIBRARY1_H_INCLUDED

int UpdateCred(int fileSelector, char* getUser3){
    char c;
    FILE *ptr;
    FILE *tmp;
    char platform[SIZE], user[SIZE], pass[SIZE], word[SIZE], word1[SIZE], word2[SIZE], load[SIZE], path[100], path2[100];
    int Turner, s, m, found,position;
    strcpy(path, getUser3);
    strcpy(path2,getUser3);
    strcat(path2,"\\tmp.txt");
     switch(fileSelector){
            case 0:
            strcat(path,"\\Social_Crd.txt");
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
          printf("You will have to Add credentials first!");
                fclose(ptr);
                getch();
                return 1;
          }

          fseek(ptr,0,SEEK_END);
          position = ftell(ptr);
          if(position < 1){
                printf("\nYou will have to enter the credentials first.");
                getch();
                return 1;
          }else{
                printf("At any point you can type: 'Out' to Exit\n\n");
          }


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
    found = 0; m = 1;

        fseek(ptr,0,SEEK_SET);

        while(fscanf(ptr, "%[^,], %[^,], %s\n", word, word1, word2) == 3){
        if (!(strcmp(word, platform)) && !(strcmp(word1, user)) && !(strcmp(word2, pass))) {
                found = 1;
                break;
            }
        }

        if(found == 1){
            fseek(ptr,0,SEEK_SET);
            printf("Your Credentials were found you can edit them from here!\n\n");
            tmp = fopen(path2,"a+");
            while (fscanf(ptr, "%[^,], %[^,], %s\n", word, word1, word2) == 3) {
                //Here if the platform,user and pass matched enter
                if (!(strcmp(word, platform)) && !(strcmp(word1, user)) && !(strcmp(word2, pass))) {
                    Updatep:
                    printf("E0 - to edit Platform\nE1 - to edit User\nE2 - to edit Password\n");
                    scanf("%d", &s);
                    if(s == 0){
                           printf("Update the Platform Name: ");
                           scanf("%s", &word);
                           strcpy(load,word);
                    }else if(s == 1){
                           printf("Update the User Name: ");
                           scanf("%s", &word1);
                           strcpy(load,word1);
                    }else if(s == 2){
                           printf("Update the Password: ");
                           //scanf("%s", &word2);
                           astric(&word2);
                           encript(&word2);
                           strcpy(load,word2); // All this coping is so that "load array"
                    }else{
                       printf("You have enter a Wrong integer");
                       goto Updatep;
                    }

                    fprintf(tmp,"%s,",word);
                    fprintf(tmp,"%s,",word1);
                    fprintf(tmp,"%s\n",word2);
                }else{
                  //This if condition is to check if there is any match to the edited combination Already || checking duplication
                  if(s == 0){
                    Turner = (!(strcmp(word, load)) && !(strcmp(word1, user)) && !(strcmp(word2, pass)));
                  }else if(s == 1){
                    Turner = (!(strcmp(word, platform)) && !(strcmp(word1, load)) && !(strcmp(word2, pass)));
                  }else if(s == 2){
                    Turner = (!(strcmp(word, platform)) && !(strcmp(word1, user)) && !(strcmp(word2, load)));
                  }else{ printf("Error");};

                  if(Turner){
                      printf("This Credential Already Exits !\n\n");
                      Hoop:
                      printf("select: 1 to continue?\n");
                      printf("select: 0 to Exit editing the file\n");
                      scanf("%d", &m);
                      if(m){
                          continue;
                      }else if(!m){
                          break;
                      }else{
                        printf("Incorrect choice!");
                        goto Hoop;
                      }
                  }else{
                      fprintf(tmp,"%s,",word);
                      fprintf(tmp,"%s,",word1);
                      fprintf(tmp,"%s\n",word2);
                  }
                }
        }

        }else{
                printf("Your entry do not match with any of the Credentials stored Currently!\n\n");
                printf("Enter to Submit");
                fflush(stdin);
                c = getchar();
                fclose(ptr);
                fclose(tmp);
                return 1;
        }

        fseek(tmp,0,SEEK_SET);
        while (fscanf(tmp, "%[^,], %[^,], %s\n", word, word1, word2) == 3) { //This loop is to check if the duplication exists
                if(s == 0){
                    Turner = (!(strcmp(word, load)) && !(strcmp(word1, user)) && !(strcmp(word2, pass)));
                  }else if(s == 1){
                    Turner = (!(strcmp(word, platform)) && !(strcmp(word1, load)) && !(strcmp(word2, pass)));
                  }else if(s == 2){
                    Turner = (!(strcmp(word, platform)) && !(strcmp(word1, user)) && !(strcmp(word2, load)));
                  }else{ printf("Error"); };

            if (Turner) {
                   found++;
                }
            }

        fclose(ptr);
        fclose(tmp);

        if(found > 2){
            m = 0;
            printf("\nThis Credential Already Exits !\n");
            printf("Exit editing file.\n");
            getch();
        }

        if(m == 1){
        // Remove the original file
            remove(path);
        // Rename the temporary file to the original file
            rename(path2, path);
        }else if (m == 0 ||(found > 2)){
            remove(path2);
        }

        printf("\nEnter to Submit");
        fflush(stdin);
        c = getchar();
        return 1;
};
