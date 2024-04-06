//Header Files
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

//Functions Prototypes
void Play(); void Instructions (); void Credits(); void Continue (); void Exit();

void display_board ( char P[8][8])
{
	cout << endl << endl << endl;
	cout << "\t         A     B     C     D     E     F     G     H   "      << endl << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 1    |     |  " << P[0][1] << "  |     |  " << P[0][3] << "  |     |  " << P[0][5] << "  |     |  " << P[0][7] <<"  |    1" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 2    |  " << P[1][0] << "  |     |  " << P[1][2] << "  |     |  " << P[1][4] <<"  |     |  " << P[1][6] << "  |     |    2" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 3    |     |  " << P[2][1] << "  |     |  " << P[2][3] << "  |     |  " << P[2][5] << "  |     |  " << P[2][7] <<"  |    3" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 4    |  " << P[3][0] << "  |     |  " << P[3][2] << "  |     |  " << P[3][4] <<"  |     |  " << P[3][6] << "  |     |    4" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 5    |     |  " << P[4][1] << "  |     |  " << P[4][3] << "  |     |  " << P[4][5] << "  |     |  " << P[4][7] <<"  |    5" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 6    |  " << P[5][0] << "  |     |  " << P[5][2] << "  |     |  " << P[5][4] <<"  |     |  " << P[5][6] << "  |     |    6" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 7    |     |  " << P[6][1] << "  |     |  " << P[6][3] << "  |     |  " << P[6][5] << "  |     |  " << P[6][7] <<"  |    7" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl;
	cout << "\t 8    |  " << P[7][0] << "  |     |  " << P[7][2] << "  |     |  " << P[7][4] <<"  |     |  " << P[7][6] << "  |     |    8" << endl;
	cout << "\t      +-----+-----+-----+-----+-----+-----+-----+-----+"      << endl << endl;
	cout << "\t         A     B     C     D     E     F     G     H   "      << endl;
}

char pieces [8][8] = 	 {{' ','X',' ','X',' ','X',' ','X'},
						  {'X',' ','X',' ','X',' ','X',' '},
						  {' ','X',' ','X',' ','X',' ','X'},
						  {' ',' ',' ',' ',' ',' ',' ',' '},
						  {' ',' ',' ',' ',' ',' ',' ',' '},
						  {'O',' ','O',' ','O',' ','O',' '},
						  {' ','O',' ','O',' ','O',' ','O'},
						  {'O',' ','O',' ','O',' ','O',' '}};
						  

string Player_1 ; string Player_2;

//Main Function
int main()
{
	char option;
	
	do
	{
		// Title Screen
		system("cls");
		cout <<"\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t"<<"***********************************"<<endl;
		cout<<"\t\t\t\t\t"<<"*         PROJECT CHECKERS        *"<<endl;
		cout<<"\t\t\t\t\t"<<"***********************************"<<endl<<endl;
		cout<<"\t\t\t\t\t"<<"1. Play"<<endl;
		cout<<"\t\t\t\t\t"<<"2. Instructions"<<endl;
		cout<<"\t\t\t\t\t"<<"3. Exit"<<endl<<endl;
		cout<<"\t\t\t\t\t"<<"Choose Option (1-3):";
		
		cin >> option;
	
		switch(option)
		{
			case '1':
				Play();
				break;
			case '2':
				Instructions();
				break;
		}
	}
	while(option != '3');
	Exit ();
	Credits ();
	return 0;
}

int count_X = 0; int count_O = 0;

void count_pieces ()
{
	
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			if (pieces[i][j] == 'X')
				count_X = count_X+1;
			else if (pieces[i][j] == 'O')
				count_O = count_O+1;
		}
	}
}

						  
int check_move (int current_row, int current_col, int move_row, int move_col)
{
	if (pieces[current_row][current_col] == pieces[move_row][move_col])
	{
		return 0;
	}
	else if (pieces[move_row][move_col] == ' ')
	{
		return 1;
	}
	else
	{
		if (pieces[current_row][current_col] == 'X')
		{
			if (move_col - current_col == 1)
			{
				move_row = move_row+1;	move_col = move_col+1;
				if (pieces[move_row][move_col] == ' ')
					return 2;
				else
					return 0;
			}
			else
			{
				move_row = move_row+1;	move_col = move_col-1;
				if (pieces[move_row][move_col] == ' ')
					return 2;
				else
					return 0;
			}		
		}
		else if (pieces[current_row][current_col] == 'O')
		{
			if (move_col - current_col == 1)
			{
				move_row = move_row-1;	move_col = move_col+1;
					
				if (pieces[move_row][move_col] == ' ')
					return 2;
				else
					return 0;
			}
			else
			{
				move_row = move_row-1;	move_col = move_col-1;
				
				if (pieces[move_row][move_col] == ' ')
					return 2;
				else
					return 0;
			}	
		}
	}
}

