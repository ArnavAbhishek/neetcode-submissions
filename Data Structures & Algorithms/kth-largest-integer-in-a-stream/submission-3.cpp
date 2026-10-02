class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> _cont;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(int i=0; i<nums.size(); i++){
            _cont.push(nums[i]);
        }
    }
    
    int add(int val) {
        _cont.push(val);
        if(_cont.size() == _k+1) _cont.pop();
        else{
            while(_cont.size() > 0 && _cont.size() != _k){
                _cont.pop();
            }
        }
        return _cont.top();
    }
};
