#include <stdio.h>
#include <windows.h>


void createAcc(int* errorcache);
void login(int* errorcache);



int main() {
    int errorcache=0;
    printf("Hello, World!\n");
    char enter[2];
    char choice;


    printf("Type what you want to do?\n");
    printf("1)Create an account\n"
           "2)Login to your account\n"
           "3)Admin panel\n");
    fflush(stdin);
    scanf("%c",&choice);

    if(choice=='1')
    {
        createAcc(&errorcache);

        if(errorcache!=0)
        {
            printf("###ERROR CODE:%d\n",errorcache);
        }

    }
    else if(choice=='2')
    {


        login(&errorcache);
        if(errorcache!=0)
        {
            printf("###ERROR CODE:%d\n",errorcache);
        }


    }



    printf("Press enter to continue...");
    fflush(stdin);
    fgets(enter,2,stdin);


    return 0;
}

void createAcc(int* errorcache)
{
    char username[10];
    char password[10];
    FILE* Filepointer;
    int lengthofuser;
    int lengthofpass;
    char buffer;
    char enter[2];

    //----------TAKE INPUT----------------
    int found=1;
    while (found==1 ) {

        system("cls");
        printf("Enter your username it should be less than 9 letters and it cant have any space in it...\n");
        scanf("%s", username);

        //#######################################


        //----------------CALC LENGTH----------------

        for (lengthofuser = 0; username[lengthofuser] != '\0'; ++lengthofuser)
            //printf("lengthofuser: %d\n", lengthofuser); //debug

        //#################################################


        //------------------CHECK IF THAT USERNAME ALREADY EXISTS-----------------

        Filepointer = fopen("accounts.txt", "r");
            if (Filepointer == NULL){
            printf("ERROR 13\n");
            }
            else {

                int counter = 0;
                found = 0;
                int check = 0;
                buffer = fgetc(Filepointer);
                if(buffer=='\n')
                {
                    printf("First ROW detected!\n");
                }
                else
                {
                    printf("NO FIRST ROW DETECTION! EXITING THE PROGRAM!\n");
                    fclose(Filepointer);
                    *errorcache=111;

                    return;

                }
                while (found != 1 && buffer!=EOF) {

                buffer = fgetc(Filepointer);
                //printf("BUFFER=> %d\n\n", buffer);  //debug
                //printf("USERNAME=> %d\n\n", username[counter]);    //debug
                //printf("COUNTER VALUE=> %d\n\n",counter);


                if (buffer == username[counter] || (buffer == '|' && username[counter] == '\0')) {
                    check = 1;
                    //printf("if'in içi\n\n"); //debug
                    //printf("BUFFER:%c\n",buffer);
                    if (buffer == '|') {
                        found = 1;
                        printf("This username already exists please enter a different one!\n");
                        printf("|press enter to continue...");
                        fflush(stdin);
                        fgets(enter,2,stdin);
                    }

                } else {
                    check = 0;
                }

                counter++;


                if (check == 0) {
                    while (buffer != '|' && buffer != EOF && buffer!='\n')  {
                        buffer = fgetc(Filepointer);
                        //printf("buffer in while: %c\n", buffer); //debug
                    }
                    //printf("everything removed!\n");
                    counter = 0;
                }


                //printf("enter a value to cont."); // debug
                //int temp; //debug
                //scanf("%d", &temp); //debug

            }

        }

        fclose(Filepointer);

    }

    //#########################################





    //----------------WRITING TO FILE----------------

    Filepointer = fopen("accounts.txt","a");// it opens the file in appending mode
    if(Filepointer==NULL) {
        printf("you couldn't open it!\n");
    }

    else
    {

        int counter=0;




        fputc('\n',Filepointer);
        while (counter < lengthofuser && username[counter] != '\0') {
            //printf("we're currently adding this char: %c\n", username[counter]);

            fputc(username[counter], Filepointer);
            counter++;
        }

    }

    fclose(Filepointer);

    //#################################################



    //----------TAKE INPUT----------------



        system("cls");
        printf("Enter your password it should be less than 9...\n");
        scanf("%s", password);

        //#######################################


        //----------------CALC LENGTH----------------

        for (lengthofpass = 0; password[lengthofpass] != '\0'; ++lengthofpass) {
            //printf("lengthofpass: %d\n", lengthofpass); //debug
        }

        //#################################################





    //#########################################





    //----------------WRITING TO FILE----------------

    Filepointer = fopen("accounts.txt","a");// it opens the file in appending mode
    if(Filepointer==NULL) {
        printf("you couldn't open it!\n");
    }

    else
    {

        int counter=0;




        fputc('|',Filepointer);
        while (counter < lengthofpass && password[counter] != '\0') {
            //printf("we're currently adding this char: %c\n", password[counter]);

            fputc(password[counter], Filepointer);
            counter++;
        }

    }

    fclose(Filepointer);


}

