package 프로그래머스.월간코딩테스트시즌2.Q3

import kotlin.math.abs

class Solution {
    private fun dfs(
        a: IntArray,
        list: List<Pair<Int, ArrayList<Int>>>,
        prevNode: Int,
        curNode: Int,
        completed: Array<Boolean>
    ): Long {
        println("prev: $prevNode, cur: $curNode")
        var moveCount = 0L
        for (nextNode in list[curNode].second) {
            if (completed[nextNode] || nextNode == prevNode) continue
            moveCount += dfs(a, list, curNode, nextNode, completed)
        }

        if (a[curNode] != 0) {
            moveCount += abs(a[curNode].toLong())
            a[prevNode] += a[curNode]
            a[curNode] = 0
        }

        completed[curNode] = true
        return moveCount
    }

    fun solution(a: IntArray, edges: Array<IntArray>): Long {
        if (a.sum() != 0) return -1
        if (a.none { it != 0 }) return 0

        val map = HashMap<Int, ArrayList<Int>>()
        edges.forEach {
            if (map[it[0]] == null) map[it[0]] = arrayListOf(it[1])
            else map[it[0]]?.add(it[1])

            if (map[it[1]] == null) map[it[1]] = arrayListOf(it[0])
            else map[it[1]]?.add(it[0])
        }

        val sortedList = map.toList().sortedBy { it.first }
        val completed = Array(a.size) { false }
        sortedList.forEach {
            println(it)
        }

        return dfs(a, sortedList, -1, sortedList.first().first, completed)
    }
}