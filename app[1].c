#include <stdio.h>
void admin();
void bin_details();
int b;

    void details();
    int saveToAnotherFile(int data);


    // main menu functions
     int user_reg();
     int user_login();
     int app_main_menu();
       // sub function
            void option_forward(int ad_menu_num);
            int username_check(char chk_user[50]);
            int user_check(char chk_user[50], char chk_pass[50]);
            void pass_enc(char pass[50], char encrypted_pass[50]);
            void user_enc(char user[50], char encrypted_user[50]);
            int cred_save(char sv_user[50], char sv_pass[50]);
            int user_login_menu();
            void check_status();
            void edit_database();
            void comp_fed();
            void deleteBin();
            void addBin();
            void back_menu();


                                 int binchkandsend(){

                                                int num;
                                                int binNumber;
                                                int Bin;
                                                int binFound=0;

                                                FILE* fp;
                                                printf("*********BIN FULL OR NOT**********\n");
                                                fp=fopen("bin.txt","r");
                                                printf("Enter the bin number:");
                                                scanf("%d",&binNumber);

                                                while(fscanf(fp, "%d", &Bin) == 1){//read the integers until the end of the file


                                                while(Bin==binNumber){
                                                printf("FULL=1\n or \n NOT=0\n");
                                                printf("Enter the Number:");
                                                scanf("%d",&num);







                                                if(num==1)
                                                {
                                                printf("The Bin number is sent");
                                                saveToAnotherFile(binNumber);
                                                }
                                                else if(num==0){
                                                    printf("Bin Not full");
                                                    break;
                                                }
                                                binFound=1;
                                                break;
                                                }

                                                }
                                                if(!binFound){
                                                    printf("THe bin Number is not in the database.\n");
                                                }
                                                fclose(fp);

                                 }




                                int saveToAnotherFile(int data) {
                                    FILE* fptr;

                                    fptr = fopen("bin_info.txt", "a"); // Open the file in append mode
                                    if (fptr == NULL) {
                                        printf("Error opening the file.\n");

                                    }

                                    fprintf(fptr, "BIN:%d\n", data); // Write data to the file
                                    fclose(fptr); // Close the file
                                }

                                int admin_menu()
{
    int ad_menu_num;
    for (;;)
    {
        printf("1.User registration\n");
        printf("2.User login\n");
        printf("3.Return to main menu\n");
        printf("Choose the desired option:");
        scanf("%d", &ad_menu_num);
        if (ad_menu_num != 1 && ad_menu_num != 2 && ad_menu_num != 3)
            printf("Wrong option number,Please try again----function admin_menu\n|\n|\n|");
        else
            break;
    }
    // Forwarding to user selection
    option_forward(ad_menu_num);
}



//user option forward
void option_forward(int ad_menu_num)
{
    switch (ad_menu_num)
    {
    case 1:
        user_reg();
        break;
    case 2:
        user_login();
        break;
    case 3:
        app_main_menu();
        break;
    default:
        printf("Value error----function option_forward");
        // call admin_menu function if needed
        break;
    }
}




// functions for admin menu options

        int user_reg()
        {
            char regUser[50], regPass[50], conregPass[50];
            int goback;
            printf("The username should be less than 50 charectors\n");
            printf("Enter new username : ");

            while (1)
            {
                scanf("%s", regUser);
                if (strlen(regUser) < 51 && strlen(regUser) > 5)
                {
                    //encrypt the data
                    char encryptedUser[50];
                    user_enc(regUser,encryptedUser);
                    if (username_check(encryptedUser) == 0)
                    {

                        while (1)
                        {
                            printf("Enter password: ");
                            scanf("%s", regPass);
                            if ( strlen(regPass) > 8 && strlen(regPass) < 51)
                            {
                                printf("Confirm  password: ");
                                scanf("%s", conregPass);
                                if (strcmp(regPass, conregPass) == 0)
                                {
                                    char encryptedPass[50];

                                    pass_enc(regPass,encryptedPass);
                                    cred_save(encryptedUser,encryptedPass);
                                    printf("User created successfully , Pess any key to go to admin menu\n");
                                    break;

                                }
                                else
                                    printf("Password doesnt match,retry.\n");
                            }

                            else
                                printf("Password should contain more than 8 cheractors and less than 51 cheractors]\n");
                        }
                    }
                    // check is this in database??
                    else
                        printf("Try input different username\n");
                }

                else
                    printf("Username should be between 51 and 5 cheractors\n");

                break;
            }

            printf("User created successfully , Pess any key to go to admin menu\n");
            scanf("%d",&goback);
            system("cls");
        }



        int user_login()
        {
            char pass[50], user[50],encryptedckuser[50], encryptedckpass[50];

            printf("Enter the username\n");
            scanf("%s", &user);
            printf("Enter the password\n");
            scanf("%s", &pass);

            user_enc(user,encryptedckuser);
            pass_enc(pass,encryptedckpass);
            user_check(encryptedckuser,encryptedckpass);
        }





        int app_main_menu(){


            system("cls");
            //call main menu function

            }