void login(int* errorcache){

    char username[10];
    char password[10];
    char storedpass[10]="";
    FILE *Filepointer;
    int lengthofuser;
    int lengthofpass;
    char buffer;
    char enter[2];

    int found = 0;

    fflush(stdin);
        system("cls");
        printf("Enter your username...\n");
        scanf("%s", username);

        //#######################################


        //----------------CALC LENGTH----------------

        for (lengthofuser = 0; username[lengthofuser] != '\0'; ++lengthofuser)
        {
        //printf("lengthofuser: %d\n", lengthofuser); //debug
        }

        //#################################################

        //------------------CHECK IF THAT USERNAME ALREADY EXISTS-----------------

        Filepointer = fopen("accounts.txt", "r");
        if (Filepointer == NULL){
            printf("ERROR 13\n");
        }
        else {

            int counter = 0;
            found = 0;
            int check = 0;
            buffer = fgetc(Filepointer);
            if(buffer=='\n')
            {
                //printf("First ROW detected!\n");
            }
            else
            {
                printf("NO FIRST ROW DETECTION! EXITING THE PROGRAM!\n");
                fclose(Filepointer);
                *errorcache=111;

                return;

            }
            while (found != 1 && buffer!=EOF) {

                buffer = fgetc(Filepointer);
                //printf("BUFFER=> %d\n\n", buffer);  //debug
                //printf("USERNAME=> %d\n\n", username[counter]);    //debug
                //printf("COUNTER VALUE=> %d\n\n",counter);


                if (buffer == username[counter] || (buffer == '|' && username[counter] == '\0')) {
                    check = 1;
                    //printf("if'in içi\n\n"); //debug
                    //printf("BUFFER:%c\n",buffer);
                    if (buffer == '|') {
                        found = 1;
                        //printf("This username already exists please enter a different one!\n");

                        //------------------storing the password of that username
                        //int holderofi;
                        buffer= fgetc(Filepointer);
                        for (int i = 0; buffer!='\n'; ++i)
                        {
                            if(buffer==EOF)
                            {
                                break;
                            }
                            //printf("INSIDE PASS PART\n"); //debug
                            storedpass[i]=buffer;
                            buffer= fgetc(Filepointer);
                            //printf("|press enter to continue..."); //debug
                            //fflush(stdin);    //debug
                            //fgets(enter,2,stdin);     //debug
                            //holderofi=i;


                        }
                       // storedpass[holderofi+1]='\0';
                        //printf("####### %d",storedpass[holderofi+1]);

                        //printf("password:%s\n",storedpass);
                        //printf("|press enter to continue...");
                        //fflush(stdin);
                        //fgets(enter,2,stdin);
                    }

                } else {
                    check = 0;
                }

                counter++;


                if (check == 0) {
                    while (buffer != '|' && buffer != EOF && buffer!='\n') {
                        buffer = fgetc(Filepointer);
                        //printf("buffer in while: %c\n", buffer); //debug
                    }
                    //printf("everything removed!\n");
                    counter = 0;
                }


                //printf("enter a value to cont."); // debug
                //int temp; //debug
                //scanf("%d", &temp); //debug

            }

        }

        fclose(Filepointer);

    //#########################################

    //--------------------TAKING INPUT FOR PASSWORD FROM USER------

    printf("Please enter your password its case sensitive\n");
    scanf("%s",password);
    //printf("THAT IS THIS: %d\n",storedpass[7]);
    for (lengthofpass = 0; storedpass[lengthofpass]!='\0'; ++lengthofpass)
    {

        //printf("PASS: %c\n",storedpass[lengthofpass]);
        //printf("%d\n",lengthofpass);
        //printf("|press enter to continue...");
        //fflush(stdin);
        //fgets(enter,2,stdin);
    }
    int checker=1;
    for (int i = 0; i <= lengthofpass && checker==1; ++i)
    {
        //printf("STORED:%c\n",storedpass[i]);
        //printf("USER:%c\n",password[i]);
        if(storedpass[i]==password[i])
        {
            checker=1;
            //printf("BOTH IN:%c\n",password[i]);
            if(storedpass[i]=='\0')
            {
                printf("correct password you're in!\n");
                printf("|press enter to continue...");
                fflush(stdin);
                fgets(enter,2,stdin);
                break;
            }
        }
        else
        {
            checker=0;
        }


        //printf("|press enter to continue...");
        //fflush(stdin);
        //fgets(enter,2,stdin);

    }
    printf("|press enter to continue LAST CALL...");
    fflush(stdin);
    fgets(enter,2,stdin);


}
