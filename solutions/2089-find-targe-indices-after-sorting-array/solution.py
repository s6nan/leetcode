"""
    2089. Find Target Indices After Sorting Array

    Topics: Easy - Array - Binary Search - Sorting - Weekly Contest 269

    Mantık (TR): Diziyi gerçekten sıralamak yerine, diziyi tek seferde gezerek 
                 target'tan küçük olan sayıların adedini (a) ve target'a eşit olanların adedini (c) 
                 sayıyoruz. Dizi sıralansaydı target elemanları tam olarak 'a' indeksinden başlayıp 
                 'a + c - 1' indeksine kadar yan yana dizileceği için bu aralığı doğrudan döndürüyoruz.

    Logic (EN):  Instead of sorting the array, we count how many elements are strictly 
                 less than the target (a) and how many are equal to the target (c) in a single pass. 
                 In a sorted array, the target values would occupy indices from 'a' to 'a + c - 1', 
                 so we directly generate and return this range.

    Time Comp: O(n) | Space Comp: O(1)
"""

class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        # a -> target'tan küçük olan sayıların adedi, c -> kaç adet target olduğu.
        # a -> count of numbers less than target, c -> frequency of target.
        a = 0
        c = 0

        for num in nums:
            if num < target:
                a += 1
            elif num == target:
                c += 1

        # Sıralama yapıldığında target'tan küçük olanların sayısından (a) başlayarak c kadar indis üretme.
        # Starting from index 'a', generate 'c' consecutive indices representing the sorted positions.
        return list(range(a, a + c))