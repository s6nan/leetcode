/*
    168. Excel Sheet Column Title

    Topics: Easy - Math - String

    Mantık (TR): Excel sütunları 1-tabanlıdır (A=1, ..., Z=26) ve '0' rakamı yoktur (bijective base-26).
                 Bu yüzden her adımda önce sayıyı 1 eksiltip 0-25 aralığına çekiyoruz.
                 Ardından 26'ya göre modunu alıp 'A' ile toplayarak harfi buluyor ve sonucun başına
                 ekliyoruz (basamakları sağdan sola ürettiğimiz için). Son olarak sayıyı 26'ya bölüp
                 bir sonraki basamağa geçiyoruz.

    Logic (EN):  Excel columns are 1-indexed with no '0' digit (bijective base-26). In each iteration,
                 we decrement the number by 1 to map it into the 0-25 range, take it modulo 26,
                 convert the remainder to a character ('A' + rem), and prepend it to the result
                 (since digits are produced right-to-left). Then we divide by 26 and repeat until 0.

    Time Comp: O(log26(n)) | Space Comp: O(1) / O(log26(n))
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber != 0) {
            // 1-tabanlı sistemi 0-tabanlı sisteme (0-25 aralığına) çekiyoruz.
            // Convert from 1-based indexing to 0-based indexing (0-25 range).
            columnNumber--;

            // En sağdaki basamağın harf karşılığını bulup string'in başına ekliyoruz.
            // Find the rightmost character and prepend it to the result string.
            ans = (char)('A' + (columnNumber % 26)) + ans;

            // Bir sonraki basamağa geçmek için sayıyı 26'ya bölüyoruz.
            // Divide by 26 to move to the next digit.
            columnNumber /= 26;
        }
        return ans;
    }
};