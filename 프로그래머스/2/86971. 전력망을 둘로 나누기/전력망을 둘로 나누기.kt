class Solution {
    var answer = Int.MAX_VALUE

    fun solution(n: Int, wires: Array<IntArray>): Int {
        val graph = Array(n + 1) { mutableListOf<Int>() }
        
        // 그래프 생성
        for (wire in wires) {
            val v1 = wire[0]
            val v2 = wire[1]
            graph[v1].add(v2)
            graph[v2].add(v1)
        }
        
        // 각 경우마다 전력망 분할
        for (i in 0 until n-1) {
            val v1 = wires[i][0]
            val v2 = wires[i][1]
            
            // 전력망 분할
            disconnect(graph, v1, v2)
            
            // 송전탑 개수 차이 계산
            val count1 = getCount(graph, v1, 0, BooleanArray(n + 1))
            val count2 = n - count1
            
            // 송전탑 개수 차이의 절대값 갱신
            answer = minOf(answer, Math.abs(count1 - count2))
            
            // 분할된 전력망 복구
            connect(graph, v1, v2)
        }
        
        return answer
    }
    
    // 전력망 분할
    fun disconnect(graph: Array<MutableList<Int>>, v1: Int, v2: Int) {
        graph[v1].remove(v2)
        graph[v2].remove(v1)
    }
    
    // 송전탑 개수 계산
    fun getCount(graph: Array<MutableList<Int>>, node: Int, count: Int, visited: BooleanArray): Int {
        visited[node] = true
        var result = count + 1
        
        for (next in graph[node]) {
            if (!visited[next]) {
                result = getCount(graph, next, result, visited)
            }
        }
        
        return result
    }
    
    // 분할된 전력망 복구
    fun connect(graph: Array<MutableList<Int>>, v1: Int, v2: Int) {
        graph[v1].add(v2)
        graph[v2].add(v1)
    }
}
