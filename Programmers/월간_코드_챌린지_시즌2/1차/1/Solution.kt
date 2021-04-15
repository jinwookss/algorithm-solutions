package 프로그래머스.월간코딩테스트시즌2.Q1

class Solution {
    fun solution(absolutes: IntArray, signs: BooleanArray): Int {
        return absolutes.mapIndexed { index, i ->
            val sign = if (signs[index]) 1 else -1
            i * sign
        }.sum()
    }
}