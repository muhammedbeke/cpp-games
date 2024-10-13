class game {
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char player = 'X';
    char computer = 'O';
    bool running = true;
public:
    game();  
    void drawBoard();
    void playerMove();
    void secondPlayerMove();
    bool checkWinner();
    bool checkTie();
};
