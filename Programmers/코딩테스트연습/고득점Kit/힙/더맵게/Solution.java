import java.util.PriorityQueue;

public class 더맵게 {
    /**
     * 섞은 음식 = (가장 안매운 음식 + 두 번째로 안매운 음식 * 2)
     * 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반
     */
    public int solution(int[] scoville, int K) {
        int mixCount = 0;

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int i : scoville) {
            minHeap.add(i);
        }

        while (minHeap.size() >= 2 && minHeap.peek() < K) {

            int first = minHeap.poll();
            int second = minHeap.poll();
            int mix = first + (second * 2);
            minHeap.add(mix);
            mixCount++;
        }

        if (minHeap.peek() < K) return -1;
        else return mixCount;
    }
}
