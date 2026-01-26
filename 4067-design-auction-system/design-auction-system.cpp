class AuctionSystem {
private:
    unordered_map<int, set<pair<int, int>>> itemBids;
    map<pair<int, int>, pair<int, int>> userBids;
    
public:
    AuctionSystem() {
        
    }
    void addBid(int userId, int itemId, int bidAmount) {
        auto key = make_pair(userId, itemId);
        
        // If user already has a bid on this item, remove it first
        if (userBids.find(key) != userBids.end()) {
            itemBids[itemId].erase(userBids[key]);
        }
        
        // Add new bid
        auto bidPair = make_pair(bidAmount, userId);
        itemBids[itemId].insert(bidPair);
        userBids[key] = bidPair;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        auto key = make_pair(userId, itemId);
        itemBids[itemId].erase(userBids[key]);
        auto bidPair = make_pair(newAmount, userId);
        itemBids[itemId].insert(bidPair);
        userBids[key] = bidPair;
    }
    
    void removeBid(int userId, int itemId) {
        auto key = make_pair(userId, itemId);
        
        // Remove from itemBids
        itemBids[itemId].erase(userBids[key]);
        if (itemBids[itemId].empty()) {
            itemBids.erase(itemId);
        }
        
        // Remove from userBids
        userBids.erase(key);
    }
    
    int getHighestBidder(int itemId) {
        if (itemBids.find(itemId) == itemBids.end() || itemBids[itemId].empty()) {
            return -1;
        }
        
        // Get the last element (highest bid, highest userId)
        auto it = itemBids[itemId].rbegin();
        return it->second; // return userId
    }
};
