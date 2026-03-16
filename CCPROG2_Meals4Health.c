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
 * Last modified: 3/16/2026
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
    int ingcount; //how many ingredients a recipe has
    int stepcount; //how many instructions a recipe has
};

void strwspace(char string[], int maxSize) //NOTE on maxSize value: str20 -> 21, str15 -> 16, str70 ->71
{ 
	int i;
	char ch;
	scanf("%c", &ch);
    while (ch == '\n')
    {
        scanf("%c", &ch);
    }

    for (i = 0; i < maxSize - 1 && ch != '\n'; i++)
    {
        string[i] = ch;
	    scanf("%c", &ch);
    }
    string[i] = '\0'; 
    while (ch != '\n') 
    {
    scanf("%c", &ch);
    }

}

int hanapinIndex(struct recipeTag recipe[], int recipeCount, char target[])
{
    int i, foundIndex = -1;
    for (i = 0; i < recipeCount && foundIndex == -1; i++) 
    {
        if (strcmp(recipe[i].dish_name, target) == 0) 
        {
            foundIndex = i;
        }
    }

    return foundIndex;
}

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

void updAddFoodCalorieInfo(char foodItem [50], int quantity, str20 unit, int calorie_count) // struct ang param
{
// when you add (scanf), ask for the food item, quantity, and unit. (for data, refer to website in specs, we can prepare a txt file for this)
    printf("Enter Food Item: ");
    scanf("%c", &foodItem);
    printf("\nEnter Quantity: ");
    scanf("%d", &quantity);
    printf("\nEnter Unit: ");
    scanf("%c", &unit); //use strwspace func
    printf("\nEnter Calorie Count: ");
    scanf("%d", &calorie_count);
}

void updViewFoodCalorieChart(char foodItem [50], int quantity, str20 unit, int calorie_count)
{
// display what you added, order: |Food Item    Quantity    Unit    Calories| (show only 10 items per screen. N = view next 10 items, X = exit)
    int i;
    char ch;
    int j = 0;
    for (i = 0; i < 50; i++);
    {
        for (i = 0; i < 10; i++);
        {
            printf("\nFood Item: %c   Quantity: %d    Unit: %c    Calories: %d", foodItem, quantity, unit, calorie_count);
        }
        if (i == 10)
        {
            printf("Input: ");
            scanf("%c", &ch);
            if (ch == 'N')
            {
                do
                {
                printf("\nFood Item: %c   Quantity: %d    Unit: %c    Calories: %d", foodItem, quantity, unit, calorie_count);
                j++;
                }
                while (j < 10);
            }
            j = 0; //resets the index of j para pwede ulit-ulitin until 10 yung mga susunod na N. (or idk fix this nalang, di ko alam if gagana to)
        }
    }
}

void updSaveCalorieInfo()
{
// text file di pa ko marunong dito
}

void updLoadCalorieInfo()
{
// sa file eme ulit di pa ko marunong
}

void updAddRecipe(struct recipeTag recipe[50], str20 recipeTag->dish_name, str20 recipeTag->classification, int recipeTag->serving, struct ingredientTag ingredient[20], str70 recipeTag->instruc[15]) //PLS HELP
{
    int r, i;
    for (r = 0; r < 50; r++)
    {
        printf("\nEnter Dish Name: ");
        scanf("%s", recipe[r].dish_name);
            for (i = 0; i < 50; i++)
            {
                if (strcmp(recipe[r].dish_name, recipe[i].dish_name) == 0)
                printf("\nThat Dish Name already exists! Reinput another");
                scanf("%s", recipe[r].dish_name);
            }
                i = 0;
        printf("\nEnter Classification: ");
        scanf("%s", recipe[r].classification);
            if (strcmp("starter", recipe[r].classification) != 0 && strcmp("main", recipe[r].classification) != 0 && strcmp("dessert", recipe[r].classification) != 0)
            {
                printf("\nThat is an invalid classification! Reinput classification.");
                scanf("%s", recipe[r].classification);
            }
        printf("\nEnter Number of Servings: ");
        scanf("%d", &serving);
        //how to implement that there should be AT LEAST 1 ingredient AND instruction
        printf("\nEnter Ingredients: ");
        scanf("%s", ingredient[r]);
        do
        {
            printf("\nYou need at least 1 Ingredient!\nEnter Ingredients: ");
            strwspace(string, maxSize)
        } while (strcmp("", ingredient[r]) == 0);
        printf("\nEnter Instructions: "); //can call AddIngredient and AddStep for this function
        scanf("%s", instruc[r]);
        do
        {
            printf("\nYou need at least 1 Instruction!\nEnter Instruction: ");
            strwspace(string, maxSize)
        } while (strcmp("", instruc[r]) == 0);
    }
    //bring back to URB Menu
}

