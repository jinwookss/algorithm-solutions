package 프로그래머스.월간코딩테스트시즌2.Q2

import java.util.*

class Solution {

    private fun findPair(char: Char): Char {
        return when (char) {
            '(' -> ')'
            '[' -> ']'
            '{' -> '}'
            ')' -> '('
            ']' -> '['
            else -> '{'
        }
    }

    fun solution(s: String): Int {
        var failCount = 0
        val stack = Stack<Char>()

        for (offset in s.indices) {

            stack.clear()

            for (i in s.indices) {
                val index = (offset + i + s.length) % s.length
                val curChar = s[index]

                println("offset: $offset, index: $index, char: $curChar")

                if (stack.isEmpty()) {
                    if (curChar == '(' || curChar == '[' || curChar == '{') {
                        stack.push(curChar)
                    } else {
                        println("fail")
                        failCount++
                        stack.clear()
                        break
                    }
                } else {
                    if (curChar == ')' || curChar == ']' || curChar == '}') {
                        if (stack.peek() == findPair(curChar)) {
                            stack.pop()
                        } else {
                            println("fail")
                            failCount++
                            stack.clear()
                            break
                        }
                    } else {
                        if (stack.peek() == '(' || stack.peek() == '[' || stack.peek() == '{') {
                            stack.push(curChar)
                        } else {
                            println("fail")
                            failCount++
                            stack.clear()
                            break
                        }
                    }
                }
            }

            if (stack.isNotEmpty()) failCount++
        }
        return s.length - failCount
    }
}