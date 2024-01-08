#include <stdio.h>


void createAcc(char* username);


int main() {
    printf("Hello, World!\n");
    char username[10];
    createAcc(username);
    printf("Value outside func. for username:%s\n",username);











    return 0;
}

void createAcc(char* username)
{
    FILE* Filepointer;
    int length;
    char buffer;

    //----------TAKE INPUT----------------
    int found=1;
    while (found==1 ) {


        printf("%s\n", username);
        printf("Enter your username it should be less than 9 letters and it cant have any space in it...\n");
        scanf("%s", username);

        //#######################################


        //----------------CALC LENGTH----------------

        for (length = 0; username[length] != '\0'; ++length)
            printf("length: %d\n", length);

        //#################################################


        //------------------CHECK IF THAT USERNAME ALREADY EXISTS-----------------

        Filepointer = fopen("accounts.txt", "r");
        if (Filepointer == NULL) {
            printf("ERROR 13\n");
        } else {
            char buffer;
            int counter = 0;
            found = 0;
            int check = 0;
            while (found != 1 && buffer!=EOF) {

                buffer = fgetc(Filepointer);
                printf("BUFFER=> %d\n\n", buffer);
                printf("COUNTER=> %d\n\n", username[counter]);


                if (buffer == username[counter] || (buffer == '\n' && username[counter] == '\0')) {
                    check = 1;
                    printf("if'in içi\n\n");
                    if (buffer == '\n') {
                        found = 1;
                        printf("We found the username which we're lookin for!\n");
                    }

                } else {
                    check = 0;
                }

                counter++;


                if (check == 0) {
                    while (buffer != '\n' && buffer != EOF) {
                        buffer = fgetc(Filepointer);
                        printf("buffer in while: %c\n", buffer);
                    }
                    counter = 0;
                }


                //printf("devam etmek icin bir deger gir");
                //int temp;
                //scanf("%d", &temp);

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
        while (counter < length && username[counter]!='\0') {
            printf("we're currently adding this char: %c\n", username[counter]);

            fputc(username[counter], Filepointer);
            counter++;
        }

    }

    fclose(Filepointer);

    //#################################################


    scanf("%s",username);

}