void updModifyRecipe(struct recipeTag recipe[50], str20 recipeTag->dish_name) //list of all recipe titles will be displayed in ALPHABETICAL order (call ListRecipeTitles). user inputs name of dish to modify. user is then asked which info will be changed.
{
printf("\n");
ListRecipeTitles(recipeTag recipe, recipeCount);
int d;
struct recipeTag tempDish;
char temp;
printf("\nInput Dish Name to modify: ");
scanf("%s", &recipeTag->tempDish);
for (d = 0; d < 50; d++)
            {
                if (strcmp(recipe[j].dish_name, recipe[d].dish_name) == 0) //little unsure sa index na j since sa ListRecipeTitles j ginamit and the dish name it's representing here is yung nasa original list
                printf("\nWhich would you like to modify?\n[1]Add Ingredient | [2]Delete Ingredient | [3]Add Step | [4]Delete Step | [R]Return To Menu\nInput: ");
                scanf("%s", &temp);
                if (temp == "1")
                {
                    updAddIngredient(recipeTag recipe, recipeCount);
                }

                if (temp == "2")
                {
                    updDeleteIngredient(recipeTag recipe, recipeCount);
                }

                if (temp == "3")
                {
                    updAddStep(recipeTag recipe, recipeCount);
                }

                if (temp == "4")
                {
                    updDeleteStep(recipeTag recipe, recipeCount);
                }

                if (temp == "R")
                {
                    updReturnToURBM(); // wala pa function
                }
            }
                d = 0;
                temp = 0;
}

// UNDER MODIFY RECIPE, THERE ARE SUB FUNCTIONS\

void updAddIngredient(struct recipeTag recipe[], int recipeCount)  //recipeCount will be declared in main and WILL be used in AddRecipe

{
//new ingredient is added to current set of ingredients, user brought back to modify menu
int ingslot = recipe[recipeCount].ingcount;
printf("\nEnter the Quantity: ");
scanf("%lf",&recipe[recipeCount].ingredient[ingslot].quantity);
printf("\n-> Successfully saved: %lf \n", recipe[recipeCount].ingredient[ingslot].quantity);

printf("\nEnter the Unit: ");
strwspace(recipe[recipeCount].ingredient[ingslot].unit,16);
printf("\n-> Successfully saved: %s \n", recipe[recipeCount].ingredient[ingslot].unit);

printf("\nEnter the Item Name: ");
strwspace(recipe[recipeCount].ingredient[ingslot].item,21);
printf("\n-> Successfully saved: %s \n", recipe[recipeCount].ingredient[ingslot].item);

recipe[recipeCount].ingcount++;
}

