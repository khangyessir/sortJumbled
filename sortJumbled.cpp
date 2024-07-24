class Solution {
private:
    int getMappedValue(int num, const vector<int>& mapping) {
        string number = to_string(num);
        string number = to_string(num);
        string mpStr = "";
        for(char c : number) {
            mpStr += to_string(mapping[c - '0']);
        }
        return stoi(mpStr);
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mpNums;
        for(int num : nums) {
            int mappedValue = getMappedValue(num, mapping);
            mpNums.push_back({mappedValue, num});
        }
        stable_sort(mpNums.begin(), mpNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        vector<int> sortNums;
        for(const auto& p : mpNums) {
            sortNums.push_back(p.second);
        }
        return sortNums;
    }
};