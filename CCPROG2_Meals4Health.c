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
   Pre-condition: fp must be successfully opened in read ("r") mode.
*/
int fstrwspace(FILE *fp, 
    char string[])
{
	char ch;
	int i = 0;
	int x;
	
	while ((x = fscanf(fp, "%c", &ch)) == 1 && ch != '\n')
	{   
        string[i] = ch;
        i++;
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

/* UpdateRecipeBox serves as the menu and handler for all Update Mode features
   @param recipe - the master array of recipe structures
   @param calorie_count - integer array tracking calorie counts
   @param food_item - the master array of ingredient structures
   Pre-condition: recipe and food_item arrays must be properly initialized in main
*/
void UpdateRecipeBox(struct recipeTag recipe[50], 
    int calorie_count[50], 
    struct ingredientTag food_item[50])
{
    // 50 recipes and 50 food items/ingredients
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
        return;
    }

    for (i = 0; i < fooditemCount && flag == 0; i++)
    {
        printf("\nFood Item: %s   Quantity: %.2lf    Unit: %s    Calories: %d", fooditem[i].item, fooditem[i].quantity, fooditem[i].unit, fooditem[i].calorieCount);
        if ((i + 1) % 10 == 0 && (i + 1) < fooditemCount)
        {
            printf("\nContinue? (N for Next or X to exit):  ");
            scanf(" %c", &ch);
            if (ch == 'X' || ch == 'x'){
                flag = 1;
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
                fprintf(fp, "%lf %s %d\n", &fooditem[i].quantity, fooditem[i].unit, &fooditem[i].calorieCount);
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
        while (fstrwspace(fp, fooditem[*fooditemCount].item) == 1)
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
        if (strcmp("starter", recipe[*recipeCount].classification) != 0 && strcmp("main", recipe[*recipeCount].classification) != 0 && strcmp("dessert", recipe[*recipeCount].classification) != 0)
        {
            printf("\nThat is an invalid classification! Reinput classification.");
            scanf("%s", recipe[*recipeCount].classification);
        }
    printf("\nEnter Number of Servings: ");
    scanf("%d", &recipe[*recipeCount].serving);
    do 
    {
        updAddIngredient(recipe, *recipeCount);
        printf("\nWould you like to add another ingredient (Y/N)? ");
        scanf(" %c",&leftover); // Added space to catch leftover newlines
    }while (leftover != 'N' && leftover != 'n');

    do 
    {
        updAddStep(recipe, *recipeCount);
        printf("\nWould you like to add another instruction (Y/N)? ");
        scanf(" %c",&leftover); // Added space to catch leftover newlines
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
{/*list of all recipe titles will be displayed in ALPHABETICAL order (call ListRecipeTitles). 
user inputs name of dish to modify. user is then asked which info will be changed.*/
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
    printf("\nEnter the Quantity: ");
    scanf("%lf",&recipe[TargetIndex].ingredient[ingslot].quantity);
    printf("\n-> Successfully saved: %lf \n", recipe[TargetIndex].ingredient[ingslot].quantity);

    printf("\nEnter the Unit: ");
    strwspace(recipe[TargetIndex].ingredient[ingslot].unit,16);
    printf("\n-> Successfully saved: %s \n", recipe[TargetIndex].ingredient[ingslot].unit);

    printf("\nEnter the Item Name: ");
    strwspace(recipe[TargetIndex].ingredient[ingslot].item,21);
    printf("\n-> Successfully saved: %s \n", recipe[TargetIndex].ingredient[ingslot].item);

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
    printf("\nEnter the Instrcution: ");
    strwspace(recipe[TargetIndex].instruc[stepslot],16);
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

/* updScanRecipes sorts the recipe array alphabetically and displays each dish one at a time, calculating and 
   presenting the individual ingredient calories and total recipe calories by cross-referencing the master food item array, 
   while providing an interactive menu to navigate to the next or previous recipe.
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
void updScanRecipes(struct recipeTag recipe[], 
    int recipeCount, 
    struct FoodItemTag fooditem[], 
    int fooditemCount)
{

    struct recipeTag temp;
    int i, j, k, found;
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
                printf("%.2lf %s %s %d\n", recipe[currentIndex].ingredient[i].quantity, recipe[currentIndex].ingredient[i].unit, recipe[currentIndex].ingredient[i].item, currentIngredientCal);    
            }

            printf("Procedures:\n");
            for (i = 0; i < recipe[currentIndex].stepcount; i++)
            {
                printf("%d. %s\n", i + 1, recipe[currentIndex].instruc[i]);
            }
        
        printf("N = Next, P = Previous, X = Exit\nInput: "); //if user chooses X or x, the while loop stops and acts as the exit page
        scanf(" %c", &ch);
        if ((ch == 'N' || ch == 'n') && currentIndex < recipeCount - 1)
        {
            currentIndex++; //next page
        }
        else if ((ch == 'P' || ch == 'p') && currentIndex > 0)
        {
            currentIndex--; //previous page
        }
        else if ((ch == 'P' || ch == 'p') && currentIndex == 0)
        {
            printf("There is no previous page!\n");
        }
        } while ((ch != 'X' && ch != 'x') && currentIndex < recipeCount); //while the user does not choose to exit or under amount of recipes
        
    }
}

/* updSearchRecipeByTitle presents an alphabetical list of all saved recipes, prompts the user to input a specific dish name to search for, and utilizes the hanapinIndex helper function to retrieve and print all corresponding details including classification, ingredients, and procedural steps.
   @param recipe - the master array of recipe struct to search through
   @param recipeCount - the total number of valid recipes currently stored
   Pre-condition: recipeCount must be greater than or equal to 0, and the recipe array must be populated with valid data.
*/
void updSearchRecipeByTitle(struct recipeTag recipe[], 
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
                fprintf(fp,"%d %s\n", &recipe[i].serving, recipe[i].classification);

                //Ingredients section
                fprintf(fp,"Ingredients %d\n", recipe[i].ingcount);
                for (j = 0; j < recipeCount; j++)
                {
                    fprintf(fp,"%lf %s %s\n", &recipe[i].ingredient[j].quantity, recipe[i].ingredient[j].unit, recipe[i].ingredient[j].item);
                }

                //Steps section
                fprintf(fp,"Steps %d\n", recipe[i].stepcount);
                for (j = 0; j < recipeCount; j++)
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

/* updImportRecipes reads a formatted text file to extract recipe data into a temporary struct, cross-references the dish name 
   against the existing database to handle overwrite permissions, and safely integrates the parsed data into the master array 
   while skipping over any blank lines.
   @param recipe - the master array of recipe struct where the imported data will be saved
   @param recipeCount - the address of the integer tracking the total number of recipes, which will be updated as new dishes are added
   Pre-condition: The target text file must exist and strictly follow the formatting guidelines established by the export function.
*/
void updImportRecipes(struct recipeTag recipe[], 
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
        *recipeCount = 0;
        while (fstrwspace(fp, recipe[*recipeCount].dish_name) == 1)
        {
            isBlank = 0;

            if (strlen(recipe[*recipeCount].dish_name) == 0)
                isBlank = 1;

            if (isBlank == 0)
            {
                fscanf(fp, "%d %s", &temp.serving, temp.classification);
                fscanf(fp, "%c", &cTemp); 
                //Read Ingredients
                fscanf(fp, "%s %d", sTemp, &temp.ingcount);
                fscanf(fp, "%c", &cTemp);
                for (j = 0; j < recipeCount; j++)
                {
                    fscanf(fp, "%lf %s", &temp.ingredient[j].quantity, temp.ingredient[j].unit);
                    fscanf(fp, "%c", &cTemp); 
                    fGetStrwspace(fp, temp.ingredient[j].item);
                }
                //Read Steps
                fscanf(fp, "%s %d", sTemp, &temp.stepcount);
                fscanf(fp, "%c", &cTemp);
                for (j = 0; j < recipeCount; j++)
                {
                    fGetStrwspace(fp, temp.instruc[j]);
                }
                index = hanapinIndex(recipe, *recipeCount, temp.dish_name);

                if (index != -1)
                {
                    printf("\nRecipe '%s' already exists. Overwrite? (Y/N): ", temp.dish_name);
                    scanf("%c", &overwriteChoice);

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
        printf("\nFinished importing recipes from %s!\n", *recipeCount, filename);
    }
    else
    {
        printf("Whoops! Could not open %s", filename);
    }
}

void updReturnMainMenu()
{
//allows user to quit UPDATE MODE and return to MAIN MENU. information in lists should be cleared after this option.
}


void AccessRecipeBox()
{
    
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
    if ((ch == 'N' || ch == 'n') && currentIndex < matchCount - 1)
    {
        currentIndex++; //next page
    }
    else if ((ch == 'P' || ch == 'p') && currentIndex > 0)
    {
        currentIndex--; //previous page
    }
    else if ((ch == 'P' || ch == 'p') && currentIndex == 0)
    {
        printf("There is no previous page!\n");
    }
    } while ((ch != 'X' && ch != 'x') && currentIndex < matchCount); //while the user does not choose to exit or under amount of recipes
    }
    }
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
