#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random

int select(int k, std::vector<int>& S) {
    if (S.size() == 1) {
        return S[0]; // Base case
    }
    
    // Randomly choose a pivot
    srand(time(0));
    int pivotIndex = rand() % S.size();
    int pivot = S[pivotIndex];
    
    // Partition into S1, S2, S3
    std::vector<int> S1, S2, S3;
    for (int num : S) {
        if (num < pivot) {
            S1.push_back(num);
        } 
        else if (num == pivot) {
            S2.push_back(num);
        } 
        else {
            S3.push_back(num);
        }
    }
    
    // Determine which partition contains the kth element
    if (S1.size() >= k) {
        return select(k, S1);
    } 
    else if (S1.size() + S2.size() >= k) {
        return pivot;
    } 
    else {
        return select(k - S1.size() - S2.size(), S3);
    }
}

int main() {
    std::vector<int> S = {7, 10, 4, 3, 20, 15};
    int k = 3; // Find the 3rd smallest element
    
    std::cout << "The " << k << "rd smallest element is: " << select(k, S) << std::endl;
    
    return 0;
}