// sub functions for user registeration and user login
                        // encrypt username and password functions for sub functions
                           void back(){
                                   admin_menu();
                           }
                            void user_enc(char user[50],char encrypted_user[50])
                            {
                                for (int i = 0; i < strlen(user); i++)
                                {
                                    int j = i*i*i + 2;
                                    encrypted_user[i] = user[i] + j;
                                    encrypted_user[strlen(user)] = '\0';
                                }
                            }




                            void pass_enc(char pass[50],char encrypted_pass[50])
                            {
                                for (int k = 0; k < strlen(pass); k++)
                                {
                                    int l = k * k + 1;
                                    encrypted_pass[k] = pass[k] + l;
                                    encrypted_pass[strlen(pass)] = '\0';
                                }

                            }





                            // File handling functions
                            int username_check(char chk_user[50])
                            {
                                char stored_user[50];
                                FILE *cred_file;
                                cred_file = fopen("cred.txt", "r+");

                                while (fscanf(cred_file, "%s", stored_user) != EOF)
                                {


                                    if (strcmp(chk_user, stored_user)==0)
                                    {
                                        printf("Username exists in the file.\n");
                                        fclose(cred_file);
                                        return 1;
                                        break;
                                    }
                                }
                                printf("Username does not exist in the file.\n");
                                fclose(cred_file);
                                return 0;
                            }



                            int user_check(char chk_username[50],char chk_userpass[50]){

                                char stored_username[50],stored_userpass[50];
                                FILE *cred_file;
                                cred_file = fopen("cred.txt", "r+");

                                while (fscanf(cred_file,"%s  %s", stored_username,stored_userpass) != EOF)
                                {


                                    if (strcmp(chk_username, stored_username)==0 && strcmp(chk_userpass, stored_userpass)==0 )
                                    {
                                        printf("User exists in the database.\n");
                                        fclose(cred_file);
                                        user_login_menu();


                                    }
                                    else
                                        printf("Username or password unavailable");
                                }
                                fclose(cred_file);
                                return 0;
                            }



                            int cred_save(char sv_user[50], char sv_pass[50])
                            {
                                FILE *cred_file;
                                cred_file = fopen("cred.txt", "a+");
                                fprintf(cred_file, "\n%s   %s", sv_user, sv_pass);
                                fclose(cred_file);
                            }

                            int user_login_menu(){
                                    int user_login_menu_num;
                                    printf("\n\n\1.Check Bin status\n2.Add/Remove bins\n3.Check complaints and feedbacks\n");
                                    printf("Enter option");
                                    scanf("%d",&user_login_menu_num);
                                    switch(user_login_menu_num){
                                    case 1:
                                        check_status();
                                        break;
                                    case 2:
                                        edit_database();
                                        break;
                                    case 3:
                                        comp_fed();
                                        break;
                                    default:
                                        printf("Please retry");
                                        user_login_menu();
                                    }

                            }
                            //function for see the filled bins details
                            void check_status(){
                                char bin_stat[50];
                                FILE *fptr;
                                fptr = fopen("bin_info.txt","r");
                                printf("The filled bins are\n");
                                while(fscanf(fptr,"%s",&bin_stat)==1){
                                    printf("%s\n",bin_stat);
                                }
                            }

                            // functions for add and remove bins
                            void edit_database(){
                                int edit;
                                printf("\n\n\n1.Delete bin\n2.Add bin\n");
                                printf("Choose the desired option :");
                                scanf("%d",&edit);
                                (edit==1?deleteBin():(edit==2?addBin():printf("Wrong input,please try again")));

                            }

                            void comp_fed(){
                                char comp[1000];
                                FILE *comp_file;
                                comp_file=fopen("comp_data.txt","r");
                                while(fscanf(comp_file,"%s",&comp)==1){
                                    printf("%s\n",comp);
                                }

                            }




                            void deleteBin() {
                            printf("Now you can delete bins\n");

                            FILE *delete_bin;
                            delete_bin=fopen("bin.txt", "a+");
                            int line_number = 0;
                            int line;
                            printf("List of bin numbers:\n");
                            while (fscanf(delete_bin, "%d", &line) == 1) {
                                printf("%d. %d\n", ++line_number, line);
                            }

                            fclose(delete_bin);
                            int bin_to_delete;
                            printf("Enter the number of the bin you want to delete: ");
                            scanf("%d", &bin_to_delete);

                            delete_bin = fopen("bin.txt", "a+");
                            FILE *tempFile = fopen("temp.txt", "a+");

                            line_number = 0;

                            while (fscanf(delete_bin, "%d", &line) == 1) {
                                ++line_number;

                                if (line_number != bin_to_delete) {
                                    fprintf(tempFile, "%d\n", line);
                                }
                            }

                            fclose(delete_bin);
                            fclose(tempFile);

                            remove("bin.txt");
                            rename("temp.txt", "bin.txt");

                            printf("Bin number %d has been deleted from the file.\n", bin_to_delete);
                        }





                                void addBin() {
                                printf("Now you can add bins\n");


                                FILE *list_bin = fopen("bin.txt", "a+");

                                int bin;
                                int bin_count = 0;

                                printf("Current list of bin numbers:\n");
                                while (fscanf(list_bin, "%d", &bin) == 1) {
                                    printf("%d. %d\n", ++bin_count, bin);
                                }

                                fclose(list_bin);
                                int new_bin;
                                printf("Enter the bin you want to add: ");
                                scanf("%d", &new_bin);

                                FILE *add_bin = fopen("bin.txt", "a+");

                                fprintf(add_bin, "%d\n", new_bin);

                                fclose(add_bin);

                                printf("Bin %d has been added to the file.\n", new_bin);
                            }






