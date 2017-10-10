
/** 8QueenProblem
 *  8queen.cpp
 * 
 *  Problem: EightQueen Problem
 *     In chess (with an 8 × 8 board), it is possible to place eight queens on the board such that no two queens attack each other. 
 *	   Determine all such possible arrangements given the position of one of the queens (i.e. coordinate (a, b) must contain a queen). 
 *     Output the possibilities in lexicographical (sorted) order.. 
 *	   Thus, a solution requires that no two queens share the same row, column, or diagonal. 
 *  
 *  For More Description of the Problem:
 *     Wiki Link: https://en.wikipedia.org/wiki/Eight_queens_puzzle
 *      
 *  Input Format: 
 *      number of test cases in first line and test cases in each lines a b
 *	Example Input:
 		3
 		2 5
 		3 1
		7 3
 *
 *  OutPut Format:
 *      This program will out put all possible 8 queen arrangements on Chessboard with the given queen position constraint.
 *		The ouput prints the position of queen in each column
 *
 */


/*******************************************************************/
#include <iostream>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
/////////////////////////////////////////////////////////////////////
int row[8], a, b, TC, lineCounter, total =0;
/////////////////////////////////////////////////////////////////////
bool check(int r, int c){
	REP(prev, c){
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
    		return false;
	}
	if(c<b){
		if (row[b] == r || (abs(row[b] - r) == abs(b - c)))
		    return false;
	}
    return true;
}

void backtracking(int c){
	if (c==8)
		{
			printf("%2d		", ++lineCounter);
			REP(i,8) cout<< " "<< row[i]+1;
			printf("\n");
			total++;
			return;
		}

	if(c != b){
		REP(r,8){
			if (check(r,c)){
				row[c]=r; backtracking(c+1);
			}
		}
	}
	else backtracking(c+1);

}
/*******************************************************************/
int main(int argc, char const *argv[])
{
	scanf("%d",&TC);
	while(TC--){
		scanf("%d %d", &a, &b); a--;  b--; lineCounter = 0;
		memset(row, 0, sizeof row);
		cout << "For values		" << "|a = " << a << "	|b = " << b <<endl;
		cout << "SOLN	COLUMN\n";
		cout<< " #		1 2 3 4 5 6 7 8\n\n";
		row[b]=a;
		backtracking(0);
		if (TC) cout << "\n\n\n\n" << endl;
	}

	cout << "\n\n\n\n\nTotal Cases = " << total<< endl;
	return 0;
}



