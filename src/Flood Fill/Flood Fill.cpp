class Solution {
public:
    void floodFillutil(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        if (sr <0 || sr >= image.size() || sc <0 || sc >= image[0].size())
            return;
        
        if (image[sr][sc] == oldColor)
        {
            image[sr][sc] = newColor;
            
            floodFillutil(image, sr-1, sc, newColor, oldColor);
            floodFillutil(image, sr, sc-1, newColor, oldColor);
            floodFillutil(image, sr+1, sc, newColor, oldColor);
            floodFillutil(image, sr, sc+1, newColor, oldColor);
        }
        
        // return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int R = image.size();
        int C = image[0].size();
        
        vector<vector<int>> result;
        if (!R || !C)
            return result;
        
        int oldColor = image[sr][sc];
        
        if (image[sr][sc] != newColor)
            floodFillutil(image, sr, sc, newColor, oldColor);
        return image;
    }
};