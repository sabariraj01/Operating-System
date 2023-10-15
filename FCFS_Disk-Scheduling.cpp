#include <iostream>
#include <vector>
#include <cmath>

int fcfsDiskScheduling(int currentPosition, const std::vector<int>& requests) {
    int totalHeadMovement = 0;
    
    for (int i = 0; i < requests.size(); i++) {
        totalHeadMovement += std::abs(currentPosition - requests[i]);
        currentPosition = requests[i];
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
    
    int totalHeadMovement = fcfsDiskScheduling(currentPosition, requests);
    
    std::cout << totalHeadMovement << std::endl;
    
    return 0;
}
