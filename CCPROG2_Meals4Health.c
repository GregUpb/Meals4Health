/******************************************************************************
 * This is to certify that this project is my own work, based on my personal
 * efforts in studying and applying the concepts learned. I have
 * constructed the functions and their respective algorithms and
 * corresponding code by myself. The program was run, tested, and debugged
 * by my own efforts. I further certify that I have not copied in part or
 * whole or otherwise plagiarized the work of other students and/or persons.
 *
 * Jacob Miguel P. Gregorio, DLSU ID# 12504157
 * Gabriel Angelo L. De Silva, DLSU ID# 12507083
 *****************************************************************************/

 /*
 * Description: A repository of cooking recipes and to provide tools to add recipes, generate shopping list, and to
recommend menu.
 * based on the CCPROG2 MP Specifications (AY 2025-2026 T1).
 * Programmed by: Jacob Miguel P. Gregorio and Gabriel Angelo L. De Silva
 * Last modified: 3/1/2026
 * Version: 0.0
 * [Acknowledgements: N/A]
 */
/* Notes:
2 Accounts: 1. Admin Account (Update Recipe Box) 2. User Account (Access Recipe)
Some features in Update Recipe Box may also be available in Access Recipe Box

*/
#include <stdio.h>
#include <string.h>
typedef char str20[21];
typedef char str15[16];
typedef char str70[71];

struct ingredientTag{
    double quantity; //amount in units
    str15 unit; //grams, cups, teaspoon, etc.
    str20 item; //Pangalan ng ingredient
};

struct recipeTag{
    str20 dish_name, classification; //classification must be starter, main, or dessert ONLY
    struct ingredientTag ingredient[20]; //list of food items
    str70 instruc[15]; //list of steps to prep and cook ingredients
    int serving; //how many ppl it is for
};

int login(str15 user, str15 pass){ //For Update Recipe Box Access
    printf("Enter Username: ");
    scanf("%s", user);
    printf("\nEnter Password: ");
    scanf("%s", pass);
    if (strcmp("admin",user)== 0 && strcmp("ad1234",pass) == 0){
        return 1;
    }
    else{
        return 0;
    }
}
//Update Recipe Box and its Features
void UpdateRecipeBox(struct recipeTag recipe[50], int calorie_count[50], struct ingredientTag food_item[50]){
    // 50 recipes and 50 food items/ingredients
}

//Access Recipe Box and its functions
void AccessRecipeBox(){
    
}

int main()
{
    int choice = 0;
    int exit = 0;
    int res;
    char ch;
    str15 user, pass;
    int calorie_count[50];

    do {

        printf("[1] - Update Recipe Box\n");
        printf("[2] - Access Recipe Box\n");
        printf("[3] - Exit\n");

        scanf("%d", &choice);
        scanf("%c", &ch);

        switch (choice)
        {
            case 1:
                res = login(user, pass);
                if (res == 1){
                    //insert update recipe box func call here
                }
                else {
                    printf("\nInvalid Username or Password");
                }
                break;
            case 2:
                // insert function call here
                break;
            case 3:
                printf("Maraming salamat sa paggamit ng aming aplikasyon");
                exit = 1;
                break;
            default:
            break;
        }

    } while (exit != 1);
    return 0;
}