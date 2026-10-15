/*
    3723. Maximize Sum of Squares of Digits

    Topics: Math - Greedy - Biweekly Contest 168

    Mantık (TR): En büyük değeri bulurken, her seferinde soldan başlayarak ve basamaklara 
                 en büyük rakamı getirerek sum'ı sıfırlama çabasından ibaret.

    Logic (EN):  Greedily place the largest possible digit (up to 9) from left to right 
                 until the remaining sum is reduced to zero.

    Time Comp: O(n) | Space Comp: O(n)
*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // En büyük rakamlar toplamı sum'dan küçük ise boş döndürüyoruz.
        // If max possible digit sum is less than sum, return empty string.
        if (9 * num < sum) {
            return "";
        }

        string ans = "";
        for (int i = 0; i < num; i++) {
            // sum 9 veya 9'dan büyükse cevaba 9 ekleniyor ve sum'dan 9 çıkarılıyor.
            // If sum >= 9, append '9' and subtract 9 from sum.
            if (sum >= 9) {
                ans += '9';
                sum -= 9;
            } else {
                // sum 9'dan küçüktür; kalan sayıyı char olarak ekleyip sum'ı sıfırlıyoruz (kalan basamaklar '0' olur).
                // Otherwise, append the remaining sum as a char and set sum to 0 (subsequent digits become '0').
                ans += '0' + sum;
                sum = 0;
            }
        }
        return ans;
    }
};