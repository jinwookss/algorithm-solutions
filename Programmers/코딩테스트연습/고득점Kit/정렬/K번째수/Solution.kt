package 프로그래머스.정렬

class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        return commands.map { command ->
            array.slice(command[0] - 1 until command[1]).sorted()[command[2] - 1]
        }.toIntArray()
    }
}