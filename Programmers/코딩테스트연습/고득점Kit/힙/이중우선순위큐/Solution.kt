package 프로그래머스.이중우선순위큐

import java.util.*

class Solution {
    fun solution(operations: Array<String>): IntArray {
        val maxQueue = PriorityQueue<Int>(Collections.reverseOrder())
        val minQueue = PriorityQueue<Int>()

        operations.forEach { operation ->
            val s = operation.split(" ")
            val cmd = s[0]
            val value = s[1].toInt()

            when (cmd) {
                "I" -> {
                    maxQueue.add(value)
                    minQueue.add(value)
                }
                "D" -> {
                    if (maxQueue.isNotEmpty() && minQueue.isNotEmpty()) {
                        if (value == 1) {
                            val removed = maxQueue.poll()
                            minQueue.remove(removed)
                        } else {
                            val removed = minQueue.poll()
                            maxQueue.remove(removed)
                        }
                    }
                }
            }
        }

        return if (maxQueue.isEmpty()) {
            intArrayOf(0, 0)
        } else {
            intArrayOf(maxQueue.peek(), minQueue.peek())
        }
    }
}