#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

#define ROW_SIZE        15
#define COLUMN_SIZE     15
#define WORDS_SIZE      16


char puzzle[ROW_SIZE][COLUMN_SIZE] = {
    {'a', 'x', 'd', 'u', 'r', 'y', 'h', 'p', 's', 'p', 't', 't', 'i', 'd', 't'},
    {'v', 'n', 'x', 's', 'e', 'c', 'a', 'q', 'c', 'u', 'i', 'u', 'o', 'z', 'p'},
    {'m', 'e', 'r', 'g', 'f', 'w', 'o', 'z', 'i', 's', 'n', 'l', 'k', 'a', 'c'},
    {'v', 's', 'c', 'x', 's', 'e', 's', 'x', 'o', 'f', 'l', 'w', 'z', 'j', 'z'},
    {'v', 't', 'r', 'p', 'n', 'd', 'l', 'p', 'b', 'a', 'c', 'h', 'e', 'b', 'y'},
    {'p', 'r', 'e', 'k', 'a', 'w', 'e', 'c', 'r', 'c', 't', 'x', 'n', 's', 'b'},
    {'f', 'p', 'd', 'm', 'r', 'd', 'l', 'o', 's', 'p', 'e', 'j', 'a', 'q', 't'},
    {'w', 'h', 'i', 'n', 't', 'l', 'y', 'i', 'b', 't', 'c', 'a', 's', 'h', 'n'},
    {'l', 'a', 't', 'c', 'i', 'q', 'n', 'n', 'r', 'i', 'l', 'h', 't', 'y', 'j'},
    {'k', 'r', 'r', 'x', 'o', 'i', 'f', 'k', 'y', 'b', 'w', 'o', 'e', 'w', 'a'},
    {'v', 'c', 'p', 'd', 'u', 'y', 'z', 'k', 'l', 'e', 't', 'n', 'a', 'k', 'w'},
    {'i', 'u', 'e', 'o', 'h', 'k', 'n', 'a', 'b', 'd', 'o', 't', 'a', 'n', 'a'},
    {'f', 'a', 'q', 'h', 'y', 't', 'j', 'b', 'i', 'm', 'y', 'm', 'u', 'd', 's'},
    {'v', 'q', 'z', 'f', 'c', 'j', 'i', 'e', 'e', 'm', 'n', 'k', 'u', 'x', 'l'},
    {'b', 'a', 'l', 'a', 'n', 'c', 'e', 'w', 'e', 'c', 'n', 'u', 'o', 'p', 'b'}
};

const char *words[WORDS_SIZE] = {
    "balance",
    "bank",
    "cash",
    "check",
    "coin",
    "credit",
    "debit",
    "deposit",
    "dollar",
    "loan",
    "money",
    "paws",
    "pounce",
    "sunwest",
    "transfer",
    "withdraw"
};

void findAndReplaceWords() {
  for (int i = 0; i < WORDS_SIZE; i++) {
    const char * word = words[i];
    int len = strlen(word);
    int found = 0;
    for (int row = 0; row < ROW_SIZE && !found; row++) {
      for (int col = 0; col <= COLUMN_SIZE - len && !found; col++) {
        if (strncmp( & puzzle[row][col], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row][col + k] = toupper(puzzle[row][col + k]);
          }
          found = 1;
        }
      }
    }

    for (int row = 0; row < ROW_SIZE && !found; row++) {
      for (int col = COLUMN_SIZE - 1; col >= len - 1 && !found; col--) {
        if (strncmp( & puzzle[row][col - len + 1], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row][col - k] = toupper(puzzle[row][col - k]);
          }
          found = 1;
        }
      }
    }

    for (int col = 0; col < COLUMN_SIZE && !found; col++) {
      for (int row = 0; row <= ROW_SIZE - len && !found; row++) {
        if (strncmp( & puzzle[row][col], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row + k][col] = toupper(puzzle[row + k][col]);
          }
          found = 1;
        }
      }
    }

    for (int col = 0; col < COLUMN_SIZE && !found; col++) {
      for (int row = ROW_SIZE - 1; row >= len - 1 && !found; row--) {
        if (strncmp( & puzzle[row - len + 1][col], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row - k][col] = toupper(puzzle[row - k][col]);
          }
          found = 1;
        }
      }
    }

    for (int startRow = 0; startRow <= ROW_SIZE - len && !found; startRow++) {
      for (int startCol = 0; startCol <= COLUMN_SIZE - len && !found; startCol++) {
        int matched = 1;
        for (int k = 0; k < len; k++) {
          if (puzzle[startRow + k][startCol + k] != word[k]) {
            matched = 0;
            break;
          }
        }
        if (matched) {
          for (int k = 0; k < len; k++) {
            puzzle[startRow + k][startCol + k] = toupper(puzzle[startRow + k][startCol + k]);
          }
          found = 1;
        }
      }
    }

    for (int row = 0; row <= ROW_SIZE - len && !found; row++) {
      for (int col = 0; col <= COLUMN_SIZE - len && !found; col++) {
        if (strncmp( & puzzle[row][col], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row + k][col + k] = toupper(puzzle[row + k][col + k]);
          }
          found = 1;
        }
      }
    }

    for (int row = ROW_SIZE - 1; row >= len - 1 && !found; row--) {
      for (int col = 0; col <= COLUMN_SIZE - len && !found; col++) {
        if (strncmp( & puzzle[row][col], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row - k][col + k] = toupper(puzzle[row - k][col + k]);
          }
          found = 1;
        }
      }
    }

    for (int row = 0; row <= ROW_SIZE - len && !found; row++) {
      for (int col = COLUMN_SIZE - 1; col >= len - 1 && !found; col--) {
        if (strncmp( & puzzle[row][col - len + 1], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row + k][col - k] = toupper(puzzle[row + k][col - k]);
          }
          found = 1;
        }
      }
    }

    for (int row = ROW_SIZE - 1; row >= len - 1 && !found; row--) {
      for (int col = COLUMN_SIZE - 1; col >= len - 1 && !found; col--) {
        if (strncmp( & puzzle[row][col - len + 1], word, len) == 0) {
          for (int k = 0; k < len; k++) {
            puzzle[row - k][col - k] = toupper(puzzle[row - k][col - k]);
          }
          found = 1;
        }
      }
    }

  }
}

int main() {
  findAndReplaceWords();
  for (int i = 0; i < ROW_SIZE; i++) {
    for (int j = 0; j < COLUMN_SIZE; j++) {
      cout << puzzle[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
