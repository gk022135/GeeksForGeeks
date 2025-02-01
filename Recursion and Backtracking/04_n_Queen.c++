// n Queen problem :- in this problem you have to place n Queen on n x n chess-board(matrix) in such manner no queen comes in their way, a queen can move in such way if she present on pos [i][j] then she can move entire i row and j column and also dialoganly to corresponding position

/*
<--------------Intution---------->
you have to place n queen such that no one come in their path, so place a queen in first row and make all possible path for this queen can make move and mark it as false so other queen can't move to that position
in next step place second queen to second row do same proccess as above
<-------------------------------->
<------------Approach------------>
1. declare all required items as globally ( as you own)
   A. Declare nxn matrix intially you can  move any where so marked all element as true
      vector<vector>>bool(n, vector<bool>(n, true));
   B. Declare a result vector in which all possible  position will be store when ALL QUEEN ARE PLACED( x == ALL QUENS)
   C. make temporary vector<in>temp for storing pos of particular queen
2. Make a function which mark direction false regarding each queen which is placed so that no other queen can move to this position
3. Make function for making move for each queen 
   A. check base case if index == n(Total Queen) 
        then push tempoary temp to result 
          // index --> (0 - n) queen1 to queenN
   B. iterate 
<-------------------------------->
*/