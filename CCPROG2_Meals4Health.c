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
#include <stdlib.h>
#include <time.h>
typedef char str20[21];
typedef char str15[16];
typedef char str70[71];

struct ingredientTag
{
    double quantity; //amount in units
    str15 unit; //grams, cups, teaspoon, etc.
    str20 item; //Pangalan ng ingredient
};

struct FoodItemTag
{
    double quantity; //amount in units
    str15 unit; //grams, cups, teaspoon, etc.
    str20 item; //Pangalan ng ingredient ++ w/ space
    int calorieCount; //ilang calories
};

struct recipeTag
{
    str20 dish_name, classification; //classification must be starter, main, or dessert ONLY && dish_name ++ w/ space
    struct ingredientTag ingredient[20]; //list of food items
    str70 instruc[15]; //list of steps to prep and cook ingredients ++ w/ space
    int serving; //how many ppl it is for
    int ingcount; //how many ingredients a recipe has
    int stepcount; //how many instructions a recipe has
};

int generateRandomValue(int min, int max) //random number for recommendMenu
{
    return (rand() % (max - min + 1)) + min;
}

//Function Prototypes
void ListRecipeTitles(struct recipeTag recipe[], int recipeCount);
void updAddIngredient(struct recipeTag recipe[], int TargetIndex);
void updDeleteIngredient(struct recipeTag recipe[], int TargetIndex);
void updAddStep(struct recipeTag recipe[], int TargetIndex);
void updDeleteStep(struct recipeTag recipe[], int TargetIndex);
void updReturnToURBM();
/* strwspace reads a string input from the user, including spaces, up to a maximum size.
   @param string - the character array where the input will be stored
   @param maxSize - the maximum number of characters allowed (including the null terminator)
   Pre-condition: maxSize must be greater than 0 and the string array must have enough capacity.
*/
void strwspace(char string[], 
    int maxSize) //NOTE on maxSize value: str20 -> 21, str15 -> 16, str70 ->71
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

/* fstrwspace reads a string from a text file, including spaces, until it hits a newline or EOF.
   @param fp - the file pointer currently being read from
   @param string - the character array where the file text will be stored
   @return 1 if at least one character was successfully read, and returns 0 if it hits End of File (EOF)
   @param maxSize - the maximum number of characters allowed (including the null terminator)
   Pre-condition: fp must be successfully opened in read ("r") mode.
*/
int fstrwspace(FILE *fp, 
    char string[], 
    int maxSize)
{
	char ch;
	int i = 0;
	int x;
	
	while ((x = fscanf(fp, "%c", &ch)) == 1 && ch != '\n')
	{   
    if ( i < maxSize - 1)
    {
        string[i] = ch;
        i++;
    }
	}
    string[i] = '\0';
    if (x == 1 || i > 0) // x == 1 checks if fscanf read a char, and i > 0 is a failsafe when it reaches EOF
    {
        return 1;
    }
    else
    {
        return 0;  
    }
}

/* hanapinIndex searches the recipe array for a specific dish name and returns its location.
   @param recipe - the array of recipe structures to search through
   @param recipeCount - the current number of recipes saved in the array
   @param target - the string containing the name of the dish to find
   @return the integer index of the recipe if found, and returns -1 if it does not exist
   Pre-condition: recipeCount must be equal to the amount of the filled elements in the recipe array.
*/
int hanapinIndex(struct recipeTag recipe[], 
    int recipeCount, 
    char target[])
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

