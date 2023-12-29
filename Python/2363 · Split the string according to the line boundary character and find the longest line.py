def splitlines(src: str) -> str:
    """
    :param src: The source string needs to be processed
    :return: The maximum length of the string
    """
    # -- write your code here --
    strs = src.splitlines()
    return max(strs, key=lambda x: len(x))