void Move_Left_Down (char move_pos[],string pos, int col, int chk)
{
	if (chk==1)
		cout << "Left-Downwards (" << (move_pos[0] = pos[0]-1) << (move_pos[1] = pos[1]+1) << ")";
	else if (chk==2 && (col!=0 || col!=1))
		cout << "Left-Downwards (" << (move_pos[0] = pos[0]-2) << (move_pos[1] = pos[1]+2) << ")";	
	else if (chk==0)
		cout << "Can not be moved";
}

void Move_Right_Down (char move_pos[],string pos, int col, int chk)
{
	if (chk==1)
		cout << "Right-Downwards (" << (move_pos[0] = pos[0]+1) << (move_pos[1] = pos[1]+1) << ")";
	else if (chk==2 && (col!=6 || col!=7))
		cout << "Right-Downwards (" << (move_pos[0] = pos[0]+2) << (move_pos[1] = pos[1]+2) << ")";	
	else if (chk==0)
		cout << "Can not be moved";
}

void Move_Left_Up (char move_pos[],string pos, int col, int chk)
{
	if (chk==1)
		cout << "Left-Upwards (" << (move_pos[0] = pos[0]-1) << (move_pos[1] = pos[1]-1) << ")";
	else if (chk==2 && (col!=0 || col!=1))
		cout << "Left-Upwards (" << (move_pos[0] = pos[0]-2) << (move_pos[1] = pos[1]-2) << ")";	
	else
		cout << "Can not be moved";
}

void Move_Right_Up (char move_pos[],string pos, int col, int chk)
{
	if (chk==1)
		cout << "Right-Upwards (" << (move_pos[0] = pos[0]+1) << (move_pos[1] = pos[1]-1) << ")";
	else if (chk==2 && (col!=6 || col!=7))
		cout << "Right-Upwards (" << (move_pos[0] = pos[0]+2) << (move_pos[1] = pos[1]-2) << ")";	
	else
		cout << "Can not be moved";
}

void kill (int old_row, int old_col, int new_row, int new_col)
{
	// RIGHT
	if (new_col == old_col+2)
	{
		// DOWN
		if (new_row == old_row+2)
		{
			pieces[old_row+1][old_col+1] = ' ';
		}
		// UP
		else if (new_row == old_row-2)
		{
			pieces[old_row-1][old_col+1] = ' ';
		}
	}
	// LEFT
	else if (new_col == old_col-2)
	{
		// DOWN
		if (new_row == old_row+2)
		{
			pieces[old_row+1][old_col-1] = ' ';
		}
		// UP
		else if (new_row == old_row-2)
		{
			pieces[old_row-1][old_col-1] = ' ';
		}
	}
}

