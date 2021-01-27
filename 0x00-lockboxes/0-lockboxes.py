#!/usr/bin/python3
if __name__ == "__main__":
    pass


def canUnlockAll(boxes):
    size = len(boxes)
    if boxes is None or type(boxes) != list or size == 0:
        return False

    openBxs = [False] * size
    openBxs[0] = True
    keys = boxes[0]
    for k in keys:
        if type(k) == int and (k > 0 and k < size) and \
                openBxs[k] is False and type(boxes[k]) == list:
            openBxs[k] = True
            content = boxes[k]
            for c in content:
                if type(c) == int:
                    keys.append(c)

    return False not in openBxs
