# bull: same numbers on the same position
# use hash to count the same numbers: bull + cow

class Solution:
    """
    @param secret: An string
    @param guess: An string
    @return: An string
    """

    def get_hint(self, secret: str, guess: str) -> str:
        # write your code here
        if len(secret) != len(guess):
            return '0A0B'

        bull = 0
        cow = 0
        char = {}

        for i in range(len(secret)):
            if secret[i] in char:
                char[secret[i]] += 1
            else:
                char[secret[i]] = 1

            if secret[i] == guess[i]:
                bull += 1

        for i in range(len(guess)):
            if guess[i] not in char or 0 == char[guess[i]]:
                continue

            cow += 1
            char[guess[i]] -= 1

        cow -= bull

        return str(bull) + 'A' + str(cow) + 'B'