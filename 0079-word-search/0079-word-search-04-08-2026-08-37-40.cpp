class Solution {
public:
//backtracking = dfs
int n,m;
bool dfs(int i, int j, vector<vector<char>>& board, string word,int len_of_word_found){
       if(len_of_word_found == word.length())
            return true;
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        if(board[i][j]!= word[len_of_word_found] || board[i][j]=='!')
            return false; //already vis    

        char temp = board[i][j]; //asked in ques
        board[i][j] ='!';      // mark vis-> norml dfs me v krte
 
        bool ans = dfs(i-1, j, board, word, len_of_word_found+1 ) ||
                   dfs(i+1, j, board, word, len_of_word_found+1 ) ||
                   dfs(i, j-1, board, word, len_of_word_found+1 ) ||
                   dfs(i, j+1, board, word, len_of_word_found+1 );
        //after recursive call for i and j: (same in segTree) 
        board[i][j] = temp;   //mark unvisitd for other paths
        return ans;
}
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if( dfs(i,j,board,word,0) )
                        return true;
                }
            }
        }
        return false;
     }//1. Why Mark as Visited (board[i][j] = '!'
      //Prevents revisiting the same cell in the current path.
    // Without marking, the DFS would loop infinitely (e.g., A → B → A → B → ...).
    // Example:
    // For word = "AB", board:
    // A B
    // B A
    // If you don't mark A (0,0) as visited, after A → B, 
    // the DFS would try to go  back to A (0,0) again.

    //     2. Why Unmark After DFS (board[i][j] = temp)?
    // Restores the board for other paths to use this cell.
    // Example:
    // Consider a board:
    // A B C
    // D E F
    // G H I
    // and word = "ABEH" (path: A→B→E→H).
    // After exporin this path, we must unmark E (so that if there's 
    // another valid path like D→E→H→I..., E is available again).
    //warna D->!->!->I konsa path hota

// Step  	                Action	                Why?
// 1. Enter cell (i,j)	    board[i][j] = '!'	Block this cell for the current path
// 2. Explore neighbors	    DFS recursively	    Check all 4 directions
// 3. Backtrack	            board[i][j] = temp	Restore cell for other paths
// 4. Return result     	return ans	   Success/failure of the current path



// Let's visualize the backtracking process.We'll walk through the DFS steps for a small board and word, showing how marking and unmarking works.

// e.g. Board (3x3):
// A B C
// D E F
// G H I
// Word to find: "ABE"
// Path: A(0,0) → B(0,1) → E(1,1)
// Step-by-Step Visualization
// Initial State
// Board:
//   [ ['A', 'B', 'C'],
//     ['D', 'E', 'F'],
//     ['G', 'H', 'I'] ]
// Step 1: Start at (0,0) → 'A'
// board[0][0] = 'A' matches word[0] = 'A'
// Mark as visited: board[0][0] = '!'
// Board after marking:
// [ ['!', 'B', 'C'],
//   ['D', 'E', 'F'],
//   ['G', 'H', 'I'] ]
// Why? Prevents revisiting A in the current path.
// Step 2: Move Right to (0,1) → 'B'
// board[0][1] = 'B' matches word[1] = 'B'
// Mark as visited: board[0][1] = '!'
// Board after marking:
// [ ['!', '!', 'C'],
//   ['D', 'E', 'F'],
//   ['G', 'H', 'I'] ]
// Why? Prevents going back to B (e.g., A → B → A).
// Step 3: Move Down to (1,1) → 'E'
// board[1][1] = 'E' matches word[2] = 'E'
// Word found! → Return true
// Board at this point:
// [ ['!', '!', 'C'],
//   ['D', '!', 'F'],
//   ['G', 'H', 'I'] ]
// Why Unmarking is Critical
// Now, imagine another path needs to use (0,0) or (0,1) (e.g., if the word was "ADE" instead of "ABE"). Without unmarking, the board would stay corrupted:

// Without Unmarking
// After finding "ABE", the board would remain:
// [ ['!', '!', 'C'],
//   ['D', '!', 'F'],
//   ['G', 'H', 'I'] ]
// Problem: A and B are permanently marked as '!'.
// Consequence: The path A(0,0) → D(1,0) → E(1,1) would fail because:
// board[0][0] = '!' → can't start at A.
// Even if we started elsewhere, the board is corrupted.
// With Unmarking (Correct Behavior)
// After the DFS returns true (or false), we unmark the cell to restore the board:

// Step 4: Unmark (1,1) → 'E'
// Before unmarking:
// [ ['!', '!', 'C'],
//   ['D', '!', 'F'],
//   ['G', 'H', 'I'] ]
// After unmarking (set back to 'E'):
// [ ['!', '!', 'C'],
//   ['D', 'E', 'F'],
//   ['G', 'H', 'I'] ]
// Step 5: Unmark (0,1) → 'B'
// Before unmarking:
// [ ['!', '!', 'C'],
//   ['D', 'E', 'F'],
//   ['G', 'H', 'I'] ]
// After unmarking (set back to 'B'):
// [ ['!', 'B', 'C'],
//   ['D', 'E', 'F'],
//   ['G', 'H', 'I'] ]
// Step 6: Unmark (0,0) → 'A'
// Before unmarking:
// [ ['!', 'B', 'C'],
//   ['D', 'E', 'F'],
//   ['G', 'H', 'I'] ]
// After unmarking (set back to 'A'):
// [ ['A', 'B', 'C'],
//   ['D', 'E', 'F'],
//   ['G', 'H', 'I'] ]
// Why This Matters
// Action	What Happens	Without Unmarking	With Unmarking
// Mark cell	Prevents revisiting in current path	❌ Board gets corrupted	✅ Board stays clean for other paths
// Unmark cell	Restores board state after DFS	❌ Path ADE fails	✅ Path ADE can now be explored
// Key Insight
// Marking = "This cell is busy in my current path."
// Unmarking = "This cell is now free for other paths."
// This is the backtracking pattern:

// Try a path (mark cell).
// Explore all directions.
// Revert the change (unmark cell) to allow other paths.
// Visual Summary
// Initial Board:        After Marking A:    After Marking B:    After Finding "ABE":
//   A B C                 ! B C                ! ! C                ! ! C
//   D E F                 D E F                D E F                D ! F
//   G H I                 G H I                G H I                G H I

// After Unmarking:      (Restored to original state)
//   A B C
//   D E F
//   G H I
// 💡 Remember: Unmarking is not optional. It’s the reason backtracking works for multiple paths. Without it, the solution would fail for all test cases with more than one valid path.


};