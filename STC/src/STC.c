// Simple Temperature Converter - (EN/US) - V 1.0.0 Stable.

#include <stdio.h>

float Convert (float UFM, int Type);

int main (void) {

    float NumUser = 0;
    int Op = 0, PLUser = 0;
    char EndAsk = 'A';

    puts ("Welcome to the Simple Temperature Converter!\n\n");

    puts ("WARNING: If you need to use decimal numbers, only use '.', never use ','.");
    puts ("WARNING: Be careful with invalid characters, they can make mistakes...\n\n");

    do { NumUser = 0, Op = 0, PLUser = 0, EndAsk = 'A';

        puts ("Please use numbers to indicate your operation:\n");

        puts ("1: Celsius (C) to Fahrenheit (F).");
        puts ("2: Celsius (C) to Kelvin (K).");
        puts ("3: Celsius (C) to Rankine (R).\n");

        puts ("4: Fahrenheit (F) to Celsius (C).");
        puts ("5: Fahrenheit (F) to Kelvin (K).");
        puts ("6: Fahrenheit (F) to Rankine (R).\n");

        puts ("7: Kelvin (K) to Celsius (C).");
        puts ("8: Kelvin (K) to Fahrenheit (F).");
        puts ("9: Kelvin (K) to Rankine (R).\n");

        puts ("10: Rankine (R) to Celsius (C).");
        puts ("11: Rankine (R) to Fahrenheit (F).");
        puts ("12: Rankine (R) to Kelvin (K).\n");

        puts ("13: Exit.\n");
        
        scanf ("%d", &Op);

        if (Op == 13) { puts ("\nExiting..."); return 0; }
        else if (Op > 13 || Op < 1) { puts ("\nERROR: Please enter a valid number!\nResetting...\n\n"); continue; }

        puts ("\nPlease enter the number of temperature to be converted:\n");

        scanf ("%f", &NumUser);
        
        puts ("\nDo you want to use the default settings?\n");

        puts ("1: Yes, use the default 2 decimal places.");
        puts ("2: No, choose the precision.\n");

        scanf ("%d", &PLUser);

        if (PLUser == 1 || PLUser == 2) {

            if (PLUser == 2) { puts ("\nPlease enter the number of decimal places (from 1 to 6):\n"); scanf ("%d", &PLUser); }
            else if (PLUser == 1) { PLUser = 2; }

            if (PLUser < 1) { PLUser = 1; }
            else if (PLUser > 6) { PLUser = 6; }

        } else { puts ("\nERROR: Please enter a valid number!\nResetting...\n\n"); continue; }

        switch (Op) {

            case 1: { printf ("\nResult: %.*f - Fahrenheits.\n", PLUser, Convert (NumUser, 1) ); break; } // Celsius (°C) to Fahrenheit (°F).
            case 2: { printf ("\nResult: %.*f - Kelvins.\n", PLUser, Convert (NumUser, 2) ); break; } // Celsius (°C) to Kelvin (K).
            case 3: { printf ("\nResult: %.*f - Rankines.\n", PLUser, Convert (NumUser, 3) ); break; } // Celsius (°C) to Rankine (°R).

            case 4: { printf ("\nResult: %.*f - Celsius.\n", PLUser, Convert (NumUser, 4) ); break; } // Fahrenheit (°F) to Celsius (°C).
            case 5: { printf ("\nResult: %.*f - Kelvins.\n", PLUser, Convert (NumUser, 5) ); break; } // Fahrenheit (°F) to Kelvin (K).
            case 6: { printf ("\nResult: %.*f - Rankines.\n", PLUser, Convert (NumUser, 6) ); break; } // Fahrenheit (°F) to Rankine (°R).

            case 7: { printf ("\nResult: %.*f - Celsius.\n", PLUser, Convert (NumUser, 7) ); break; } // Kelvin (K) to Celsius (°C).
            case 8: { printf ("\nResult: %.*f - Fahrenheits.\n", PLUser, Convert (NumUser, 8) ); break; } // Kelvin (K) to Fahrenheit (°F).
            case 9: { printf ("\nResult: %.*f - Rankines.\n", PLUser, Convert (NumUser, 9) ); break; } // Kelvin (K) to Rankine (°R).

            case 10: { printf ("\nResult: %.*f - Celsius.\n", PLUser, Convert (NumUser, 10) ); break; } // Rankine (°R) to Celsius (°C).
            case 11: { printf ("\nResult: %.*f - Fahrenheits.\n", PLUser, Convert (NumUser, 11) ); break; } // Rankine (°R) to Fahrenheit (°F).
            case 12: { printf ("\nResult: %.*f - Kelvins.\n", PLUser, Convert (NumUser, 12) ); break; } // Rankine (°R) to Kelvin (K).
        }

        puts ("\nFinished! Do you want to restart? (Y/N):\n");

        scanf (" %c", &EndAsk);

        if (EndAsk == 'Y' || EndAsk == 'y') { puts ("\nResetting...\n\n"); continue; }
        else if (EndAsk == 'N' || EndAsk == 'n') { puts ("\nExiting..."); return 0; }
        else { puts ("\nERROR: Please check if you used Y/N!\nResetting...\n\n"); }

    } while (1);

    return 0;
}

// End of the main function. *****----------------------------------------------------------------------------------------------------*****

float Convert (float UFM, int Type) {

    float Result = 0;

    switch (Type) {

        case 1: { Result = UFM * 1.8 + 32; break; } // Celsius (°C) to Fahrenheit (°F).
        case 2: { Result = UFM + 273.15; break; } // Celsius (°C) to Kelvin (K).
        case 3: { Result = (UFM + 273.15) * 1.8; break; } // Celsius (°C) to Rankine (°R).

        case 4: { Result = (UFM - 32) * 5 / 9; break; } // Fahrenheit (°F) to Celsius (°C).
        case 5: { Result = (UFM - 32) * 5 / 9 + 273.15; break; } // Fahrenheit (°F) to Kelvin (K).
        case 6: { Result = UFM + 459.67; break; } // Fahrenheit (°F) to Rankine (°R).

        case 7: { Result = UFM - 273.15; break; } // Kelvin (K) to Celsius (°C).
        case 8: { Result = (UFM - 273.15) * 1.8 + 32; break; } // Kelvin (K) to Fahrenheit (°F).
        case 9: { Result = UFM * 1.8; break; } // Kelvin (K) to Rankine (°R).

        case 10: { Result = UFM * 5 / 9 - 273.15; break; } // Rankine (°R) to Celsius (°C).
        case 11: { Result = UFM - 459.67; break; } // Rankine (°R) to Fahrenheit (°F).
        case 12: { Result = UFM * 5 / 9; break; } // Rankine (°R) to Kelvin (K).
    }

    UFM = 0, Type = 0;

    return Result;
}

// End of the code.