class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> _cont;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(auto it: nums){
            _cont.push(it);
        }
    }
    
    int add(int val) {
        _cont.push(val);
        while(_cont.size() > 0 && _cont.size() != _k){
            _cont.pop();
        }
        return _cont.top();
    }
};
