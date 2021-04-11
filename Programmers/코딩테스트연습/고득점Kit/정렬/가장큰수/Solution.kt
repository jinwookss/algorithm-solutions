package 프로그래머스.정렬.가장큰수

class Solution {
    fun solution(numbers: IntArray): String {
        return numbers
            .map { it.toString() }
            .sortedWith(Comparator<String> { s1: String, s2: String ->
                (s2 + s1).compareTo(s1 + s2)
            })
            .joinToString("")
            .toBigInteger()
            .toString()
    }
}