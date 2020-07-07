/* Kaitlyn Forsberg
 * This program allows two users to play tic-tac-toe and it displays who wins
 * based on the rules of tic-tac-toe.
 */

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main() 
{

	cout << endl;
	cout << "Welcome to Tic Tac Toe" << endl << endl;

	array<array<char, 3>, 3> table {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

	//display empty board
	cout << "+---+---+---+" << endl
	     << "|" << " " << table[0][0] << " " << "|" << " " << table[0][1] << " " 
	     << "|" << " " << table[0][2] << " " << "|" << endl
	     << "+---+---+---+" << endl
	     << "|" << " " << table[1][0] << " " << "|" << " " << table[1][1] << " " 
	     << "|" << " " << table[1][2] << " " << "|" << endl
	     << "+---+---+---+" << endl
	     << "|" << " " << table[2][0] << " " << "|" << " " << table[2][1] << " " 
	     << "|" << " " << table[2][2] << " " << "|" << endl
	     << "+---+---+---+" << endl << endl;

	int row, column;
	while (true) {
		cout << "X's turn" << endl;
		cout << "Pick a row (1, 2, 3): ";
		cin >> row;
		
		while (row < 1 || row > 3) {
			cout << "Invalid row. Pick a valid row (1, 2, 3)";
			cin >> row;
		}
	
		cout << "Pick a column (1, 2, 3): ";
		cin >> column;

		while (column < 1 || column > 3) {
                        cout << "Invalid column. Pick a valid column (1, 2, 3)";
                        cin >> column;
                }

		
		//if row/column empty, then an X is added
		if ((table[row-1][column-1]) == ' ') {
			table[row-1][column-1] = 'X';
		}
		else {
			while ((table[row][column]) != ' ') {
				cout << "That row/column is taken. Try again."; 
	
				cout << "Pick a row (1, 2, 3): ";
                		cin >> row;

                		while (row < 1 || row > 3) {
                        		cout << "Invalid row. Pick a valid row (1, 2, 3)";
                        		cin >> row;
                		}

                		cout << "Pick a column (1, 2, 3): ";
                		cin >> column;

                		while (column < 1 || column > 3) {
                        		cout << "Invalid column. Pick a valid column (1, 2, 3)";
                        		cin >> column;
                		}
			
				if ((table[row-1][column-1]) == (' ')) {
                        		table[row-1][column-1] = 'X';
					break;				}

			} //end while loop

		if ((table[row-1][column-1]) == (' ')) {	
			table[row-1][column-1] = 'X';
		}

		} //end else

	//display table after X is put in table
	cout << "+---+---+---+" << endl
             << "|" << " " << table[0][0] << " " << "|" << " " << table[0][1] << " "
             << "|" << " " << table[0][2] << " " << "|" << endl
             << "+---+---+---+" << endl
             << "|" << " " << table[1][0] << " " << "|" << " " << table[1][1] << " "
             << "|" << " " << table[1][2] << " " << "|" << endl
             << "+---+---+---+" << endl
             << "|" << " " << table[2][0] << " " << "|" << " " << table[2][1] << " "
             << "|" << " " << table[2][2] << " " << "|" << endl
             << "+---+---+---+" << endl << endl;
	

	//rules that would allow X to win the game	
	 if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }
        else if (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }
        else if (table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }
        else if (table[0][0] == 'X' && table[1][0] == 'X' && table[2][0] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }
        else if (table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }
        else if (table[0][2] == 'X'  && table[1][2] == 'X' && table[2][2] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }
        else if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }
        else if (table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == 'X') {
                cout << "X wins!" << endl;
                return 0;
        }


		cout << "O's turn" << endl;
                cout << "Pick a row (1, 2, 3): ";
                cin >> row;

                while (row < 1 || row > 3) {
                        cout << "Invalid row. Pick a valid row (1, 2, 3)";
                        cin >> row;
                }

                cout << "Pick a column (1, 2, 3): ";
                cin >> column;

                while (column < 1 || column > 3) {
                        cout << "Invalid column. Pick a valid column (1, 2, 3)";
                        cin >> column;
                }

		//if row/column empty then places a 0
                if ((table[row-1][column-1]) == ' ') {
		       table[row-1][column-1] = 'O';
                }
                else {
                        while ((table[row-1][column-1]) != ' ') {
                                cout << "That row/column is taken. Try again.";

                                cout << "Pick a row (1, 2, 3): ";
                                cin >> row;

                                while (row < 1 || row > 3) {
                                        cout << "Invalid row. Pick a valid row (1, 2, 3)";
                                        cin >> row;
                                }

                                cout << "Pick a column (1, 2, 3): ";
                                cin >> column;

                                while (column < 1 || column > 3) {
                                        cout << "Invalid column. Pick a valid column (1, 2, 3)";
                                        cin >> column;
                                }
			
			} //end while loop

			table[row-1][column-1] = 'O';

                } //end else

	//display table after O is placed
	cout << "+---+---+---+" << endl
             << "|" << " " << table[0][0] << " " << "|" << " " << table[0][1] << " "
             << "|" << " " << table[0][2] << " " << "|" << endl
             << "+---+---+---+" << endl
             << "|" << " " << table[1][0] << " " << "|" << " " << table[1][1] << " "
             << "|" << " " << table[1][2] << " " << "|" << endl
             << "+---+---+---+" << endl
             << "|" << " " << table[2][0] << " " << "|" << " " << table[2][1] << " "
             << "|" << " " << table[2][2] << " " <<  "|" << endl
             << "+---+---+---+" << endl << endl;

	//rules that would allow player O to win
	if (table[0][0] == 'O' && table[0][1] == 'O' && table[0][2] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
        else if (table[1][0] == 'O' && table[1][1] == 'O' && table[1][2] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
        else if (table[2][0] == 'O' && table[2][1] == 'O' && table[2][2] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
        else if (table[0][0] == 'O' && table[1][0] == 'O' && table[2][0] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
        else if (table[0][1] == 'O' && table[1][1] == 'O' && table[2][1] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
        else if (table[0][2] == 'O' && table[1][2] == 'O' && table[2][2] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
        else if (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
        else if (table[0][2] == 'O' && table[1][1] == 'O' && table[2][0] == 'O') {
                cout << "O wins!" << endl;
                return 0;
        }
	
	
	} //end while loop

	//if all options exhausted, then game is a tie
	cout << "Tie game!" << endl;

	return 0;

} //end main