void move (int row, int col, string pos)
{
	char move_pos_1[3] = "\0";	char move_pos_2[3] = "\0";
	int chk;
	
	cout << endl << "Select where to Move" << "\t";
	
	if (row==0)
	{
		if (col==7)
		{
			chk = check_move (row,col,(row+1),(col-1));
			Move_Left_Down (move_pos_1, pos, col, chk);
		}	
		else
		{
			chk = check_move (row,col,(row+1),(col-1));
			Move_Left_Down (move_pos_1, pos, col, chk);
			cout << "\t\t";
			chk = check_move (row,col,(row+1),(col+1));
			Move_Right_Down (move_pos_2, pos, col, chk);
		}
	}
	else if (row==7)
	{
		if (col==0)
		{
			chk = check_move (row,col,(row-1),(col+1));
			Move_Right_Up (move_pos_1, pos, col, chk);
		}
		else
		{
			chk = check_move (row,col,(row-1),(col-1));
			Move_Left_Up (move_pos_1, pos, col, chk);
			cout << "\t\t";
			chk = check_move (row,col,(row-1),(col+1));
			Move_Right_Up (move_pos_2, pos, col, chk);
		}
	}
	else if (col==0 && row%2==1)
	{
		if (pieces[row][col]=='X')
		{
			chk = check_move (row,col,(row+1),(col+1));
			Move_Right_Down (move_pos_1, pos, col, chk);
		}
		else if (pieces[row][col]=='O')
		{
			chk = check_move (row,col,(row-1),(col+1));
			Move_Right_Up (move_pos_1, pos, col, chk);
		}
	}
	else if (col==7 && row%2==0)
	{
		if (pieces[row][col]=='X')
		{
			chk = check_move (row,col,(row+1),(col-1));
			Move_Left_Down (move_pos_1, pos, col, chk);
		}
		else if (pieces[row][col]=='O')
		{
			chk = check_move (row,col,(row-1),(col-1));
			Move_Left_Up (move_pos_1, pos, col, chk);
		}
	}
	else
	{
		if (pieces[row][col]=='X')
		{
			chk = check_move (row,col,(row+1),(col-1));
			Move_Left_Down (move_pos_1, pos, col, chk);
			cout << "\t\t";
			chk = check_move (row,col,(row+1),(col+1));
			Move_Right_Down (move_pos_2, pos, col, chk);
		}
		else if (pieces[row][col]=='O')
		{
			chk = check_move (row,col,(row-1),(col-1));
			Move_Left_Up (move_pos_1, pos, col, chk);
			cout << "\t\t";
			chk = check_move (row,col,(row-1),(col+1));
			Move_Right_Up (move_pos_2, pos, col, chk);
		}
	}
	
	cout << endl;
	char choice[3] = "\0";
	cout << "Enter Position : ";
	cin.getline(choice,3);
	
	if (choice[0]>='a' && choice[0]<='z')
		choice [0] = choice[0]-32;
		
	if (strcmp(move_pos_1,choice)==0)
	{
		int r = (move_pos_1[1]-49); int c = (move_pos_1[0]-65);
		pieces [r][c] = pieces[row][col];
		pieces[row][col] = ' ';
		kill (row,col,r,c);
	}
	else if (strcmp(move_pos_2,choice)==0)
	{
		int r = (move_pos_2[1]-49); int c = (move_pos_2[0]-65);
		pieces [r][c] = pieces[row][col];
		pieces[row][col] = ' ';
		kill (row,col,r,c);
	}
	else
	{
		cout << "Invalid Entry";
		move(row,col,pos);
	}
}

int turn_check (string pos, int turn)
{
	int row = (pos[1]-49); int col = (pos[0]-65);
	if (turn%2==1 && pieces[row][col] == 'X')
		return 1;
	else if (turn%2==0 && pieces[row][col] == 'O')
		return 1;
	else
		return 0;
}

void game (int i)
{
	system ("cls");
	
	display_board(pieces);
	cout << endl << endl;
	
	if (i%2==1)
	cout << "Your turn " << Player_1 << " (X) " << "Pieces Left : " << count_X << endl;
	else
	cout << "Your turn " << Player_2 << " (O) " << "Pieces Left : " << count_O << endl; 
	
	cout << endl;
	string pos = "\0";
	
	cout << "Select A Piece to Move" <<endl;
	cout << "Enter Position (like A2,B1,C4 etc.) :";
		
	fflush(stdin);
	getline(cin,pos);
	cout <<endl;
		
	//converting to uppercase
	if (pos[0]>='a' && pos[0]<='z')
		pos [0] = pos[0]-32;
		
	int confirm;
	confirm = turn_check(pos, i);
	if ( confirm == 1)
	{	
		int row = (pos[1]-49); int col = (pos[0]-65);
		move (row,col,pos);
	}
	else
	{
		cout << "Invalid Entry";
		getch();
		game(i);
	}
}

//Play Function
void Play ()
{
	system ("cls");
	
	cout << "Player 1 Enter your Name :";
	fflush(stdin);
	getline(cin,Player_1);
	
	cout << "Player 2 Enter your Name :";
	fflush(stdin);
	getline(cin,Player_2);
		
	cout << endl << endl;
	
	count_pieces();
	for (int i=1; (count_X!=0 || count_O!=0) ;i++)
	{
		system ("cls");
		game(i);
		count_pieces();
		
	}
	
	cout << endl << endl;
	
	if (count_X == 0)
	{
		cout << Player_2 << "WINS";
		Continue();
	}
	else if (count_O == 0)
	{
		cout << Player_1 << "WINS";
		Continue();
	}
	cout << endl << endl;
}

