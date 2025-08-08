class Solution {
    public boolean isValidSudoku(char[][] board) {
       Set<Character>[] row = new HashSet[9];
       Set<Character>[] col = new HashSet[9];
       Set<Character>[][] boxes = new HashSet[3][3];

        for(int i=0;i<9;i++){
            row[i] = new HashSet<>();
            col[i] = new HashSet<>();
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                boxes[i][j] = new HashSet<>();
            }
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val = board[i][j];

                if(val == '.')continue;

                if(row[i].contains(val))return false;
                row[i].add(val);
                if(col[j].contains(val))return false;
                col[j].add(val);
                if(boxes[i / 3][j / 3].contains(val))return false;
                boxes[i / 3][j / 3].add(val);
            }
        }
    return true;
    }
}