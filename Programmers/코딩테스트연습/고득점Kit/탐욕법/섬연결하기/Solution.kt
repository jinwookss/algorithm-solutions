package 프로그래머스.탐욕법.섬연결하기

class Solution {

    fun solution(n: Int, costs: Array<IntArray>): Int {
        var totalCost = 0

        val sortedCosts = costs.sortedBy { it[2] }
        val visited = mutableSetOf<Int>()
        visited.add(sortedCosts.first()[0])

        while (visited.count() < n) {
            for ((s: Int, e: Int, c: Int) in sortedCosts) {
                if (visited.contains(s) && !visited.contains(e)) {
                    totalCost += c
                    visited.add(e)
                    break
                } else if (visited.contains(e) && !visited.contains(s)) {
                    totalCost += c
                    visited.add(s)
                    break
                }
            }
        }

        return totalCost
    }
}