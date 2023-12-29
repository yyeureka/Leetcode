class Solution:
    """
    @param graph: a list of Undirected graph node
    @param A: nodeA
    @param B: nodeB
    @return:  the length of the shortest path
    """

    def shortestPath(self, graph, A, B):
        # Write your code here
        if A.label == B.label:
            return 0

        dq_f = deque([A])
        visited_f = {A}
        dq_b = deque([B])
        visited_b = {B}

        res = 0

        while dq_f or dq_b:
            if self.extend_queue(dq_f, visited_f, visited_b):
                return res
            res += 1

            if self.extend_queue(dq_b, visited_b, visited_f):
                return res
            res += 1

        return -1

    def extend_queue(self, dq, visited, target):
        size = len(dq)

        for i in range(size):
            node = dq.popleft()
            if node in target:
                return True

            for next in node.neighbors:
                if next in visited:
                    continue

                visited.add(next)
                dq.append(next)

        return False