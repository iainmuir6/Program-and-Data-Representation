// Iain Muir, iam9ez
// March 4th, 2020
// wordPuzzle.cpp --> post-lab

#include "timer.h"
#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include <unordered_set>
using namespace std;

// load factor for the hashtablex
#define LOADFACTOR 0.5

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);


/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;  --> not neccessary output

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " columns." << endl;  --> not neccessary output

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

// ----------------------------------------------------------------------------------------

bool checkprime(unsigned int p) {
  if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
    return false;
  if ( p == 2 ) // 2 is prime
    return true;
  if ( p % 2 == 0 ) // even numbers other than 2 are not prime
    return false;
  for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
    if ( p % i == 0 )
      return false;
  return true;
}

int getNextPrime (unsigned int n) {
  while ( !checkprime(++n) );
  return n; // all your primes are belong to us
}

// ----------------------------------------------------------------------------------------

int main (int argc, char **argv) {
  ifstream dictionary(argv[1]);
  if (!dictionary.is_open()) {
    cout << "File did not open!" << endl;
    return 1;
  }
  
  int dicCount = 0;
  string words;
  while (dictionary >> words) {
    dicCount++;
  }
  //cout << dicCount << endl;  --> not neccessary output
  dictionary.close();
  
  // ------------------------------
  
  ifstream dictionary2(argv[1]);
  if (!dictionary2.is_open()) {
    cout << "File did not open!" << endl;
    return 1;
  }

  int htSize = getNextPrime(dicCount / LOADFACTOR);
  hashTable ht(htSize);
  /*
  int htSize = dicCount * LOADFACTOR;
  hashTable ht(htSize);
  */
  
  //unordered_set <string> ht;
  
  while (dictionary2 >> words) {
    ht.insert(words);
  }
 
  dictionary2.close();

  // ------------------------------

  // to hold the number of rows and cols in the input file
  int rows, cols;

  // attempt to read in the file
  bool result = readInGrid(argv[2], rows, cols);

  // if there is an error, report it
  if (!result) {
    cout << "Grid was not successfully read in..." << endl;
    return 1;
  }

  vector<string> foundWords; // --> used to buffer the output
  
  timer* t = new timer();
  t->start();
  
  int wordCount = 0 ;
  string direction;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = 0; k < 8; k++) {


	// Eliminates unnecesary word searches
	if (i < 2 && (k == 0 | k == 1 | k == 7)) { // if top two rows and N
	  continue;
	}    

	if (i > (rows-2) && (k == 3 | k == 4 | k == 5)) { // if bottom two rows and S
	  continue;
	}
	
	if (j < 2 && (k == 5 | k == 6 | k == 7)) { // if first two columns and W
	  continue;
	}

	if (j > (cols-2) && (k == 1 | k == 2 | k == 3)) { // if last two columns and E
	  continue;
	}
	
	
	for (int l = 0; l < 23; l++) {
	  string word = getWordInGrid(i, j, k, l, rows, cols);
	  if (word.length() >= 3 && ht.find(word)) {  
	    if (word.length() != l) { // if the word is out of the grid
	      break;
	    }  
	    if (k == 0) {
	      direction = "N";
	    }  
	    if (k == 1) {
	      direction = "NE";
	    }
	    if (k == 2) {
	      direction = "E";
	    }
	    if (k == 3) {
	      direction = "SE";
	    }
	    if (k == 4) {
	      direction = "S";
	    }
	    if (k == 5) {
	      direction = "SW";
	    }
	    if (k == 6) {
	      direction = "W";
	    }
	    if (k == 7) {
	      direction = "NW";
	    }
	    foundWords.push_back(direction + " (" + to_string(i) + "," + to_string(j) + "):        " + word);
	    wordCount++;
	  }  
	}  
      }
    }  
  }
  t->stop();

  
  for (int i = 0; i < foundWords.size(); i++) {
    cout << foundWords[i] << endl;
  }
  
  cout << wordCount << " words found" << endl;
  cout << "Found all words in " << t->getTime() << " seconds" << endl;
  
  //cout << int(t->getTime() * 1000)  << endl;
  
  return 0;
}


	