void updDeleteIngredient(struct recipeTag recipe[], int targetIndex) //based off DeleteRecipe baka may mali
{
//allows the user to select which existing ingredients to delete. (input could be number 1 until no. of ingredients he has). cannot delete if only 1 ingredient left.
//always brought back to modify menu after
if (recipe[targetIndex].ingcount <= 1)
    {
        printf("\nUnable to delete ingredient.");
        //bring to urb menu
    }
else
    {
        int i, delindex;
        for (i = 0; i < recipe[targetIndex].ingcount; i++)
        {
            printf("\n[%d]%lf %s %s", i + 1, recipe[targetIndex].ingredient[i].quantity, recipe[targetIndex].ingredient[i].unit, recipe[targetIndex].ingredient[i].item);
        }
            scanf("%d", &delindex);
            while (delindex < 1 || delindex > recipe[targetIndex].ingcount)
            {
                printf("\nInvalid Ingredient.\nInput: ");
                scanf("%d", &delindex);
            }
            delindex = delindex - 1;
            printf("Successfully deleted %lf %s %s.", recipe[targetIndex].ingredient[delindex].quantity, recipe[targetIndex].ingredient[delindex].unit, recipe[targetIndex].ingredient[delindex].item);
            for (i = delindex; i < recipe[targetIndex].ingcount - 1; i++)
            {
                recipe[targetIndex].ingredient[i] = recipe[targetIndex].ingredient[i + 1];
            }
            recipe[targetIndex].ingcount--;
    }
}

void updAddStep(struct recipeTag recipe[], int recipeCount)
{
//asked WHERE the new step will be put in. user is then asked to input the new instruction. can be inserted anywhere, make sure there are no empty/skipped steps. 
//always brought back to modify menu after
    int stepslot = recipe[recipeCount].stepcount;
    printf("\nEnter the Instrcution: ");
    strwspace(recipe[recipeCount].instruc[stepslot],16);
    printf("\n-> Successfully saved: %s \n", recipe[recipeCount].instruc[stepslot]);
    recipe[recipeCount].stepcount++;
}

void updDeleteStep(struct recipeTag recipe[], int targetIndex) //based off DeleteRecipe baka may mali
{
//similar to DeleteIngredient
//selects which existing step to delete, (input could be number 1 until no. of steps he has). cannot delete if only 1 step left.
//always brought back to modify menu after
if (recipe[targetIndex].stepcount <= 1)
    {
        printf("\nUnable to delete step.");
        //bring to urb menu
    }
    else
    {
        int i, delindex;
        for (i = 0; i < recipe[targetIndex].stepcount; i++)
        {
            printf("\n[%d] %s", i + 1, recipe[targetIndex].instruc[i]);
        }
        scanf("%d", &delindex);
        while (delindex < 1 || delindex > recipe[targetIndex].stepcount)
        {
            printf("\nInvalid Step.\nInput: ");
            scanf("%d", &delindex);
        }
        delindex = delindex - 1;
        printf("Successfully deleted step: %s.", recipe[targetIndex].instruc[delindex]);
        for (i = delindex; i < recipe[targetIndex].stepcount - 1; i++)
        {
            strcpy(recipe[targetIndex].instruc[i], recipe[targetIndex].instruc[i + 1]); 
        }
        recipe[targetIndex].stepcount--;
    }
}

void updReturnToURBM() // URBM (Update Recipe Box Menu)
{
//choice of user to go back to URBM
}

// end of modify recipe sub-functions

void updDeleteRecipe(struct recipeTag recipe[], int *recipeCount)
{
//list of all recipes displayed in ALPHABETICAL order (call ListRecipeTitles), user inputs name of dish to delete
//display "Recipe is not in the list” if the input is not strcmp=0 with the name of the dish
//when a recipe is deleted, everything under it is also deleted (ingredients + instructions etc)
    str20 deltarget;
    int i,j, index; 
    if (*recipeCount == 0)
    {
    printf("\nThe Recipe Box is empty. Nothing to delete!");
    }
    else
    {
        ListRecipeTitles(recipe,*recipeCount);
        printf("\nEnter the dish name to delete: ");
        strwspace(deltarget, 21);
        index = hanapinIndex(recipe,*recipeCount,deltarget);
        if (index == -1)
        {
            printf("\nRecipe title not found in the Recipe Box.");
        }
        else
        {
            for (i = index; i < *recipeCount - 1; i++) 
            {
                recipe[i] = recipe[i + 1];
            }
            
            (*recipeCount)--;
            printf("\nRecipe '%s' successfully deleted.", deltarget);
        }
    }   

}

