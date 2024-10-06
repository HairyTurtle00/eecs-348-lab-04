#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    //Function for celsius to fahrenheit conversion
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    //fahrenheit to celsius conversion
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    //celsius to kelvin conversion
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    //kelvin to celsius conversion
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    //Fahrenheit to kelvin conversion
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    //Kelvin to fahrenheit conversion
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void classify(float temp) {
    //This function is in charge of giving weather reports and informing the user of the temperture 
    if (temp < 0) {
        //Tells the user that it is freezing
        printf("This temperature is freezing.\n");
        if (temp < -20) {
            printf("Weather advisory: It's very cold outside; remain indoors.\n");
        
        } else {
            //For extreme cold tell the user to wear heavy coat
            printf("Weather advisory: It's cold outside; wear a heavy coat and limit time outside.\n");
        }
    } else if (temp >= 0 && temp <= 10) {
        //Tell user it's cold
        printf("This temperature is cold.\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (temp > 10 && temp < 25) {
        //Tell user it's comfortable 
        printf("This temperature is comfortable.\n");
        printf("Weather advisory: It's a lovely day outside.\n");
    } else if (temp >= 25 && temp <= 35) {
        //tell user it's hot
        printf("This temperature is hot.\n");
        printf("Weather advisory: It's hot outside; drink lots of water and take breaks indoors.\n");
    } else {
        //Tell user not to go outside
        printf("This temperature is extreme heat.\n");
        printf("Weather advisory: It's extremely hot outside; remain indoors.\n");
    }
}

float convert(float start_units, float end_units, float temp) {
    // This function call other function to do conversions
    //Farheight to celsius
    if (start_units == 1) { 
        if (end_units == 2) { 
            return fahrenheit_to_celsius(temp);
        } 
        if (end_units == 3) { 
            //Fahrenheit to kelvin 
            return fahrenheit_to_kelvin(temp);
        }
    } else if (start_units == 2) { 
        //celsius to fahrenheit 
        if (end_units == 1) { 
            return celsius_to_fahrenheit(temp);
        }
        if (end_units == 3) { 
            //celsius to kelvin 
            return celsius_to_kelvin(temp);
        }
    } else if (start_units == 3) { 
        //kelvin to fahrenheit
        if (end_units == 1) {
            return kelvin_to_fahrenheit(temp);
        } 
        if (end_units == 2) {
            // kelvin to celsius 
            return kelvin_to_celsius(temp);
        }
    }
    return temp; 
}


int main() {
    
    while (1) {
        // main logic loop
        int start_units, end_units;
        char quit;
        float temp;
        //input loop
        printf("Please enter your temperature or (q)uit: ");
        if (scanf(" %c", &quit) != 1 || quit == 'q') {
            printf("Exiting...\n");
            break; // Exit the loop
        }


        // Convert the character back to input stream for temperature reading
        ungetc(quit, stdin);
        if (scanf("%f", &temp) != 1) {
            // Checks if the user gave bad input
            printf("You may only enter floats for temperature.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
    
        }
        printf("Please enter what units the temperature is in. 1)Fahrenheit, 2)Celsius, 3)Kelvin: ");
        //Asks the user for conversion 
        if (scanf("%d", &start_units) != 1 || start_units < 1 || start_units > 3) {
            printf("You must enter a selection between 1 and 3.\n");
            while ( getchar() != '\n' );
            continue;
        }
        if (start_units == 1 && temp < -459.67){
            //Checks for absolute zero in fahrenheigt
            printf("You cannot enter this value as it is below absolute zero.\n");
            continue;
        }
        if (start_units == 2 && temp < -273.15){
            //Checks for absoulute zero in celcius 
            printf("You cannot enter this value as it is below absolute zero.\n");
            continue;
        }

        if (start_units == 3 && temp < 0) {
            //Doesn't let the user enter negative kelvin
            printf("You may not enter negative Kelvin values.\n");
            while ( getchar() != '\n' );
            continue;
        }
    

        printf("What temperature would you like to convert to? (1)Fahrenheit, (2)Celsius, (3)Kelvin: ");
        //Checks if vaild input
        if (scanf("%d", &end_units) != 1 || end_units < 1 || end_units > 3) {
            printf("You must enter a selection between 1 and 3.\n");
            while ( getchar() != '\n' );
            continue;
        }
        if (end_units == start_units) {
            //Checks if user is trying to convert to the same units 
            printf("You cannot convert to the same units you started with.\n");
            while ( getchar() != '\n' );
            continue;
        }
        
        //Call conversion function
        float converted_temp = convert(start_units, end_units, temp);
        //Case to add F unit to end of float 
        if (end_units == 1){
            printf("Converted temperature: %.2f", converted_temp);
            printf("F \n");
        }
        //Case to add C unit to end of float
        if (end_units == 2){
            printf("Converted temperature: %.2f", converted_temp);
            printf("C \n");
        }
        //Case to add K unit to end of float
        if (end_units == 3){
            printf("Converted temperature: %.2f", converted_temp);
            printf("K \n");
        }
        //Calls the function that gives weather report 
        if (start_units == 1) {
            //converts to celsius 
            classify(fahrenheit_to_celsius(temp));
        } 
        else if (start_units == 2) {
            //Already in celsius 
            classify(temp);
        } 
        else if (start_units == 3) {
            //converts to celsius 
            classify(kelvin_to_celsius(temp));
        }
    }

}

