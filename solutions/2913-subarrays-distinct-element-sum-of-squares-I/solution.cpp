/*
    2913. Subarrays Distinct Element Sum of Squares I

    Topics: Array - Hash Table - Binary Indexed Tree - Segment Tree - Biweekly Contest 116

    Mantık (TR): İç içe iki döngüyle tüm alt dizileri gezerken, her alt dizideki eşsiz eleman
                 sayısını sabit boyutlu bir boolean dizisiyle takip edip karelerini toplamak.
                 g
    Logic (EN):  Iterate through all subarrays using nested loops, tracking distinct elements 
                 with a fixed-size boolean array and summing the squares of their counts.

    Time Comp: O(n^2) | Space Comp: O(1)
*/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Set de kullanılabilirdi ama daha az kaynak tüketimi için bool dizi kullandık. Sayı daha önce görüldü mü onu tutuyoruz.
            // A fixed boolean array is used instead of a hash set for better memory and speed performance.
            bool seen[101] = {false}; 
            int c = 0; // Farklı sayı sayacı / Distinct element counter

            for (int j = i; j < nums.size(); j++) {
                // Daha önce o sayı görülmediyse görüldü olarak işaretliyor ve sayacımızı bir artırıyoruz.
                // If the number hasn't been seen in the current subarray, mark it and increment the counter.
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    c += 1;
                }
                sum += c * c;
            }
        }
        return sum;
    }
};