void ListRecipeTitles(struct recipeTag recipe[], int recipeCount) //universal function methinks
{
//provides a list of all recipe titles in ALPHABETICAL ORDER, after the display, user is brought back to UPDATE MODE MENU.
//order is based on ASCII value
    struct recipeTag temp;
    int i, j;

    if (recipeCount == 0)
    {
        printf("\nThe Recipe Box is empty.");
    }
    else
    {
    for (i = 0; i < recipeCount - 1; i++)
    {
        for (j = 0; j < recipeCount - i - 1; j++)
        {
            if (strcmp(recipe[j].dish_name,recipe[j+1].dish_name) > 0)
            {
                temp = recipe[j];
                recipe[j] = recipe[j+1];
                recipe[j+1] = temp;
            }
        }
    }

    printf("\n------ Recipe Titles in Alphabetical ------");
    for (i = 0; i < recipeCount; i++)
    {
        printf("\n%d. %s", i + 1, recipe[i].dish_name);
    }

    }
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

void updSearchRecipeByTitle(struct recipeTag recipe[], int recipeCount)
{
//shows list of all recipes (ALPHABETICAL order, call ListRecipeTitles). then ask to type the recipe title to show respective info.
//if title exists, show all info. 
//bring user back to UPDATE MODE MENU
    str20 query;
    int j, index; 

    if (recipeCount == 0){
        printf("\nRecipe Box is empty");
    }

    else
    {
        ListRecipeTitles(recipe, recipeCount);
        printf("\nFor more infomation, enter the Recipe you want to view: ");
        strwspace(query,21);

        index = hanapinIndex(recipe,recipeCount,query);

        if (index == -1)
        {
        printf("\nRecipe title not found in the Recipe Box.\n");
        }
    
        else
        {
            printf("\n------ Recipe Information ------");
            printf("\nDish Name: %s", recipe[index].dish_name);
            printf("\nClassification: %s", recipe[index].classification);
            printf("\nServings: %d", recipe[index].serving);
            printf("\nIngredients: ");
            for (j = 0; j < recipe[index].ingcount; j++)
            {
                printf("\n- %lf %s of %s", recipe[index].ingredient[j].quantity, recipe[index].ingredient[j].unit, recipe[index].ingredient[j].item);
            }
            printf("\nInstructions: ");
            for (j = 0; j < recipe[index].stepcount; j++)
            {
            printf("%d. %s\n", j + 1, recipe[index].instruc[j]);
            }
        }  
    }
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

void accGenerateShoppingList(struct recipeTag recipe[], int recipeCount)
{
//show list of all recipe titles (call ListRecipeTitles), asks user which recipe to generate a shopping list for.
//user also asked how many people they will cook for.
//*Recomputation may be needed based on number of servings of the recipe. (basically like if binago no. of people, do the recompute)
//display all on screen, user then brought back to ACCESS MODE MENU.
    str20 query;
    int j, index, targetServ;
    double ratio;
    if (recipeCount == 0)
    {
        printf("\nThe Recipe Box is empty. Nothing to shop for!");
    }
    else
    {
        ListRecipeTitles(recipe, recipeCount);
        printf("\nEnter the Recipe for your shopping list: ");
        strwspace(query,21);
        index = hanapinIndex(recipe,recipeCount,query);
        if (index == -1)
        {
        printf("\nRecipe title not found in the Recipe Box.\n");
        }
       else
        {
            printf("\nOriginal recipe serves: %d", recipe[index].serving);
            printf("\nHow many servings do you need to cook? ");
            scanf("%d", &targetServ);

            ratio = (double)targetServ / recipe[index].serving; //uses typecasting to make targetServ into double

            printf("\n--- Shopping List for %s (%d servings) ---", recipe[index].dish_name, targetServ);
            
            for (j = 0; j < recipe[index].ingcount; j++)
                {
                   printf("\n- %lf %s of %s", recipe[index].ingredient[j].quantity * ratio, recipe[index].ingredient[j].unit, recipe[index].ingredient[j].item);
                }
            }
    }  
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
