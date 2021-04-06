package 프로그래머스.디스크컨트롤러

import java.util.*

class Solution {
    companion object {
        val INPUT = arrayOf(
            intArrayOf(1, 2),
            intArrayOf(5, 2),
            intArrayOf(3, 2)
        ) // = 9
    }

    fun solution(jobs: Array<IntArray>): Int {
        var answer = 0

        // 전체 작업
        var jobList = jobs.map { it[0] to it[1] }.sortedBy { it.first }
        println(jobList.size)
        // 현재 시간에서 시작할 수 있는 작업
        val priorityQueue: PriorityQueue<Pair<Int, Int>> = PriorityQueue(compareBy { it.second })
        var time = 0

        while (jobList.isNotEmpty() || priorityQueue.isNotEmpty()) {
            val availableJobs = jobList.takeWhile { it.first <= time }
            priorityQueue.addAll(availableJobs)
            jobList = jobList.drop(availableJobs.size)

            if (priorityQueue.isEmpty()) {
                time = jobList.first().first
            } else {
                val job = priorityQueue.poll()
                time += job.second
                answer += time - job.first
            }
        }

        return answer / jobs.size
    }
}