int main()
{
    int a;
      details();

    printf(" **welcome to our project**\n");
    printf(" What is yourinput option\n\t1.BIN\n \t2.COMPLAIN\n \t3.ADDMIN\n");
    scanf("%d",&a);
    switch(a)
    {
    case(1):
       printf("\t\tBIN DETAILS\n");
       bin_details();
       break;
    case(2):
     printf("\t\tCOMPLAIN DETAILS\n");
    int choise ;
   char Name [100];
    char number [100];
    char department [30];
    char problem [100];
    char Feedback [100];
    FILE *file;
    char data[100];

              printf("\t\t\t\t*******Complaint and Feedback Service****\n\n");

              printf("\t\t\t\t\t\t1.Complaint.\n \t\t\t\t\t\t2.Feedback.\n");


    while (1) {
        printf("\tEnter your choice:");
        scanf("%d",&choise);

        if(choise == 1)
        {
            printf("\t\t\t\t*Complaint*\n\n");

            printf("\t\t\t\t1.Enter your name:");
            scanf("%s",&Name);
            printf("\t\t\t\t\tHello %s\n",Name);

            printf("\t\t\t\t2.Enter your student number:");
            scanf("%s",&number);

            printf("\t\t\t\t3.what is your department(ECS,PE,A.CHEM,MI,CS):");
            scanf("%s",&department);

            printf("\t\t\t\t4.Tell what is your problem:",problem);
            getchar();
            fgets(problem, sizeof(problem),stdin);

            file = fopen("comp_data.txt","a");

             if (file == NULL)
             {
        printf("Error opening the file.\n");
        return 1;
    }
       fprintf(file,"\t\t\t\t\t*******Complaint and Feedback Service****\n\n");

       fprintf(file,"\t\t\t*Complaint*\n\t1.Name:%s\n\t2.Student Number: %s\n\t3.Department: %s\n\t4.problem: %s\n\n",Name,number,department,problem);

       fclose(file);

       printf("\t\t\t\tComplaint data has been added to comp_data.txt.\n");

       break;

        }
        else if(choise == 2){
            printf("\t\t\t\t*Feedback*\n");

            printf("\t\t\t\t1.Enter your name:");
            scanf("%s",&Name);
            printf("\t\t\t\t\tHello %s\n",Name);

            printf("\t\t\t\t2.Enter your student number:",number);
            scanf("%s",&number);

            printf("\t\t\t\t3.what is your department(ECS,PE,A.CHEM,MIT,ELEC,CS):",department);
            scanf("%s",&department);

            printf("\t\t\t\t4.Tell what is your Feedback:",Feedback);

            getchar();
            fgets(Feedback, sizeof(Feedback),stdin);

             file = fopen("comp_data.txt","a");

             if (file == NULL){
        printf("Error opening the file.\n");
        return 1;
    }

            fprintf(file,"\t\t\t*Feedback*\n\t1.Name:%s\n\t2.Student Number: %s\n\t3.Department: %s\n\t4.Feedback: %s\n\n",Name,number,department,Feedback);

       fclose(file);

       printf("\t\t\t\tFeedback data has been added to comp_data.txt.\n");

            break;
        }
        else{
            printf("Invalid Input");
        }
   }


     break;
     case (3):
     printf("\t\tADDMIN\n");
     admin();
     break;
     default:
     printf("\tinvalid input\n");
    }


}


void details() {
    int b, i;

    printf("\t***WELCOME***\n");
    printf("\tHi Buddy!\n");
    printf("Are you a...\n");
    printf("1. Student\n");
    printf("2. Academic Staff\n");
    printf("3. Non-academic Staff\n");

    scanf("%d", &b);

    switch (b) {
        case 1:
            printf("Enter your Student Number: ");
            char stu[100];
            scanf("%s", stu);
            // Process student information here
            break;
        case 2:
            printf("Enter your name: ");
            char aca[100];
            scanf("%s", aca);
            printf("Enter your position: ");
            char job1[100];
            scanf("%s", job1);
            // Process academic staff information here
            break;
        case 3:
            printf("Enter your name: ");
            char nona[100];
            scanf("%s", nona);
            printf("Enter your position: ");
            char job2[100];
            scanf("%s", job2);
            // Process non-academic staff information here
            break;
        default:
            printf("Invalid input\n");
    }
}







void bin_details(){
    binchkandsend();
}


void admin(){

    // Calling admin menu function
        admin_menu();

}
