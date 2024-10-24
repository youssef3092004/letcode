def find_missing_number(numbers: list, n: int) -> int:
    sum = []
    for i in range(min(numbers), max(numbers)):
        if i not in numbers:
            sum.append(i)
    print(*sum)
if __name__ == '__main__':
    find_missing_number([7, 2, 4, 1, 8, 10, 9, 6], 10)
