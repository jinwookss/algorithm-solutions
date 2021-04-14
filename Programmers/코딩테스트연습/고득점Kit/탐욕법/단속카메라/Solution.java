package 프로그래머스.탐욕법.단속카메라;

import java.util.Arrays;
import java.util.Comparator;

public class Solution {

    public int solution(int[][] routes) {
        int answer = 0;

        Arrays.sort(routes, Comparator.comparingInt(route -> route[1]));

        int out = Integer.MIN_VALUE;
        for (int[] route : routes) {
            if (out < route[0]) {
                answer++;
                out = route[1];
            }
        }

        return answer;
    }
}
