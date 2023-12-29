"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""


class Solution:
    """
    @param imput:
    @param id:
    @return: the total importance value
    """

    def getImportance(self, employees, id):
        # Write your code here.
        dict = {}
        for i in employees:
            dict[i.id] = [i.importance, i.subordinates]

        return self.helper(id, dict)

    def helper(self, id, dict):
        if id not in dict:
            return 0

        count, sub = dict[id]
        for i in sub:
            count += self.helper(i, dict)

        return count
