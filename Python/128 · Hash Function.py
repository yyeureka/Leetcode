class Solution:
    """
    @param key: A string you should hash
    @param h_a_s_h__s_i_z_e: An integer
    @return: An integer
    """
    def hash_code(self, key: str, h_a_s_h__s_i_z_e: int) -> int:
        # write your code here
        res = 0
        for c in key:
            res = (res * 33 + ord(c)) % h_a_s_h__s_i_z_e

        return res