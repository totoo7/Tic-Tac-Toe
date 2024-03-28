#include <iostream>
using namespace std;

const int MAX_N = 9;

void input(int &n) {
    do {
        cout<<"Input n: ";
        cin>>n;
        cout<<"\n";
    } while (n < 3 || n > 9);
}

void buildMatrix(char board[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '-';
        }
    }
}

void fillArray(int array[], int n, int &size) {
    size = 0;
    for (int i = 0; i < n * n; i++) {
        array[i] = i;
        size++;
    }
}

int play(char str[MAX_N][MAX_N], int n, char sign)
{
	int i, j;
	do {
		cout << "Player " << sign << ": ";
		cin >> i >> j;
		if (str[i][j] != '-' || i >= n || j >= n) cout<<"Invalid coordinates"<<"\n";
	} while (str[i][j] != '-' || i >= n || j >= n);
	str[i][j] = sign;
	return i * n + j;
}

void printBoard(char str[MAX_N][MAX_N], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<str[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
bool checkMainDiagonal(char str[MAX_N][MAX_N], int n, char& winner)
{
	winner = str[0][0];
	if (winner == '-') return false;
	for (int i = 1; i < n; i++) {
		if ((winner != str[i][i])) {
			winner = '-';
			return false;
		}
	}
	return true;
}
bool checkSecondDiagonal(char str[MAX_N][MAX_N], int n, char& winner)
{
	winner = str[0][n - 1];
	if (winner == '-') return false;
	for (int i = 0; i < n; i++) {
		if (str[i][n - 1 - i] != winner) {
			winner = '-';
			return false;
		}
	}
	return true;
}
bool checkRows(char str[MAX_N][MAX_N], int n, char& winner)
{
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = true;
		winner = str[i][0];
		for (int j = 1; j < n; j++) {
			if ((str[i][j] != winner) || (winner == '-')) {
				flag = false;
				break;
			}
        }
		if (flag) return true;
	}
	return false;
}
bool checkColumns(char str[MAX_N][MAX_N], int n, char& winner)
{
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = true;
		winner = str[0][i];
		for (int j = 1; j < n; j++) {
			if ((str[j][i] != winner) || (winner == '-')) {
				flag = false;
				break;
			}
        }
		if (flag) return true;
	}
	return flag;
}

char winner(char str[MAX_N][MAX_N], int n)
{
	char win;
	char checkWinner = ' ';
	if (checkMainDiagonal(str, n, checkWinner)) win = checkWinner;
	else if (checkSecondDiagonal(str, n, checkWinner)) win = checkWinner;
	else if (checkRows(str, n, checkWinner)) win = checkWinner;
	else if (checkColumns(str, n, checkWinner)) win = checkWinner;
	else win = '-';
	return win;
}

void playWithTwoPlayers(char str[MAX_N][MAX_N], int n)
{
	char win = '-';
	printBoard(str, n);
	for (int i = 0; i < (n * n); i++)
	{
		play(str, n, 'X');
		printBoard(str, n);
		i++;
		win = winner(str, n);
		if (win != '-') break;

		play(str, n, 'O');
		printBoard(str, n);
		win = winner(str, n);
		if (win != '-') break;
	}

	if (win == '-') cout<<"Nobody wins\n";
	else cout<<"PLAYER "<<win<<" IS THE WINNER!\n";
	cout<<"\n";
}

int main() {

	char str[MAX_N][MAX_N];
	int n = 0;
	int emptySpaces[MAX_N * MAX_N];
	int size = 0;

	input(n);

	bool flag = true;
	while (flag)
	{
		buildMatrix(str, n);
		fillArray(emptySpaces, n, size);
		playWithTwoPlayers(str, n);
	}

    return 0;
}