void Continue ()
{
	
	char option;
	do
	{
		system ("cls");
		cout << endl << endl;
		cout <<"\t\t\t\t\t"<<"***********************************"<<endl;
		cout <<"\t\t\t\t\t"<<"*         PROJECT CHECKERS        *"<<endl;
		cout <<"\t\t\t\t\t"<<"***********************************"<<endl<<endl<<endl;			
		cout <<"\t\t\t\t\t\t    GAME OVER" <<endl <<endl;
		cout <<"\t\t\t\t\t"<< "1.Play Again?" <<endl;
		cout <<"\t\t\t\t\t"<< "2.Instructions" <<endl;
		cout <<"\t\t\t\t\t"<< "3.Back to Main Menu"<<endl;
		cout <<"\t\t\t\t\t"<< "4.Exit"<<endl;
		cout <<"\t\t\t\t\t"<< "Choose your Option (1-4):";
		cin >> option;
	
		switch (option)
		{ 
			case '1' : Play () ; break;
			case '2' : Instructions () ; break;
			case '3' : main () ; break;
		}
	}
	while (option != '4');
	Exit ();
}

//Instructions Function
void Instructions()
{

	system("cls");
	cout << "\t\t\t\t" << "***********************************" << endl;
	cout << "\t\t\t\t" << "*         PROJECT CHECKERS        *" << endl;
	cout << "\t\t\t\t" << "***********************************" << endl << endl << endl;
	cout << endl << endl << endl;
	cout<<"INSTRUCTIONS           "<<endl;
	cout<<"============="<<endl<<endl;
	cout<<"1. This is two player board game "<<endl;
	cout<<"2. Each player will have 12 Pieces"<<endl;
	cout<<"3. Pieces can only move diagonally"<<endl;
	cout<<"4. Pieces can only move if there is any empty space at the designated position"<<endl;
	cout<<"5. Opponent Pieces can be eliminated by jumping over the Enemy piece if the adjacent diagonal is empty"<<endl;
	cout<<"6. The objective of the game is to eliminate all pieces of the opponent"<<endl;
	cout<<"7. Pieces can be moved by entering the BOX Name where you want to move"<<endl;
	cout<<"8. BOX Name consists of an Alphabet and a Numbers shown with the display board"<<endl;
	cout<<endl;
	
	cout<<"Press any key to continue...";
	getch();
}

//Credits
void Credits ()
{
	system ("cls");
	cout<<"\t\t\t\t\t"<<"-----------------------------------"<<endl;
	cout<<"\t\t\t\t\t"<<"|        THANKS FOR PLAYING       |"<<endl;
	cout<<"\t\t\t\t\t"<<"-----------------------------------"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"\t\tGROUP"<<endl;
	cout<<"\t\t\t\t\t"<<"\t  Lightning Leopards"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"MEMBERS"<<endl;
	cout<<"\t\t\t\t\t"<<"Moazzam Haider"<<endl;
	cout<<"\t\t\t\t\t"<<"Humna Ejaz"<<endl;
	cout<<"\t\t\t\t\t"<<"Muhammad Talha"<<endl;
	cout<<endl <<endl <<endl;
	cout<<"\t\t\t\t\t"<<"Press any key to continue...";
	getch();
	exit (0);
}

void Exit ()
{
	for (int i=0;;i++)
	{
		system ("cls");
		char option;
		cout << "\t\t\t\t\t" << "***********************************" << endl;
		cout << "\t\t\t\t\t" << "*         PROJECT CHECKERS        *" << endl;
		cout << "\t\t\t\t\t" << "***********************************" << endl << endl << endl;
		cout << endl << endl << endl;
		cout <<"\t\t\t\t\t"<<"Are you sure you want to Quit?" <<endl;
		cout <<"\t\t\t\t\t"<<"1. Yes" <<endl;
		cout <<"\t\t\t\t\t"<<"2. No" <<endl;
		cout <<"\t\t\t\t\t"<<"Choose Option (1-2):";
		cin >> option;
	
		switch (option)
		{
			case '1' : Credits () ; break ;
			case '2' : main () ; break ;
		}
	}
}
