//
//  main.cpp
//  BullsAndCows
//
//  Created by Brent Perry on 7/13/16.
//  Copyright © 2016 Brent Perry. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    vector<int> to_guess = {3, 5, 1, 9};
    string user_guess;
    vector<int> int_user_guess;
    int dig1, dig2, dig3, dig4;
    int num_bulls = 0;
    int num_cows = 0;
    bool guessed = false;
    
    cout << "We're going to play Bulls and Cows, a guessing game.\n";
    cout << "I'm thinking of 4 digits (each between 0 - 9) that do not repeat.\n";
    cout << "For example, it could be 1234, but it can't be 1123 or 1231 (the 1's repeat).\n";
    cout << "Enter 4 digits (no spaces) and if you guess one digit correctly and in the right space, \n";
    cout << "then it's a 'Bull', and the right number but in the wrong spot is a 'Cow'.\n";
    cout << "For example, I'm thinking of '1234' and you guess '1378' - you get one Bull and one Cow.\n";
    
    while (!guessed) {
        cout << "Now, enter your numbers (separated by spaces).\n";
        cin >> dig1 >> dig2 >> dig3 >> dig4;
        
        int_user_guess.push_back(dig1);
        int_user_guess.push_back(dig2);
        int_user_guess.push_back(dig3);
        int_user_guess.push_back(dig4);
        
        if (int_user_guess.size() != 4) {
            cout << "You didn't enter the right number of digits. Should be 4.\n";
        } else {
            for (int i = 0; i < 4; ++i) {
                if (to_guess[i] == int_user_guess[i]) {
                    ++num_bulls;
                }
            }
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (to_guess[i] == int_user_guess[j]) {
                        ++num_cows;
                    }
                }
            }
            num_cows = num_cows - num_bulls;
            
        }
        if (num_bulls == 4) {
            cout << "You guessed it!\n";
            guessed = true;
            break;
        } else {
            cout << "You got " << num_bulls << " Bulls, and " << num_cows << " Cows. Guess again.\n";
        }
        num_cows = num_bulls = 0;
        int_user_guess.clear();
    }
}
