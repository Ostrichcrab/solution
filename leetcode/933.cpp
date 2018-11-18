class RecentCounter {
public:
    vector<int> a;
    int h;
    RecentCounter() {
      a.clear();
      h=0;
    }
    
    int ping(int t) {
      a.push_back(t);
      while ((h<a.size())&&(a[h]+3000<t)) h++;
      return a.size()-h;
    }
};