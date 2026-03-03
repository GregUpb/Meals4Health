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

struct ingredientTag
{
    double quantity; //amount in units
    str15 unit; //grams, cups, teaspoon, etc.
    str20 item; //Pangalan ng ingredient
};

struct recipeTag
{
    str20 dish_name, classification; //classification must be starter, main, or dessert ONLY
    struct ingredientTag ingredient[20]; //list of food items
    str70 instruc[15]; //list of steps to prep and cook ingredients
    int serving; //how many ppl it is for
};

int login(str15 user, str15 pass)
{ //For Update Recipe Box Access
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
void UpdateRecipeBox(struct recipeTag recipe[50], int calorie_count[50], struct ingredientTag food_item[50])
{
    // 50 recipes and 50 food items/ingredients
}

// FUNCTIONS UNDER "UPDATE RECIPE BOX" FUNCTION

void updAddFoodCalorieInfo(char foodItem [50], int quantity, str20 unit, int calorie_count)
{
// when you add (scanf), ask for the food item, quantity, and unit. (for data, refer to website in specs, we can prepare a txt file for this)
}

void updViewFoodCalorieChart()
{
// display what you added, order: |Food Item    Quantity    Unit    Calories| (show only 10 items per screen. N = view next 10 items, X = exit)
}

void updSaveCalorieInfo()
{
// text file di pa ko marunong dito
}

void updLoadCalorieInfo()
{
// sa file eme ulit di pa ko marunong
}

void updAddRecipe()
{
//asks user to input name of dish, classification (starter, main, dessert ONLY), number of servings, different ingredients + instructions. all names must be unique.
//no blanks allowed, at least 1 ingredient and at least 1 instruction step per recipe. (may call AddIngredient and AddStep). after adding reipce, user go back to URB Menu.
}

void updModifyRecipe()
{
//list of all recipe titles will be displayed in ALPHABETICAL order (call ListRecipeTitles). user inputs name of dish to modify. user is then asked which info will be changed.
}

// UNDER MODIFY RECIPE, THERE ARE SUB FUNCTIONS\

void updAddIngredient()
{
//new ingredient is added to current set of ingredients, user brought back to modify menu
}

void updDeleteIngredient()
{
//allows the user to select which existing ingredients to delete. (input could be number 1 until no. of ingredients he has). cannot delete if only 1 ingredient left.
//always brought back to modify menu after
}

void updAddStep()
{
//asked WHERE the new step will be put in. user is then asked to input the new instruction. can be inserted anywhere, make sure there are no empty/skipped steps. 
//always brought back to modify menu after
}

void updDeleteStep()
{
//similar to DeleteIngredient
//selects which existing step to delete, (input could be number 1 until no. of steps he has). cannot delete if only 1 step left.
//always brought back to modify menu after
}

void updReturnToURBM() // URBM (Update Recipe Box Menu)
{
//choice of user to go back to URBM
}

// end of modify recipe sub-functions

void updDeleteRecipe()
{
//list of all recipes displayed in ALPHABETICAL order (call ListRecipeTitles), user inputs name of dish to delete
//display "Recipe is not in the list” if the input is not strcmp=0 with the name of the dish
//when a recipe is deleted, everything under it is also deleted (ingredients + instructions etc)
}

void ListRecipeTitles() //universal function methinks
{
//provides a list of all recipe titles in ALPHABETICAL ORDER, after the display, user is brought back to UPDATE MODE MENU.
//order is based on ASCII value
}

void updScanRecipes()
{
//displays each recipe one at a time until all have been displayed. all info per recipe should also be displayed. 
//for each recipe info shown, number of calories for EACH of the food item should also be displayed and the TOTAL CALORIES of the RECIPE (not per person).
/*
FORMAT:
<Recipe Title> <Number of Servings> <Total Calories><next line>
Ingredients:<next line>
<Quantity> <Unit> <Food Item> <Calories><next line>
<Quantity> <Unit> <Food Item> <Calories><next line>
: :
<Quantity> <Unit> <Food Item> <Calories><next line>
<next line>
Procedure:<next line>
1. <step1><next line>
2. <step 2><next line>
: : */
}

void updSearchRecipeByTitle()
{
//shows list of all recipes (ALPHABETICAL order, call ListRecipeTitles). then ask to type the recipe title to show respective info.
//if title exists, show all info. 
//bring user back to UPDATE MODE MENU
}

void updExportRecipes()
{
//DI KO TO ALAAAAAAAAAAAM next time na
}

void updImportRecipes()
{
//DI KO RIN ALAM
}

void updReturnMainMenu()
{
//allows user to quit UPDATE MODE and return to MAIN MENU. information in lists should be cleared after this option.
}

// end of UPDATE RECIPE BOX FUNCTIONS


//Access Recipe Box and its functions
void AccessRecipeBox()
{
    
}

// start of ACCESS RECIPE BOX FUNCTIONS

void accImportRecipes()
{
//file eme ulit ughhh
}

void ListRecipeTitles()
{
//list of all recipe titles (ALPHABETICAL order). same as in UPDATE MODE (ig no need to use upd & acc prefixes respectively for this function)
//after display, user brought back to ACCESS MODE MENU
}

void accScanRecipes()
{
//display each recipe one at a time until all are displayed. all info should also be displayed.
//choice to view the next or previous property or exit the scanning/viewing. 
//sequence of display is ALPHABETICAL ORDER (recipe title). 
//if user exits OR reached the end of the list, bring back to ACCESS MODE MENU
}

void accSearchRecipeByTitle()
{
//list of all recipe titles (ALPHABETICAL ORDER, call ListRecipeTitles)
}

void accGenerateShoppingList()
{
//show list of all recipe titles (call ListRecipeTitles), asks user which recipe to generate a shopping list for.
//user also asked how many people they will cook for.
//*Recomputation may be needed based on number of servings of the recipe. (basically like if binago no. of people, do the recompute)
//display all on screen, user then brought back to ACCESS MODE MENU.
}

void accScanRecipesByIngredients()
{
//ask user to TYPE (scanf) an ingredient (just the food item. e.g. Potato)
//show the recipe info of all recipes that use said ingredient (e.g. find all dishes that use Potato)
//choice to view next or previous property or exit the scanning/viewing
//sequence of display is ALPHABETICAL (recipe title)
//when user exits OR reached end of the list, bring back to ACCESS MODE MENU
}

void accRecommendedMenu()
{
//asks user to INPUT (scanf) a target calorie intake for 1 person.
//program randomly chooses 1 main course from list of recipes. if calorie count of main course is not enough, a starter is also included.
//if both are not enough, a dessert is also recommended. 
//if there is no available course, skip and show a recipe of the available course (basically, if wala ka nilagay na starter na recipe, skip that then it will show mains and desserts)
//menu should not exceed calorie intake. if ingredient (in recipe) is not included in list of food-calorie info, assume that the calorie count is 0. (e.g. water is an ingredient but not in food-calorie info list. water = 0 cal)
//show recipe info for suggested menu one at a time from starter -> main -> dessert.
//bring user back to ACCESS MODE MENU
}

void accReturnMainMenu()
{
//choice to quit ACCESS MODE MENU and go back to MAIN MENU. info in the lists should be cleared after this option.
}

// end of ACCESS RECIPE BOX FUNCTIONS
int main()
{
    int choice = 0;
    int exit = 0;
    int res;
    char ch;
    str15 user, pass;
    int calorie_count[50];

    do 
    {

        printf("[1] - Update Recipe Box\n");
        printf("[2] - Access Recipe Box\n");
        printf("[3] - Exit\n");

        scanf("%d", &choice);
        scanf("%c", &ch);

        switch (choice)
        {
            case 1:
                res = login(user, pass);
                if (res == 1)
                {
                    //insert update recipe box func call here
                }
                else 
                {
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

    } 
    while (exit != 1);
    return 0;
}
