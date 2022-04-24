class UndergroundSystem {
public:
    map<int, pair<string, int>> pass;  // id, stationName
    map<pair<string, string>, pair<int, double>> st; // <start_station, end_start> <time, no_of_passenger>
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pass[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto q = pass[id];
        st[{q.first, stationName}].first += (t-q.second);
        st[{q.first, stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair s = st[{startStation, endStation}];
        double w = s.first/s.second;
        return w;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */