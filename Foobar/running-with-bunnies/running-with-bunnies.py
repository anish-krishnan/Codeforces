#
# Please see unmemoized_algo for a clean readible 
# algorithm (Dynamic Programming Recurrence) that
# solves this problem. 
import copy

# Bellman Ford's algorithm allows us to find
# negative edge weight cycles. This is because
# our main algorithm's correctness depends on the 
# ABSENSE of a negative edge weight cycle
def BF(graph, s):
    n = len(graph)
    DP = [999999999999]*n
    DP[s] = 0
    for i in range(1, n-1):
        for u in range(n):
            for v in range(n):
                DP[v] = min(DP[v], DP[u] + graph[u][v])
    
    for u in range(n):
        for v in range(n):
            if (DP[v] > DP[u] + graph[u][v]):
                return True
    return False

# Bit String class
# This class encodes a set into a 32-bit integer
# Also allows for constant size access
class BitString(object):
    def __init__(self, bits=0, size=0):    
        self.bits = bits
        self.size = size
        
    def __hash__(self):
        return self.bits

    def set_bit(self, i):
        test = self.get_bit(i)
        if(not test):
            self.bits |= 1 << i
            self.size += 1

    def get_bit(self, i):
        return (self.bits >> i) & 1

    def clear_bit(self, i):
        test = self.get_bit(i)
        if(test):
            self.size -= 1
            self.bits &= ~(1<<i) # clear bit 19

    def get_result(self):
        res = []
        count = -1
        while (self.bits):
            if (self.bits & 1):
                res.append(count)
            count += 1
            self.bits >>= 1
        return res
    
    def __str__(self):
        return str(self.bits)
    
        
    

def solution(graph, time):
    start = 0
    end = len(graph)-1
    
    contains_neg_edge_weight_cycle = BF(graph, 0)
    num_bunnies = len(graph) - 2
    if(contains_neg_edge_weight_cycle):
        return [i for i in range(num_bunnies)]
    
    memo = {}
    
    # Dynamic Programming recurrence
    # to maximize number of bunnies
    # Allows for revisits.
    def DP(v, visited, i, t):
        if(i == 0 and v == end and t >= 0):
            return visited
        if(i == 0 and v == end and t < 0):
            return BitString()
        if(i == 0 and v != end):
            return BitString()

    
        if((v, visited.bits, i, t) in memo):
            return memo[(v, visited.bits, i, t)]
        
        new_visited = BitString(visited.bits, visited.size)
        new_visited.set_bit(v)
        opt = BitString()

        for neighbor in range(len(graph)):
            if(neighbor != v):
                newTime = t - graph[v][neighbor]
                res = DP(neighbor, new_visited, i-1, newTime) 
                opt = res if res.size > opt.size else opt 

        stay = DP(v, new_visited, i-1, t)
        res = stay if stay.size > opt.size else opt
        
        memo[(v, visited.bits, i, t)] = res
        
        return res

    result = DP(0, BitString(), len(graph)*2, time)
    
    result.clear_bit(start)
    result.clear_bit(end)
    resultList = result.get_result()

    return resultList


# Clean/Readible Dynamic Programming Recurrence
def unmemoized_DP(v, L, i, t):
    if(i == 0 and v == end and t >= 0):
        return L
    if(i == 0 and v == end and t < 0):
        return set()
    if(i == 0 and v != end):
        return set()

    L = copy.copy(L)
    L.add(v)
    opt = set() # optimal solution

    for neighbor in range(len(graph)):
        if(neighbor != v):
            newTime = t - graph[v][neighbor]
            res = unmemoized_DP(neighbor, L, i-1, newTime)  
            opt = res if len(res) > len(opt) else opt 

    stay = unmemoized_DP(v, L, i-1, t)

    return stay if len(stay) > len(opt) else opt

# Testing Framework
if __name__ == '__main__':
    case1 = [[0, 1, 1, 1, 1],
             [1, 0, 1, 1, 1],
             [1, 1, 0, 1, 1],
             [1, 1, 1, 0, 1],
             [1, 1, 1, 1, 0]]
    print("\n\nCase 1: Provided test case 1.\nTime limit: 3")
    for row in case1:
        print('', row)
    print("\n  Expected: [0, 1]\nCalculated:", str(solution(case1, 3)))

    print("\n\nCase 2: Provided test case 2.\nTime limit: 1")
    case2 = [[0, 2, 2, 2, -1],
             [9, 0, 2, 2, -1],
             [9, 3, 0, 2, -1],
             [9, 3, 2, 0, -1],
             [9, 3, 2, 2, 0]]
    for row in case2:
        print('', row)
    print("\n  Expected: [1, 2]\nCalculated:", str(solution(case2, 1)))

    print("\n\nCase 3: Infinite negative cycle.\nTime limit: -500")
    case3 = [[0, 2, 2, 2, -1],
             [9, 0, 2, 2, 0],
             [9, 3, 0, 2, 0],
             [9, 3, 2, 0, 0],
             [-1, 3, 2, 2, 0]]
    for row in case3:
        print('', row)
    print("\n  Expected: [0, 1, 2]\nCalculated:", str(solution(case3, -500)))

    print("\n\nCase 4: Max bunnies. None rescuable.\nTime limit: 1")
    case4 = [[1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 1, 1, 1, 1]]
    for row in case4:
        print('', row)
    print("\n  Expected: []\nCalculated:", str(solution(case4, 1)))

    print("\n\nCase 5: One bunny.\nTime limit: 2")
    case5 = [[1, 1, 1],
             [1, 1, 1],
             [1, 1, 1]]
    for row in case5:
        print('', row)
    print("\n  Expected: [0]\nCalculated:", str(solution(case5, 2)))

    print("\n\nCase 6: Multiple revisits.\nTime limit: 10")
    case6 = [[0, 5, 11, 11, 1],
             [10, 0, 1, 5, 1],
             [10, 1, 0, 4, 0],
             [10, 1, 5, 0, 1],
             [10, 10, 10, 10, 0]]
    for row in case6:
        print('', row)
    print("\n  Expected: [0, 1]\nCalculated:", str(solution(case6, 10)))

    print("\n\nCase 7: Multiple Revisits 2.\nTime limit: 5")
    case7 = [[0, 10, 10, 10, 1],
             [0, 0, 10, 10, 10],
             [0, 10, 0, 10, 10],
             [0, 10, 10, 0, 10],
             [1, 1, 1, 1, 0]]
    for row in case7:
        print('', row)
    print("\n  Expected: [0, 1]\nCalculated:", str(solution(case7, 5)))

    print("\n\nCase 8: Time travel.\nTime limit: 1")
    case8 = [[0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0]]
    for row in case8:
        print('', row)
    print("\n  Expected: [0, 1, 2]\nCalculated:", str(solution(case8, 1)))

    print("\n\nCase 9: No bunnies.\nTime limit: 1")
    case9 = [[2, 2],
             [2, 2]]
    for row in case9:
        print('', row)
    print("\n  Expected: []\nCalculated:", str(solution(case9, 1)))

    print("\n\nCase 10: Backwards bunny path.\nTime limit: 6")
    case10 = [[0, 10, 10, 1, 10],
              [10, 0, 10, 10, 1],
              [10, 1, 0, 10, 10],
              [10, 10, 1, 0, 10],
              [1, 10, 10, 10, 0]]
    for row in case10:
        print('', row)
    print("\n  Expected: [0, 1, 2]\nCalculated:", str(solution(case10, 6)))




