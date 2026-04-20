class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // Get number of rows
        int m = matrix.size();
        // Get number of columns
        int n = matrix[0].size();

        // Traverse each cell of the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If current cell is zero
                if (matrix[i][j] == 0) {
                    // Mark all elements in this row as -1 (except existing zeros)
                    for (int col = 0; col < n; col++) {
                        if (matrix[i][col] != 0)
                            matrix[i][col] = 5000;
                    }
                    // Mark all elements in this column as -1 (except existing zeros)
                    for (int row = 0; row < m; row++) {
                        if (matrix[row][j] != 0)
                            matrix[row][j] = 5000;
                    }
                }
            }
        }

        // Second pass: replace all -1 markers with 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 5000)
                    matrix[i][j] = 0;
            }
        }
    }
};

