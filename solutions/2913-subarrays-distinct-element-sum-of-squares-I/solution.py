"""
    2913. Subarrays Distinct Element Sum of Squares I

    Topics: Array - Hash Table - Binary Indexed Tree - Segment Tree - Biweekly Contest 116

    Mantık (TR): İç içe iki döngüyle tüm alt dizileri (subarray) gezerken, her alt dizideki 
                 farklı (eşsiz) elemanları bir set (küme) içinde tutup eleman sayısının 
                 karelerini toplamak.
    Logic (EN):  Iterate through all subarrays using nested loops, tracking distinct elements 
                 with a hash set and summing the squares of their counts.

    Time Comp: O(n^2) | Space Comp: O(n)
"""

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        sum = 0
        for i in range(len(nums)):
            # Sadece görülenleri kaydedeceğimiz set (her elemandan sadece 1 adet bulunabilir).
            # A set to store seen elements (only keeps unique values).
            seen = set()

            for j in range(i, len(nums)):
                # Her elemanı set'e ekliyoruz; yoksa ekliyor, varsa ekleme yapmıyor.
                # Add each element to the set; duplicates are automatically ignored.
                seen.add(nums[j])

                # Set'in boyutu eşsiz eleman sayısını veriyor.
                # The size of the set gives the distinct element count.
                c = len(seen)
                sum += c * c

        return sum