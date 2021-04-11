package 프로그래머스.정렬.HIndex

import java.lang.Integer.min

class Solution {
    fun solution(citations: IntArray): Int {
        return citations.sorted()
            .mapIndexed { idx, citation ->
                val over = citations.size - idx
                val under = citations.size - over
                println(Triple(citation, under, over))
                Triple(citation, under, over)
            }
            .firstOrNull {
                it.first >= it.second && it.first >= it.third
            }?.third ?: 0
    }

    /**
     * 4 3 2 1 0 - h 이하인 논문 수
     * 1 2 3 4 5 - h 이상인 논문 수
     * 6 5 4 1 0 - h
     */
    fun solution2(citations: IntArray): Int {
        return citations.sortedDescending()
            .mapIndexed { idx, citation ->
                min(idx + 1, citation)
            }.maxOrNull() ?: 0
    }
}