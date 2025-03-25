#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int width;
	int height;
};

bool compare(Rectangle a, Rectangle b) {
    return a.height > b.height;
}

void stripPacking(int stripWidth, vector<Rectangle> &rectangles) {
    sort(rectangles.begin(), rectangles.end(), compare);
    
    vector<int> levels;
    
    for (auto &rect : rectangles) {
        bool placed = false;
        
        for (int &level : levels) {
            if (level >= rect.width) {
                level -= rect.width;
                placed = true;
                break;
            }
        }
        
        if (!placed)
            levels.push_back(stripWidth - rect.width);
    }
    
    cout << "Total levels used: " << levels.size() << endl;
}

int main() {
    vector<Rectangle> rectangles = {{5, 4}, {3, 2}, {6, 4}, {2, 1}, {4, 3}};
    int stripWidth = 10;
    
    stripPacking(stripWidth, rectangles);
    
    return 0;
}
