from pprint import pprint

def backtrack(now_station: str, result: list, elements: str, n: int):
    if n == len(now_station):
        result.append(now_station)
        return result
    for elem in elements:

        now_station += elem

        result = backtrack(now_station, result, elements, n)

        now_station = now_station[:-1]

    return result

if __name__ == '__main__':
    res = []
    res = backtrack('', res, 'ab', 3)
    pprint(res)
