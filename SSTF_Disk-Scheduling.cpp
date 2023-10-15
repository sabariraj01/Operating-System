#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int sstfDiskScheduling(int currentPosition, const std::vector<int>& requests) {
    int totalHeadMovement = 0;
    std::vector<int> sortedRequests = requests;
    
    std::sort(sortedRequests.begin(), sortedRequests.end(), [currentPosition](int a, int b) {
        return std::abs(a - currentPosition) < std::abs(b - currentPosition);
    });
    
    for (int i = 0; i < sortedRequests.size(); i++) {
        totalHeadMovement += std::abs(currentPosition - sortedRequests[i]);
        currentPosition = sortedRequests[i];
    }
    
    return totalHeadMovement;
}

int main() {
    int currentPosition, numRequests;
    std::vector<int> requests;
    
    std::cin >> currentPosition;
    std::cin >> numRequests;
    
    for (int i = 0; i < numRequests; i++) {
        int request;
        std::cin >> request;
        requests.push_back(request);
    }
    
    int totalHeadMovement = sstfDiskScheduling(currentPosition, requests);
    
    std::cout << totalHeadMovement << std::endl;
    
    return 0;
}