/* login checks the inputted username and password and compares to the set admin credentials
   @param user - string where the inputted username will be stored
   @param pass - string where the inputted password will be stored
   @return 1 if the credentials match, and returns 0 if they are invalid
   Pre-condition: N/A
*/
int login(str15 user, 
    str15 pass)
{ 
    printf("\nEnter Username: ");
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



// FUNCTIONS UNDER "UPDATE RECIPE BOX" FUNCTION

/* updAddFoodCalorieInfo prompts the user for food-item details and adds a new entry to the database
   @param fooditem - the array of FoodItemTag struct where the new data will be saved
   @param fooditemCount - the address of the integer tracking the total number of saved food items
   Pre-condition: the fooditem array must not be full (fooditemCount < 50)
*/
void updAddFoodCalorieInfo(struct FoodItemTag fooditem[], 
    int *fooditemCount) 
{
    printf("Enter Food Item: ");
    strwspace(fooditem[*fooditemCount].item, 21);
    printf("\nEnter Quantity: ");
    scanf("%lf", &fooditem[*fooditemCount].quantity);
    printf("\nEnter Unit: ");
    strwspace(fooditem[*fooditemCount].unit, 16);//use strwspace func
    printf("\nEnter Calorie Count: ");
    scanf("%d", &fooditem[*fooditemCount].calorieCount);
    (*fooditemCount)++;
}

/* updViewFoodCalorieChart displays the list of food items and their calorie information by sets of ten.
   @param fooditem - the array of FoodItemTag struct containing the food data to be displayed
   @param fooditemCount - the total number of valid food items currently stored in the array
   Pre-condition: The fooditem array must contain valid data and fooditemCount must be greater than or equal to 0.
*/
void updViewFoodCalorieChart(struct FoodItemTag fooditem[], 
    int fooditemCount)
{
    int i;
    char ch;
    int flag = 0;

    if (fooditemCount == 0) {
        printf("\nNo food items to display.\n");
    }
    else
    {
        for (i = 0; i < fooditemCount && flag == 0; i++)
    {
        printf("\nFood Item: %-20s\tQuantity: %-8.2lf\tUnit: %-15s\tCalories: %d", fooditem[i].item, fooditem[i].quantity, fooditem[i].unit, fooditem[i].calorieCount);
        
        if ((i + 1) % 10 == 0 && (i + 1) < fooditemCount)
        {
            printf("\nContinue? (N for Next or X to exit):  ");
            scanf(" %c", &ch);
            if (ch == 'X' || ch == 'x'){
                flag = 1;
            }
        }
        else if ((i + 1) == fooditemCount)
        {
            printf("\nPress X to exit the view: ");
            scanf(" %c", &ch);
            if (ch == 'X' || ch == 'x'){
                flag = 1;
            }
        }
    }
    }   
}

/* updSaveCalorieInfo exports the current list of food items and their calorie counts into a specified text file.
   @param fooditem - the array of FoodItemTag struct containing the food data to be saved
   @param fooditemCount - the total number of food items to be written to the file
   Pre-condition: fooditemCount must be an accurate count of the valid items in the fooditem array.
*/
void updSaveCalorieInfo(struct FoodItemTag fooditem[], 
    int fooditemCount) 
{
    int i;
    str20 filename;
    FILE *fp;

    if (fooditemCount == 0)
    {
        printf("\nThere is no food data to save!\n");
    }
    else
    {
        //Ihingi kay User ang pangalan ng txt file kasama ang .txt. 
        printf("\nEnter Filename with .txt extension: ");
        scanf("%s", filename);

        if (fp = fopen(filename, "w"))
        {
            for (i = 0; i < fooditemCount; i++)
            {
                fprintf(fp, "%s\n", fooditem[i].item);
                fprintf(fp, "%lf %s %d\n", fooditem[i].quantity, fooditem[i].unit, fooditem[i].calorieCount);
                fprintf(fp, "\n");
            }
            fclose(fp);
            printf("\nSuccessfully saved %d food items to %s!\n", fooditemCount, filename);
        }
        else
        {
            printf("Whoops! Error writing to file");
        }
    }
}

/* updLoadCalorieInfo imports food items and their calorie counts from a specified text file into the program.
   @param fooditem - the array of FoodItemTag struct where the loaded data will be stored
   @param fooditemCount - the address of the integer tracking the total number of saved food items, which will be updated
   Pre-condition: The specified text file must exist and strictly follow the required formatting.
*/
void updLoadCalorieInfo(struct FoodItemTag fooditem[], 
    int *fooditemCount)
{
    str20 filename;
    FILE *fp;
    char temp;
    
    printf("\nEnter Filename with .txt extension: ");
    scanf("%s", filename);

    if (fp = fopen(filename, "r"))
    {
        *fooditemCount = 0;
        while (fstrwspace(fp, fooditem[*fooditemCount].item, 21) == 1)
        {
            fscanf(fp, "%lf %s %d", &fooditem[*fooditemCount].quantity, fooditem[*fooditemCount].unit, &fooditem[*fooditemCount].calorieCount);
            fscanf(fp, "%c", &temp); 
            fscanf(fp, "%c", &temp);
            (*fooditemCount)++;
        }
        fclose(fp);
        printf("\nSuccessfully loaded %d food items to %s!\n", *fooditemCount, filename);
    }
    else
    {
        printf("Whoops! Could not open %s", filename);
    }
}

/* updAddRecipe prompts the user for dish details, ingredients, and instructions to create a new recipe.
   @param recipe - the master array of recipe struct where the new dish will be saved
   @param recipeCount - the address of the integer tracking the total number of recipes
   Pre-condition: The recipe array must not be full (*recipeCount < 50).
*/
void updAddRecipe(struct recipeTag recipe[50], 
    int *recipeCount) //PLS HELP
{
    char leftover;
    recipe[*recipeCount].ingcount = 0; 
    recipe[*recipeCount].stepcount = 0;

    printf("\nEnter Dish Name: ");
    strwspace(recipe[*recipeCount].dish_name,21);
    while (hanapinIndex(recipe, *recipeCount, recipe[*recipeCount].dish_name) != -1)
        {
            printf("\nThat Dish Name already exists! Reinput another: ");
            strwspace(recipe[*recipeCount].dish_name, 21); 
        }
    
    printf("\nEnter Classification: ");
    scanf("%s", recipe[*recipeCount].classification);
        while (strcmp("starter", recipe[*recipeCount].classification) != 0 && strcmp("main", recipe[*recipeCount].classification) != 0 && strcmp("dessert", recipe[*recipeCount].classification) != 0)
        {
            printf("\nThat is an invalid classification! Reinput another: ");
            scanf("%s", recipe[*recipeCount].classification);
        }
    printf("\nEnter Number of Servings: ");
    scanf("%d", &recipe[*recipeCount].serving);
    printf("\nNow entering the Ingredient zone!");
    do 
    {
        updAddIngredient(recipe, *recipeCount);
        printf("\nWould you like to add another ingredient (Y/N)? ");
        scanf(" %c",&leftover);
    }while (leftover != 'N' && leftover != 'n');

    printf("\nNow entering the Instruction zone!");
    do 
    {
        updAddStep(recipe, *recipeCount);
        printf("\nWould you like to add another instruction (Y/N)? ");
        scanf(" %c",&leftover); 
        
    } while (leftover != 'N' && leftover != 'n');
        
    //bring back to URB Menu
    (*recipeCount)++; // Increment the total recipe count
}

/* updModifyRecipe allows the user to select an existing recipe and open a sub-menu to add or delete its ingredients and steps.
   @param recipe - the master array of recipe struct containing the dish to be modified
   @param recipeCount - the total number of valid recipes currently stored
   Pre-condition: The recipe box must not be empty (recipeCount > 0).
*/

void updModifyRecipe(struct recipeTag recipe[50], 
    int recipeCount) 
{
    int nChosenRecipe;
    struct recipeTag tempDish;
    char option;

    printf("\n");
    ListRecipeTitles(recipe, recipeCount);
    printf("\nInput Dish Name to modify: ");
    strwspace(tempDish.dish_name, 21);
    
    nChosenRecipe = hanapinIndex(recipe, recipeCount, tempDish.dish_name);
    
    if (nChosenRecipe != -1)
    {
        do 
        {
            printf("\nWhich would you like to modify?\n[1]Add Ingredient | [2]Delete Ingredient | [3]Add Step | [4]Delete Step | [R]Return To Menu\nInput: ");
            scanf(" %c", &option);

            switch (option)
            {
                case '1':
                    updAddIngredient(recipe, nChosenRecipe);
                    break;
                case '2':
                    updDeleteIngredient(recipe, nChosenRecipe);
                    break;
                case '3':
                    updAddStep(recipe, nChosenRecipe);
                    break;
                case '4':
                    updDeleteStep(recipe, nChosenRecipe);
                    break;
                case 'R':
                case 'r':
                    printf("\nReturning to Update Recipe Box Menu...\n");
                    break;
                default:
                    printf("\nInvalid option! Please try again.\n");
                    break;
            }
        } while (option != 'R' && option != 'r'); 
    }
    else
    {
        printf("Whoops! %s doesnt exist!", tempDish.dish_name);
    }
}

/* updDeleteRecipe prompts the user for a recipe title, searches for it, and removes it from the database while shifting the remaining elements.
   @param recipe - the master array of recipe struct from which the dish will be deleted
   @param recipeCount - the address of the integer tracking the total number of recipes, which will be decremented
   Pre-condition: The recipe box must not be empty (*recipeCount > 0).
*/
void updDeleteRecipe(struct recipeTag recipe[], 
    int *recipeCount)
{
//list of all recipes displayed in ALPHABETICAL order (call ListRecipeTitles), user inputs name of dish to delete
//display "Recipe is not in the list” if the input is not strcmp==0 with the name of the dish
//when a recipe is deleted, everything under it is also deleted (ingredients + instructions etc)
    str20 deltarget;
    int i, index; 
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

/* updAddIngredient prompts the user to input the specific quantity, unit of measurement, and name of a new ingredient, 
   saving these details directly into the ingredient array of the selected recipe and incrementing its total ingredient count.
   @param recipe - the master array of recipe struct containing the dish to be modified
   @param TargetIndex - the integer index of the specific recipe being modified
   Pre-condition: The target recipe must exist and have space for another ingredient (ingcount < 20).
*/
void updAddIngredient(struct recipeTag recipe[], 
    int TargetIndex)  
{
    int ingslot = recipe[TargetIndex].ingcount;
    printf("\nEnter the Ingredient Name: ");
    strwspace(recipe[TargetIndex].ingredient[ingslot].item,21);
    printf("\n-> Successfully saved: %s \n", recipe[TargetIndex].ingredient[ingslot].item);

    printf("\nEnter the Quantity: ");
    scanf("%lf",&recipe[TargetIndex].ingredient[ingslot].quantity);
    printf("\n-> Successfully saved: %lf \n", recipe[TargetIndex].ingredient[ingslot].quantity);

    printf("\nEnter the Unit: ");
    strwspace(recipe[TargetIndex].ingredient[ingslot].unit,16);
    printf("\n-> Successfully saved: %s \n", recipe[TargetIndex].ingredient[ingslot].unit);

    recipe[TargetIndex].ingcount++;
}

/* updAddStep prompts the user to input a new procedural instruction or step, 
   saving the string into the instruction array of the specified recipe and updating the overall step count for that dish.
   @param recipe - the master array of recipe struct containing the dish to be modified
   @param TargetIndex - the integer index of the specific recipe being modified
   Pre-condition: The target recipe must exist and have space for another instruction (stepcount < 15).
*/
void updAddStep(struct recipeTag recipe[], 
    int TargetIndex)
{

    int stepslot = recipe[TargetIndex].stepcount;
    printf("\nEnter the Instruction: ");
    strwspace(recipe[TargetIndex].instruc[stepslot],71);
    printf("\n-> Successfully saved: %s \n", recipe[TargetIndex].instruc[stepslot]);
    recipe[TargetIndex].stepcount++;
}


/* updDeleteIngredient displays a numbered list of all currently saved ingredients for a specific recipe, 
   prompts the user to select an ingredient for removal, and performs an array shift to overwrite the deleted item and maintain continuous data.
   @param recipe - the master array of recipe struct containing the dish to be modified
   @param TargetIndex - the integer index of the specific recipe being modified
   Pre-condition: The target recipe must exist and have more than one ingredient currently saved (ingcount > 1).
*/
void updDeleteIngredient(struct recipeTag recipe[], 
    int TargetIndex) 
{
    int i, delindex;
    if (recipe[TargetIndex].ingcount <= 1)
        {
            printf("\nUnable to delete ingredient.");
        }
    else
        {
            for (i = 0; i < recipe[TargetIndex].ingcount; i++)
            {
                printf("\n[%d]%lf %s %s", i + 1, recipe[TargetIndex].ingredient[i].quantity, recipe[TargetIndex].ingredient[i].unit, recipe[TargetIndex].ingredient[i].item);
            }
                printf("\nAlin ang gusto mo mawala na? ");
                scanf("%d", &delindex);
                while (delindex < 1 || delindex > recipe[TargetIndex].ingcount)
                {
                    printf("\nInvalid Ingredient.\nInput: ");
                    scanf("%d", &delindex);
                }
                delindex = delindex - 1;
                printf("Successfully deleted %lf %s %s.", recipe[TargetIndex].ingredient[delindex].quantity, recipe[TargetIndex].ingredient[delindex].unit, recipe[TargetIndex].ingredient[delindex].item);
                for (i = delindex; i < recipe[TargetIndex].ingcount - 1; i++)
                {
                    recipe[TargetIndex].ingredient[i] = recipe[TargetIndex].ingredient[i + 1];
                }
                recipe[TargetIndex].ingcount--;
        }
}

/* updDeleteStep displays a numbered list of all current procedural instructions for a specific recipe, 
   prompts the user to input the number of the step they wish to remove, and performs an array shift using 
   strcpy to overwrite the deleted string and maintain a continuous sequence, ensuring at least one step always remains.
   @param recipe - the master array of recipe struct containing the dish to be modified
   @param TargetIndex - the integer index of the specific recipe being modified
   Pre-condition: The target recipe must exist and have more than one instruction currently saved (stepcount > 1).
*/
void updDeleteStep(struct recipeTag recipe[], 
    int TargetIndex)
{
    if (recipe[TargetIndex].stepcount <= 1)
    {
        printf("\nUnable to delete step.");
        //bring to urb menu
    }
    else
    {
        int i, delindex;
        for (i = 0; i < recipe[TargetIndex].stepcount; i++)
        {
            printf("\n[%d] %s", i + 1, recipe[TargetIndex].instruc[i]);
        }
        printf("\nAlin ang gusto mo mawala na? ");
        scanf("%d", &delindex);
        while (delindex < 1 || delindex > recipe[TargetIndex].stepcount)
        {
            printf("\nInvalid Step.\nInput: ");
            scanf("%d", &delindex);
        }
        delindex = delindex - 1;
        printf("Successfully deleted step: %s.", recipe[TargetIndex].instruc[delindex]);
        for (i = delindex; i < recipe[TargetIndex].stepcount - 1; i++)
        {
            strcpy(recipe[TargetIndex].instruc[i], recipe[TargetIndex].instruc[i + 1]); 
        }
        recipe[TargetIndex].stepcount--;
    }
}

/* ListRecipeTitles utilizes a sorting algorithm to arrange the master array of recipes in alphabetical order based on the 
   ASCII values of their dish names, and subsequently prints a formatted, numbered list of these titles to the screen.
   @param recipe - the master array of recipe struct to be sorted and displayed
   @param recipeCount - the total number of valid recipes currently stored
   Pre-condition: recipeCount must accurately reflect the number of populated elements in the recipe array.
*/
void ListRecipeTitles(struct recipeTag recipe[], 
    int recipeCount) 
{

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

/* ScanRecipes sorts the recipe array alphabetically and displays each dish one at a time, calculating and 
   presenting the individual ingredient calories and total recipe calories by cross-referencing the master food item array, 
   while providing an interactive menu to navigate to the next or previous recipe.
   UPD AND ACCESS BOXES
   @param recipe - the master array of recipe struct to be viewed
   @param recipeCount - the total number of valid recipes currently stored
   @param fooditem - the master array of FoodItemTag struct used as a database to fetch calorie counts
   @param fooditemCount - the total number of valid food items currently stored
   Pre-condition: Both recipeCount and fooditemCount must be greater than or equal to 0, and the arrays must contain valid data.

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
    : :
*/
void ScanRecipes(struct recipeTag recipe[], 
    int recipeCount, 
    struct FoodItemTag fooditem[], 
    int fooditemCount)
{

    int i, k, found;
    char ch;
    int currentIndex = 0;
    int currentIngredientCal = 0;
    int totalCal = 0;

    if (recipeCount == 0)
    {
        printf("\nThe Recipe Box is empty.");
    }
    else
    {
        ListRecipeTitles(recipe,recipeCount);
        printf("\n=========================================\n");
        

        do
        {
            totalCal = 0; // resets total cal

            
            for (i = 0; i < recipe[currentIndex].ingcount; i++) //for each ingredient
            {
                currentIngredientCal = 0;
                found = 0;

                for (k = 0; k < fooditemCount && found == 0; k++) //searching fooditem for a match
                {
                    if(strcmp(recipe[currentIndex].ingredient[i].item, fooditem[k].item) == 0) //if they match
                    {
                        currentIngredientCal = fooditem[k].calorieCount;
                        found = 1;
                    }
                }
                totalCal += currentIngredientCal; //adding to totalcal
            }
            // display portion
            printf("\n=========================================\n");
            printf("\n%s %d Servings %d Calories\n", recipe[currentIndex].dish_name, recipe[currentIndex].serving, totalCal);
            printf("Ingredients:\n");
            for (i = 0; i < recipe[currentIndex].ingcount; i++)
            {
                currentIngredientCal = 0;
                found = 0;

                for (k = 0;  k < fooditemCount && found == 0; k++)
                {
                    if(strcmp(recipe[currentIndex].ingredient[i].item, fooditem[k].item) == 0)
                    {
                        currentIngredientCal = fooditem[k].calorieCount;
                        found = 1;
                    }
                }
                printf("%.2lf %s %s | %d Calories\n", recipe[currentIndex].ingredient[i].quantity, recipe[currentIndex].ingredient[i].unit, recipe[currentIndex].ingredient[i].item, currentIngredientCal);    
            }

            printf("Procedures:\n");
            for (i = 0; i < recipe[currentIndex].stepcount; i++)
            {
                printf("%d. %s\n", 1+i, recipe[currentIndex].instruc[i]);
            }
        printf("\n=========================================\n");
        printf("N = Next, P = Previous, X = Exit\nInput: "); //if user chooses X or x, the while loop stops and acts as the exit page
        scanf(" %c", &ch);
        if (ch == 'N' || ch == 'n')
        {
            if (currentIndex < recipeCount - 1) 
            {
                currentIndex++;
            } 
            else 
            {
                printf("\nThere is no next page!\n");
            }
        }
        else if (ch == 'P' || ch == 'p')
        {
            if (currentIndex > 0) 
            {
                currentIndex--; 
            } 
            else 
            {
                printf("\nThere is no previous page!\n");
            }
        }
        else if (ch != 'X' && ch != 'x')
        {
            
            printf("\nInvalid input! Enter N, P, or X.\n"); 
        }
        } while ((ch != 'X' && ch != 'x') && currentIndex < recipeCount); //while the user does not choose to exit or under amount of recipes
        
    }
}

/* SearchRecipeByTitle presents an alphabetical list of all saved recipes, prompts the user to input a specific dish name to search for, 
   and utilizes the hanapinIndex helper function to retrieve and print all corresponding details including classification, ingredients, 
   and procedural steps.
   UPD AND ACCESS BOXES
   @param recipe - the master array of recipe struct to search through
   @param recipeCount - the total number of valid recipes currently stored
   Pre-condition: recipeCount must be greater than or equal to 0, and the recipe array must be populated with valid data.
*/
void SearchRecipeByTitle(struct recipeTag recipe[], 
    int recipeCount)
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

/* updExportRecipes prompts the user for a destination filename and iteratively writes the entirety of the recipe 
   database into a text file, strictly adhering to a highly specific layout utilizing string headers and blank lines 
   to ensure compatibility with future import operations.
   @param recipe - the master array of recipe struct containing the data to be exported
   @param recipeCount - the total number of valid recipes currently stored
   Pre-condition: recipeCount must be greater than 0, as an empty database cannot be meaningfully exported.
*/
void updExportRecipes(struct recipeTag recipe[], 
    int recipeCount)
{
    int i,j;
    str20 filename;
    FILE *fp;

    if (recipeCount == 0)
    {
        printf("\nThere is no recipe data to save!\n");
    }
    else
    {
        //Ihingi kay User ang pangalan ng txt file kasama ang .txt. 
        printf("\nEnter Filename with .txt extension: ");
        scanf("%s", filename);

        if (fp = fopen(filename, "w"))
        {
            for (i = 0; i < recipeCount; i++)
            {   
                fprintf(fp,"%s\n", recipe[i].dish_name);
                fprintf(fp,"%d %s\n", recipe[i].serving, recipe[i].classification);

                //Ingredients section
                fprintf(fp,"Ingredients %d\n", recipe[i].ingcount);
                for (j = 0; j < recipe[i].ingcount; j++)
                {
                    fprintf(fp,"%lf %s %s\n", recipe[i].ingredient[j].quantity, recipe[i].ingredient[j].unit, recipe[i].ingredient[j].item);
                }

                //Steps section
                fprintf(fp,"Steps %d\n", recipe[i].stepcount);
                for (j = 0; j < recipe[i].stepcount; j++)
                {
                    fprintf(fp, "%s\n", recipe[i].instruc[j]);
                }
                fprintf(fp, "\n");
            }

            fclose(fp);
            printf("\nSuccessfully saved %d food items to %s!\n", recipeCount, filename);
        }
        else
        {
            printf("Whoops! Error writing to file");
        }
    }
}

/* ImportRecipes reads a formatted text file to extract recipe data into a temporary struct, cross-references the dish name 
   against the existing database to handle overwrite permissions, and safely integrates the parsed data into the master array 
   while skipping over any blank lines.
   ACCESS AND UPDATE BOXES
   @param recipe - the master array of recipe struct where the imported data will be saved
   @param recipeCount - the address of the integer tracking the total number of recipes, which will be updated as new dishes are added
   Pre-condition: The target text file must exist and strictly follow the formatting guidelines established by the export function.
*/

void ImportRecipes(struct recipeTag recipe[], 
    int *recipeCount)
{
    str20 filename;
    FILE *fp;
    char cTemp, overwriteChoice;
    str20 sTemp;
    int j, index, isBlank;
    struct recipeTag temp;
    
    printf("\nEnter Filename with .txt extension: ");
    scanf("%s", filename);

    if (fp = fopen(filename, "r"))
    {
        while (fstrwspace(fp, temp.dish_name,21) == 1)
        {
            isBlank = 0;

            if (strlen(temp.dish_name) == 0)
                isBlank = 1;

            if (isBlank == 0)
            {
                fscanf(fp, "%d %s", &temp.serving, temp.classification);
                fscanf(fp, "%c", &cTemp); 
                //Read Ingredients
                fscanf(fp, "%s %d", sTemp, &temp.ingcount);
                fscanf(fp, "%c", &cTemp);
                for (j = 0; j < temp.ingcount; j++)
                {
                    fscanf(fp, "%lf %s", &temp.ingredient[j].quantity, temp.ingredient[j].unit);
                    fscanf(fp, "%c", &cTemp); 
                    fstrwspace(fp, temp.ingredient[j].item,21);
                }
                //Read Steps
                fscanf(fp, "%s %d", sTemp, &temp.stepcount);
                fscanf(fp, "%c", &cTemp);
                for (j = 0; j < temp.stepcount; j++)
                {
                    fstrwspace(fp, temp.instruc[j],71);
                }
                index = hanapinIndex(recipe, *recipeCount, temp.dish_name);

                if (index != -1)
                {
                    printf("\nRecipe '%s' already exists. Overwrite? (Y/N): ", temp.dish_name);
                    scanf(" %c", &overwriteChoice);

                    if (overwriteChoice == 'Y' || overwriteChoice == 'y')
                    {
                        recipe[index] = temp;
                        printf("\nRecipe Overwritten!\n");
                    }

                     if (overwriteChoice == 'N' || overwriteChoice == 'n')
                    {
                        printf("\nRecipe kept as is.\n");
                    }
                }
                else
                {
                    if (*recipeCount < 50)
                    {
                        recipe[*recipeCount] = temp;
                        (*recipeCount)++;
                        printf("\nAdded %s to the list of recipes!\n", temp.dish_name);
                    }
                    else 
                    {
                        printf("\nRecipe Collection is Full! Cannot add %s\n", temp.dish_name);
                    }
                }
            }
        }
        fclose(fp);
        printf("\nFinished importing recipes from %s!\n", filename);
    }
    else
    {
        printf("Whoops! Could not open %s", filename);
    }
}

/* UpdateRecipeBox serves as the main hub for the Update Mode, providing a menu to manage ingredients and recipes.
   @param recipe - the master array of recipe struct
   @param recipeCount - pointer to the integer tracking the number of recipes
   @param fooditem - the master array of FoodItemTag struct
   @param fooditemCount - pointer to the integer tracking the number of food items
   Pre-condition: the arrays must be properly initialized in main.
*/
void UpdateRecipeBox(struct recipeTag recipe[], int *recipeCount, struct FoodItemTag fooditem[], int *fooditemCount)
{
    int choice;
    do 
    {
        printf("\n=========================================\n");
        printf("              GnG's Kusina               \n");
        printf("=========================================\n"); 
        printf("            UPDATE RECIPE BOX            \n");
        printf("=========================================\n");
        printf("[1] Add Food-Calorie Info\n");
        printf("[2] View Food-Calorie Chart\n");
        printf("[3] Save Calorie Info\n");
        printf("[4] Load Calorie Info\n");
        printf("[5] Add Recipe\n");
        printf("[6] Modify Recipe\n");
        printf("[7] Delete Recipe\n");
        printf("[8] List Recipe Titles\n");
        printf("[9] Scan Recipes\n");
        printf("[10] Search Recipe by Title\n");
        printf("[11] Export Recipes\n");
        printf("[12] Import Recipes\n");
        printf("[13] Return to Main Menu\n");
        printf("=========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
                updAddFoodCalorieInfo(fooditem, fooditemCount); 
                break;
            case 2: 
                updViewFoodCalorieChart(fooditem, *fooditemCount); 
                break;
            case 3: 
                updSaveCalorieInfo(fooditem, *fooditemCount); 
                break;
            case 4: 
                updLoadCalorieInfo(fooditem, fooditemCount); 
                break;
            case 5: 
                updAddRecipe(recipe, recipeCount); 
                break;
            case 6: 
                updModifyRecipe(recipe, *recipeCount); 
                break;
            case 7: 
                updDeleteRecipe(recipe, recipeCount); 
                break;
            case 8: 
                ListRecipeTitles(recipe, *recipeCount); 
                break;
            case 9: 
                ScanRecipes(recipe, *recipeCount, fooditem, *fooditemCount); 
                break;
            case 10: 
                SearchRecipeByTitle(recipe, *recipeCount); 
                break;
            case 11: 
                updExportRecipes(recipe, *recipeCount); 
                break;
            case 12: 
                ImportRecipes(recipe, recipeCount); 
                break;
            case 13: 
                printf("\nReturning to Main Menu...\n");
                break;
            default: 
                printf("\nInvalid option! Please try again.\n"); 
                break;
        }
    } while (choice != 13);
}

/* accGenerateShoppingList displays all available recipes, prompts the user to select a dish and input a desired number of servings, 
   and calculates a scaled shopping list by multiplying the original ingredient quantities by the serving ratio.
   @param recipe - the master array of recipe struct to be searched and accessed
   @param recipeCount - the total number of valid recipes currently stored
   Pre-condition: The recipe box must not be empty (recipeCount > 0) to generate a shopping list.
*/
void accGenerateShoppingList(struct recipeTag recipe[], 
    int recipeCount)
{
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
    

/* accScanRecipesByIngredients prompts the user to input a specific food item, searches the entire database for dishes containing that ingredient, 
   and displays the matching recipes in an interactive, paginated format complete with dynamic calorie calculations.
   @param recipe - the master array of recipe struct to be searched
   @param recipeCount - the total number of valid recipes currently stored
   @param fooditem - the master array of FoodItemTag struct used to calculate the calories of the matched recipes
   @param fooditemCount - the total number of valid food items currently stored
   Pre-condition: The recipe box must not be empty, and the fooditem array must contain valid data for accurate calorie computation.
*/
void accScanRecipesByIngredients(struct recipeTag recipe[], int recipeCount, struct FoodItemTag fooditem[], int fooditemCount)
{
//ask user to TYPE (scanf) an ingredient (just the food item. e.g. Potato)
//show the recipe info of all recipes that use said ingredient (e.g. find all dishes that use Potato)
//choice to view next or previous property or exit the scanning/viewing
//sequence of display is ALPHABETICAL (recipe title)
//when user exits OR reached end of the list, bring back to ACCESS MODE MENU
struct recipeTag temp;
    int i, j, k, found;
    char ch;
    int currentIndex = 0;
    int currentIngredientCal = 0;
    int totalCal = 0;
    int matchingIndex[50];
    int matchCount = 0;
    str20 searchItem;
    int hasIngredient;
    if (recipeCount == 0)
    {
        printf("\nThe Recipe Box is empty.");
    }
    else
    {
    for (i = 0; i < recipeCount - 1; i++) // sort
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
    printf("Enter the ingredient you want to find: ");
    strwspace(searchItem, 21);
    for (i = 0; i < recipeCount; i++) //for each ingredient
        {
            hasIngredient = 0;
            for (j = 0; j < recipe[i].ingcount && hasIngredient == 0; j++)
            {
                if (strcmp(recipe[i].ingredient[j].item, searchItem) == 0)
                {
                    matchingIndex[matchCount] = i;
                    matchCount++;
                    hasIngredient = 1;
                }
            }
        }
    if (matchCount == 0)
    {
        printf("\nNo recipes found containing '%s'.\n", searchItem);
    }
    else
    {
    do
    {
        int target = matchingIndex[currentIndex];
        totalCal = 0; // resets total cal

        for (i = 0; i < recipe[target].ingcount; i++) //for each ingredient
        {
            currentIngredientCal = 0;
            found = 0;

            for (k = 0; k < fooditemCount && found == 0; k++) //searching fooditem for a match
            {
                if(strcmp(recipe[target].ingredient[i].item, fooditem[k].item) == 0) //if they match
                {
                    currentIngredientCal = fooditem[k].calorieCount;
                    found = 1;
                }
            }
            totalCal += currentIngredientCal; //adding to totalcal
        }
        
        // display portion
        printf("\n%s %d Servings %d Calories\n", recipe[target].dish_name, recipe[target].serving, totalCal);
        printf("Ingredients:\n");
        for (i = 0; i < recipe[target].ingcount; i++)
        {
            currentIngredientCal = 0;
            found = 0;

            for (k = 0;  k < fooditemCount && found == 0; k++)
            {
                if(strcmp(recipe[target].ingredient[i].item, fooditem[k].item) == 0)
                {
                    currentIngredientCal = fooditem[k].calorieCount;
                    found = 1;
                }
            }
            printf("%.2lf %s %s %d\n", recipe[target].ingredient[i].quantity, recipe[target].ingredient[i].unit, recipe[target].ingredient[i].item, currentIngredientCal);    
        }

        printf("Procedures:\n");
        for (i = 0; i < recipe[target].stepcount; i++)
        {
            printf("%d. %s\n", i + 1, recipe[target].instruc[i]);
        }
     
    printf("N = Next, P = Previous, X = Exit\nInput: "); //if user chooses X or x, the while loop stops and acts as the exit page
    scanf(" %c", &ch);
        if (ch == 'N' || ch == 'n')
        {
            if (currentIndex < recipeCount - 1) 
            {
                currentIndex++;
            } 
            else 
            {
                printf("\nThere is no next page!\n");
            }
        }
        else if (ch == 'P' || ch == 'p')
        {
            if (currentIndex > 0) 
            {
                currentIndex--; 
            } 
            else 
            {
                printf("\nThere is no previous page!\n");
            }
        }
        else if (ch != 'X' && ch != 'x')
        {
            
            printf("\nInvalid input! Enter N, P, or X.\n"); 
        }
    } while ((ch != 'X' && ch != 'x') && currentIndex < matchCount); //while the user does not choose to exit or under amount of recipes
    }
    }
}
/* accRecommendedMenu asks the user to input a target calorie intake for 1 person. The program randomly 
   chooses 1 main course from the list of recipes; if the calorie count is not enough, a starter is 
   included, and if both are still not enough, a dessert is recommended. If there is no available course, 
   it skips and shows a recipe of the available courses. The menu will not exceed the calorie intake, and 
   unlisted ingredients are assumed to be 0 calories. It shows the suggested menu one at a time 
   (starter -> main -> dessert) before returning to the Access Mode Menu.
   @param recipe - the master array of recipe struct to pull the randomized courses from
   @param recipeCount - the total number of valid recipes currently stored
   @param fooditem - the master array of FoodItemTag struct used to calculate and verify the calorie limits
   @param fooditemCount - the total number of valid food items currently stored
   Pre-condition: The recipe array must contain valid dishes, and the generateRandomValue helper function must be defined.
*/
void accRecommendedMenu(struct recipeTag recipe[], int recipeCount, struct FoodItemTag fooditem[], int fooditemCount)
{
    int i, j, k, found;
    int targetCalorie;
    int recipeTotalCal;
    int recipeCalPerPerson[50]; // since it asks for targer calorie intake of 1 person

    int mainsFiltered[50];
    int mainCount = 0;
    int chosenMain = -1; // not found; -1 because arrays start at index 0

    int startersFiltered[50];
    int starterCount = 0;
    int chosenStarter = -1;

    int dessertsFiltered[50];
    int dessertCount = 0;
    int chosenDessert = -1;

    char ch;

    printf("Input Target Calorie Intake: \n");
    scanf("%d", &targetCalorie);

    for (i = 0; i < recipeCount; i++)
    {
        recipeTotalCal = 0;

        for (j = 0; j < recipe[i].ingcount; j++)
        {
            found = 0;
            for (k = 0;  k < fooditemCount && found == 0; k++)
            {
                if(strcmp(recipe[i].ingredient[j].item, fooditem[k].item) == 0)
                {
                    recipeTotalCal += fooditem[k].calorieCount;
                    found = 1;
                }
            }
        }
        recipeCalPerPerson[i] = recipeTotalCal / recipe[i].serving; //since some recipe serving sizes are for more than one person
    }

    //main
    for (i = 0; i < recipeCount; i++)
    {
        if (strcmp(recipe[i].classification, "main") == 0 && recipeCalPerPerson[i] <= targetCalorie)
        {
            mainsFiltered[mainCount] = i; //saves the index of i into the mainList array to take note of all the mains that fit under the calorie intake
            mainCount++;
        }
    }
    if (mainCount > 0)
    {
        int randomIndex = generateRandomValue(0, mainCount - 1); //the upper limit of an array is -1 from the mainCount
        chosenMain = mainsFiltered[randomIndex];
        targetCalorie -= recipeCalPerPerson[chosenMain];
    }

    //starter
    for (i = 0; i < recipeCount; i++)
    {
        if (strcmp(recipe[i].classification, "starter") == 0 && recipeCalPerPerson[i] <= targetCalorie)
        {
            startersFiltered[starterCount] = i; //saves the index of i into the mainList array to take note of all the starters that fit under the calorie intake
            starterCount++;
        }
    }
    if (starterCount > 0)
    {
        int randomIndex = generateRandomValue(0, starterCount - 1); //the upper limit of an array is -1 from the starterCount
        chosenStarter = startersFiltered[randomIndex];
        targetCalorie -= recipeCalPerPerson[chosenStarter];
    }

    //dessert
    for (i = 0; i < recipeCount; i++)
    {
        if (strcmp(recipe[i].classification, "dessert") == 0 && recipeCalPerPerson[i] <= targetCalorie)
        {
            dessertsFiltered[dessertCount] = i; //saves the index of i into the mainList array to take note of all the desserts that fit under the calorie intake
            dessertCount++;
        }
    }
    if (dessertCount > 0)
    {
        int randomIndex = generateRandomValue(0, dessertCount - 1); //the upper limit of an array is -1 from the dessertCount
        chosenDessert = dessertsFiltered[randomIndex];
        targetCalorie -= recipeCalPerPerson[chosenDessert];
    }

    //display
    printf("\nYour Recommended Menu!\n");

    if (chosenStarter != -1)
    {
        printf("|Starter|\n");
        printf("Dish Name: %s\n", recipe[chosenStarter].dish_name);
        printf("Servings: %d\n", recipe[chosenStarter].serving);
        printf("\nInput any character to view the next course: ");
        scanf(" %c", &ch);
    }

    if (chosenMain != -1)
    {
        printf("|Main Course|\n");
        printf("Dish Name: %s\n", recipe[chosenMain].dish_name);
        printf("Servings: %d\n", recipe[chosenMain].serving);

        if (chosenDessert != -1) 
        {
            printf("\nInput any character to view the next course: ");
            scanf(" %c", &ch);
        }
    }

    if (chosenDessert != -1)
    {
        printf("|Dessert|\n");
        printf("Dish Name: %s\n", recipe[chosenDessert].dish_name);
        printf("Servings: %d\n", recipe[chosenDessert].serving);
    }

    if (chosenStarter == -1 && chosenMain == -1 && chosenDessert == -1)
    {
        printf("\nNo menu combination fits the budget.\n");
    }
}

/* AccessRecipeBox serves as the main hub for the Access Mode, providing tools for users to view and utilize recipes.
   @param recipe - the master array of recipe struct
   @param recipeCount - pointer to the integer tracking the number of recipes
   @param fooditem - the master array of FoodItemTag struct
   @param fooditemCount - pointer to the integer tracking the number of food items
   Pre-condition: the arrays must be properly initialized in main.
*/
void AccessRecipeBox(struct recipeTag recipe[], int *recipeCount, struct FoodItemTag fooditem[], int *fooditemCount)
{
    int choice;
    do 
    {
        printf("\n=========================================\n");
        printf("              GnG's Kusina               \n");
        printf("=========================================\n");
        printf("            ACCESS RECIPE BOX            \n");
        printf("=========================================\n");
        printf("[1] Import Recipes\n");
        printf("[2] List Recipe Titles\n");
        printf("[3] Scan Recipes\n");
        printf("[4] Search Recipe by Title\n");
        printf("[5] Generate Shopping List\n");
        printf("[6] Scan Recipes by Ingredient\n");
        printf("[7] Recommend Menu\n");
        printf("[8] Return to Main Menu\n");
        printf("=========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
                ImportRecipes(recipe, recipeCount); 
                break;
            case 2: 
                ListRecipeTitles(recipe, *recipeCount); 
                break;
            case 3: 
                ScanRecipes(recipe, *recipeCount, fooditem, *fooditemCount); 
                break;
            case 4: 
                SearchRecipeByTitle(recipe, *recipeCount);
                break;
            case 5: 
                accGenerateShoppingList(recipe, *recipeCount);
                break;
            case 6: 
                accScanRecipesByIngredients(recipe, *recipeCount, fooditem, *fooditemCount);
                break;
            case 7: 
                accRecommendedMenu(recipe, *recipeCount, fooditem, *fooditemCount); 
                break;
            case 8: 
                printf("\nReturning to Main Menu...\n");
                *recipeCount = 0; 
                *fooditemCount = 0;
                break;
            default: 
                printf("\nInvalid option! Please try again.\n"); 
                break;
        }
    } while (choice != 8);
}
// end of ACCESS RECIPE BOX FUNCTIONS
int main()
{
    srand(time(NULL));
    int choice = 0, exit = 0, res, recipeCount = 0, foodCount = 0;
    char ch;
    str15 user, pass;
    struct recipeTag recipeList[50];
    struct FoodItemTag foodList[50];

    do 
    {
        printf("\n=========================================\n");
        printf("              GnG's Kusina               \n");
        printf("=========================================\n");
        printf("              MEALS4HEALTH               \n");
        printf("=========================================\n");
        printf("[1] - Update Recipe Box\n");
        printf("[2] - Access Recipe Box\n");
        printf("[3] - Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        scanf("%c", &ch);

        switch (choice)
        {
            case 1:
                res = login(user, pass);
                if (res == 1)
                {
                    UpdateRecipeBox(recipeList, &recipeCount, foodList, &foodCount);
                }
                else 
                {
                    printf("\nInvalid username or password!\n");
                }
                break;
            case 2:
                AccessRecipeBox(recipeList, &recipeCount, foodList, &foodCount);
                break;
            case 3:
                printf("\nMaraming salamat sa paggamit ng aming aplikasyon!\n");
                exit = 1;
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }

    } 
    while (exit != 1);
    
    return 0;
}
