# There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

# You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

# Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        remain=[0]*len(gas)
        temp=0
        total=0
        maxi=0
        for i in xrange(len(gas)):
            remain[i]=gas[i]-cost[i]
        i=0
        while i<len(gas):
            total+=remain[i]
            temp+=remain[i]
            if temp<0:
                temp=0
                maxi=i+1
            i+=1
        if total<0:
            return -1
        return maxi
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        