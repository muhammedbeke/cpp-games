game::game() {
    cout << "Welcome to tic tac toe game\n";
    bool running = true;
    for (int i = 0; i < 9; i++) {
        spaces[i] = ' ';  
    }
    drawBoard();

    while (running) {
        playerMove();
        system("cls");
        drawBoard();
        

        if (checkWinner() || checkTie()) {
            running = false;
            break;
        }

        secondPlayerMove();
        system("cls");
        drawBoard();
        
        if (checkWinner() || checkTie()) {
            running = false;
            break;
        }
    }

    cout << "Thanks for playing!\n";
}

void game::drawBoard() {
    cout << '\n';
    cout << "     |     |     \n";
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
    cout << "     |     |     \n";
    cout << '\n';
}

void game::playerMove() {
    int number;

    do {
        cout << "Enter a number for first player (1-9): ";
        cin >> number;
        number--;  

        if (number < 0 || number > 8) {
            cout << "Invalid number. Please choose a number between 1 and 9.\n";
            continue; 
        }

        if (spaces[number] == ' ') {
            spaces[number] = 'X';  
            break;
        }
        else {
            cout << "This number has been used before. Please choose another number.\n";
        }
    } while (true); 

}

void game::secondPlayerMove() {
    int number;
    do {
        cout << "Enter a number for second player (1-9): ";
        cin >> number;
        number--;  

        if (number < 0 || number > 8) {
            cout << "Invalid number. Please choose a number between 1 and 9.\n";
            continue; 
        }

        if (spaces[number] == ' ') {
            spaces[number] = 'O'; 
            break;
        }
        else {
            cout << "This number has been used before. Please choose another number.\n";
        }
    } while (true); 

}

bool game::checkWinner() {
    
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (spaces[winCombos[i][0]] != ' ' &&
            spaces[winCombos[i][0]] == spaces[winCombos[i][1]] &&
            spaces[winCombos[i][1]] == spaces[winCombos[i][2]]) {

            if (spaces[winCombos[i][0]] == 'X') {
                cout << "FIRST PLAYER WIN\n";
            }
            else {
                cout << "SECOND PLAYER WIN\n";
            }
            return true;
        }
    }

    return false;
}

bool game::checkTie() {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;  
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}